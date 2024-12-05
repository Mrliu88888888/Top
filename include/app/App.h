#pragma once

#include "Top/global.h"

namespace lm {
namespace app {
/// @brief 单例可执行程序
/// @return 0: 单例
///         1: 已存在正在运行的程序
///      -100: 创建锁失败
///      -200: 打开文件失败
///      -201: 截断文件失败
///      -202: 写文件失败
TOP_API int SingleApp();

/// @brief 改变工作路径为可执行文件所在路径
/// @return true: 成功
///        false: 失败
TOP_API bool ChangeWorkPath();

/// @brief 设置控制台字符集为 UTF8
TOP_API void SetConsoleCharsetUTF8();

/// @brief 程序崩溃时生成DUMP文件
TOP_API void AutoDump();
}   // namespace app
};   // namespace lm
