#include "Log.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace lm {
namespace log {
static std::shared_ptr<spdlog::logger> logger;

inline auto LogLevel(const int& level)
{
    switch (level) {
    case LOG_LEVEL_TRACE: return spdlog::level::trace;
    case LOG_LEVEL_DEBUG: return spdlog::level::debug;
    case LOG_LEVEL_INFO: return spdlog::level::info;
    case LOG_LEVEL_WARN: return spdlog::level::warn;
    case LOG_LEVEL_ERROR: return spdlog::level::err;
    case LOG_LEVEL_CRITICAL: return spdlog::level::critical;
    default: return spdlog::level::off;
    }
}

TOP_LOG_API void Init(const std::string& logname, const int& level, const uint32_t& maxfilesize,
                      const uint32_t& maxfiles)
{
    logger = (0 == maxfilesize)
                 ? spdlog::stdout_color_mt(logname)
                 : spdlog::rotating_logger_mt(
                       logname, logname, maxfilesize, ((maxfiles <= 0) ? 1 : maxfiles));

    const auto logLevel = LogLevel(level);
    logger->set_level(logLevel);
    switch (logLevel) {
    case spdlog::level::trace:
    case spdlog::level::debug:
    case spdlog::level::info:
        logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] [%s:%#] [%!] %v");
        break;
    default: logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v"); break;
    }
}

TOP_LOG_API void Log(const int& level, const std::string& msg, const char* filename,
                     const int& linenum, const char* funcname)
{
    logger->log(spdlog::source_loc{filename, linenum, funcname}, LogLevel(level), msg);
    logger->flush();
}
}   // namespace log
}   // namespace lm
