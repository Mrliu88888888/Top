#include "Log.h"
#include <spdlog/sinks/daily_file_sink.h>

void lm::log::Init(const std::string& filename, const spdlog::level::level_enum level,
                   const uint32_t max_files)
{
    auto logger = spdlog::daily_logger_mt("Top", filename, 0, 0, false, max_files);
    logger->flush_on(level);
    logger->set_level(level);
    logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] [%s:%#] [%!] %v");
    spdlog::set_default_logger(logger);
}
