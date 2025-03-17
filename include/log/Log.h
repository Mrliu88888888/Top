#pragma once

#include <spdlog/spdlog.h>
#include "Top/global.h"

namespace lm {
namespace log {
TOP_API void Init(const std::string& filename, const spdlog::level::level_enum level,
                  const uint32_t max_files);
}   // namespace log
}   // namespace lm

#define __CALL_SPDLOG(LEVEL, ...)                                        \
    spdlog::log(spdlog::source_loc{__FILE__, __LINE__, SPDLOG_FUNCTION}, \
                spdlog::level::LEVEL,                                    \
                __VA_ARGS__)

#define LOG_TRACE(...) __CALL_SPDLOG(trace, __VA_ARGS__)
#define LOG_DEBUG(...) __CALL_SPDLOG(debug, __VA_ARGS__)
#define LOG_INFO(...) __CALL_SPDLOG(info, __VA_ARGS__)
#define LOG_WARN(...) __CALL_SPDLOG(warn, __VA_ARGS__)
#define LOG_ERROR(...) __CALL_SPDLOG(err, __VA_ARGS__)
#define LOG_CRITICAL(...) __CALL_SPDLOG(critical, __VA_ARGS__)
