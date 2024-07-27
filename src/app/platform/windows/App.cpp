#include "App.h"

#include <locale>
#include <io.h>
#include <direct.h>
#include <tchar.h>

#include <Windows.h>
#include <Shlwapi.h>
#include <signal.h>
#include <DbgHelp.h>

#include "top/config/config.h"
#include "top/config/version.h"

#pragma comment(lib, "ShLwApi.Lib")

namespace lm {
namespace app {
 int SingleApp()
{
    auto hMutex = ::CreateMutex(NULL, FALSE, _T(TOP_NAME));
    return hMutex ? ((ERROR_ALREADY_EXISTS == ::GetLastError()) ? 1 : 0) : -100;
}

 bool ChangeWorkPath()
{
    TCHAR path[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, path, MAX_PATH);
    auto pChr = _tcsrchr(path, _T('\\'));
    if (pChr == NULL) {
        return false;
    }
    *pChr = _T('\0');
    return SetCurrentDirectory(path) == TRUE;
}

 void SetConsoleCharsetUTF8()
{
    // 在win server 2012 r2操作系统测试崩溃
    // std::locale::global(std::locale(".UTF-8"));

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}

#pragma region 程序崩溃时生成DUMP文件
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
    pfnMiniDumpWriteDump(
        GetCurrentProcess(),
        GetCurrentProcessId(),
        hDumpFile,
        (MINIDUMP_TYPE)(MiniDumpNormal | MiniDumpWithDataSegs | MiniDumpWithFullMemory),
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
#pragma endregion
 void AutoDump()
{
    SetUnhandledExceptionFilter(ExceptionFilter);
}
}   // namespace app
}   // namespace lm
