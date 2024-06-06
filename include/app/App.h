#pragma once

#ifdef _MSC_VER
#    ifdef TOP_APP_EXPORTS
#        define TOP_APP_API __declspec(dllexport)
#    else
#        define TOP_APP_API __declspec(dllimport)
#    endif

#    ifdef TOP_APP_STATIC
#        undef TOP_APP_API
#        define TOP_APP_API
#    endif
#else
#    define TOP_APP_API
#endif

namespace lm {
namespace app {
/// @brief 单例可执行程序
/// @return 0: 单例
///         1: 已存在正在运行的程序
///      -100: 创建锁失败
///      -200: 打开文件失败
///      -201: 截断文件失败
///      -202: 写文件失败
TOP_APP_API int SingleApp();

/// @brief 改变工作路径为可执行文件所在路径
/// @return true: 成功
///        false: 失败
TOP_APP_API bool ChangeWorkPath();

/// @brief 设置控制台字符集为 UTF8
TOP_APP_API void SetConsoleCharsetUTF8();

/// @brief 程序崩溃时生成DUMP文件
TOP_APP_API void AutoDump();
}   // namespace app
};   // namespace lm
