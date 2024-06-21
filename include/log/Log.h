#pragma once

#include <fmt/format.h>
#include "top/config/global_export.h"

namespace lm {
namespace log {
constexpr int LOG_LEVEL_TRACE    = 0;
constexpr int LOG_LEVEL_DEBUG    = 1;
constexpr int LOG_LEVEL_INFO     = 2;
constexpr int LOG_LEVEL_WARN     = 3;
constexpr int LOG_LEVEL_ERROR    = 4;
constexpr int LOG_LEVEL_CRITICAL = 5;

/// @brief 初始化日志
/// @param logname 日志文件名
/// @param level 日志等级
/// @param maxfilesize 0: 输出到控制台
///                    >0: 输出到文件 字节 (KB)
///                                   1024 * 1024 = 1MB
///                                   1024 * 1024 * 1024 = 1GB
/// @param maxfiles 最大日志文件数
/// @return 空
TOP_API void Init(const std::string& logname, const int& level, const uint32_t& maxfilesize,
                  const uint32_t& maxfiles);

/// @brief 输出日志
/// @param level 日志等级
/// @param msg 输出消息
/// @param filename 源码文件名
/// @param linenum 源码行号
/// @param funcname 函数名
/// @return 空
TOP_API void Log(const int& level, const std::string& msg, const char* filename, const int& linenum,
                 const char* funcname);
}   // namespace log
}   // namespace lm

#define STRING_FORMAT(MSG, ...) ::fmt::format(MSG, ##__VA_ARGS__)

#define LOG(LEVEL, MSG) \
    ::lm::log::Log(LEVEL, MSG, __FILE__, __LINE__, static_cast<const char*>(__FUNCTION__))

#define LOG_TRACE(MSG, ...) LOG(::lm::log::LOG_LEVEL_TRACE, STRING_FORMAT(MSG, ##__VA_ARGS__))
#define LOG_DEBUG(MSG, ...) LOG(::lm::log::LOG_LEVEL_DEBUG, STRING_FORMAT(MSG, ##__VA_ARGS__))
#define LOG_INFO(MSG, ...) LOG(::lm::log::LOG_LEVEL_INFO, STRING_FORMAT(MSG, ##__VA_ARGS__))
#define LOG_WARN(MSG, ...) LOG(::lm::log::LOG_LEVEL_WARN, STRING_FORMAT(MSG, ##__VA_ARGS__))
#define LOG_ERROR(MSG, ...) LOG(::lm::log::LOG_LEVEL_ERROR, STRING_FORMAT(MSG, ##__VA_ARGS__))
#define LOG_CRITICAL(MSG, ...) LOG(::lm::log::LOG_LEVEL_CRITICAL, STRING_FORMAT(MSG, ##__VA_ARGS__))
