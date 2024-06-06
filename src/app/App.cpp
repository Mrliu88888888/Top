#include "App.h"
#include "top/config/config.h"
#include "top/config/version.h"
#include <locale>
#ifdef _WIN32
#    include <io.h>
#    include <direct.h>
#    include <tchar.h>
#    include <Windows.h>
#    include <Shlwapi.h>
#    include <signal.h>
#    include <DbgHelp.h>
#    pragma comment(lib, "ShLwApi.Lib")
#elif __linux__
#    include <stdio.h>
#    include <fcntl.h>
#    include <unistd.h>
#    include <string.h>
#    include <signal.h>
#endif

namespace lm {
#ifdef _WIN32
TOP_APP_API int SingleApp()
{
    auto hMutex = ::CreateMutex(NULL, FALSE, _T(TOP_NAME));
    return hMutex ? ((ERROR_ALREADY_EXISTS == ::GetLastError()) ? 1 : 0) : -100;
}

TOP_APP_API bool ChangeWorkPath()
{
    TCHAR path[MAX_PATH] = {0};
    GetModuleFileName(NULL, path, MAX_PATH);
    return (PathRemoveFileSpec(path) == TRUE) ? (_tchdir(path) == 0) : false;
}

TOP_APP_API void SetConsoleCharsetUTF8()
{
    // 在win server 2012 r2操作系统测试崩溃
    // std::locale::global(std::locale(".UTF-8"));

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}

#    pragma region 程序崩溃时生成DUMP文件
typedef BOOL(WINAPI* MiniDumpWriteDumpT)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE,
                                         PMINIDUMP_EXCEPTION_INFORMATION,
                                         PMINIDUMP_USER_STREAM_INFORMATION,
                                         PMINIDUMP_CALLBACK_INFORMATION);
int GenerateMiniDump(PEXCEPTION_POINTERS pExceptionPointers)
{
    HMODULE hDbgHelp = LoadLibrary(_T("DbgHelp.dll"));
    if (NULL == hDbgHelp) {
        return EXCEPTION_EXECUTE_HANDLER;
    }

    MiniDumpWriteDumpT pfnMiniDumpWriteDump =
        (MiniDumpWriteDumpT)GetProcAddress(hDbgHelp, "MiniDumpWriteDump");
    if (NULL == pfnMiniDumpWriteDump) {
        FreeLibrary(hDbgHelp);
        return EXCEPTION_EXECUTE_HANDLER;
    }

    TCHAR      szFilePath[MAX_PATH] = _T("CrashDumps");
    TCHAR      szFileName[MAX_PATH] = {0};
    SYSTEMTIME stLocalTime          = {0};
    GetLocalTime(&stLocalTime);
    wsprintf(szFileName,
             _T("%s\\%s-%s-%04d%02d%02d-%02d%02d%02d.dmp"),
             szFilePath,
             _T(TOP_NAME),
             _T(TOP_VERSION),
             stLocalTime.wYear,
             stLocalTime.wMonth,
             stLocalTime.wDay,
             stLocalTime.wHour,
             stLocalTime.wMinute,
             stLocalTime.wSecond);

    if (_taccess(szFilePath, 0) != 0) {
        if (_tmkdir(szFilePath) != 0) {
            return EXCEPTION_EXECUTE_HANDLER;
        }
    }
    HANDLE hDumpFile = CreateFile(szFileName,
                                  GENERIC_READ | GENERIC_WRITE,
                                  FILE_SHARE_WRITE | FILE_SHARE_READ,
                                  0,
                                  CREATE_ALWAYS,
                                  0,
                                  0);
    if (INVALID_HANDLE_VALUE == hDumpFile) {
        FreeLibrary(hDbgHelp);
        return EXCEPTION_EXECUTE_HANDLER;
    }

    MINIDUMP_EXCEPTION_INFORMATION expParam = {0};
    expParam.ThreadId                       = GetCurrentThreadId();
    expParam.ExceptionPointers              = pExceptionPointers;
    expParam.ClientPointers                 = FALSE;
    pfnMiniDumpWriteDump(GetCurrentProcess(),
                         GetCurrentProcessId(),
                         hDumpFile,
                         MiniDumpWithDataSegs,
                         (pExceptionPointers ? &expParam : NULL),
                         NULL,
                         NULL);

    CloseHandle(hDumpFile);
    FreeLibrary(hDbgHelp);
    return EXCEPTION_EXECUTE_HANDLER;
}
LONG WINAPI ExceptionFilter(LPEXCEPTION_POINTERS lpExceptionInfo)
{
    if (IsDebuggerPresent()) {
        return EXCEPTION_CONTINUE_SEARCH;
    }
    return GenerateMiniDump(lpExceptionInfo);
}
#    pragma endregion
TOP_APP_API void AutoDump()
{
    SetUnhandledExceptionFilter(ExceptionFilter);
}
#elif __linux__
int SingleApp()
{
    int fd = -1;
    {
        char filename[128] = {0};
        sprintf(filename, "/tmp/%s.pid", APP_NAME);
        fd = open(filename, O_RDWR | O_CREAT, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
        if (fd < 0) {
            return -200;
        }
    }

    {
        struct flock fl = {0};
        fl.l_type       = F_WRLCK;
        fl.l_start      = 0;
        fl.l_whence     = SEEK_SET;
        fl.l_len        = 0;

        if (fcntl(fd, F_SETLK, &fl) == -1) {
            close(fd);
            return 1;
        }
        else {
            char buf[16] = {0};
            if (ftruncate(fd, 0) == -1) {
                return -201;
            }
            sprintf(buf, "%ld", (long)getpid());
            if (write(fd, buf, strlen(buf)) == -1) {
                return -202;
            }
            return 0;
        }
    }
}

bool ChangeWorkPath()
{
    char       path[1024] = {0};
    const auto len        = readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len == -1) {
        return false;
    }
    path[len] = '\0';
    auto ch   = strrchr(path, '/');
    if (ch == NULL) {
        return false;
    }
    *ch = '\0';
    return chdir(path) == 0;
}
#endif
}   // namespace lm