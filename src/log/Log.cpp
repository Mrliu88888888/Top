#include "Log.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

namespace lm {
namespace log {
static std::shared_ptr<spdlog::logger> logger;

static auto LogLevel(const int level)
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

static void SetLogLevel(const int level)
{
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

Info::Info()
    : level(LOG_LEVEL_INFO)
    , maxfilesize(1024 * 1024 * 10)
    , maxfiles(180)
{}

void InitForSize(const std::string& logname, const int level, const uint32_t maxfilesize,
                 const uint32_t maxfiles)
{
    logger = (0 == maxfilesize)
                 ? spdlog::stdout_color_mt(logname)
                 : spdlog::rotating_logger_mt(
                       logname, logname, maxfilesize, ((maxfiles <= 0) ? 1 : maxfiles));
    SetLogLevel(level);
}

void InitForDaily(const std::string& logname, const int level, const uint32_t maxfiles)
{
    logger = (0 == maxfiles) ? spdlog::stdout_color_mt(logname)
                             : spdlog::daily_logger_mt(logname, logname, 0, 0, false, maxfiles);
    SetLogLevel(level);
}

void Log(const int level, const std::string_view& msg, const char* filename, const int linenum,
         const char* funcname)
{
    logger->log(spdlog::source_loc{filename, linenum, funcname}, LogLevel(level), msg);
    logger->flush();
}
}   // namespace log
}   // namespace lm
