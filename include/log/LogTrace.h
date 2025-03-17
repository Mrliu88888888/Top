#pragma once

#include "Log.h"

namespace _log {
class LogTraceScoped final
{
public:
    explicit LogTraceScoped(const char* filename, const int32_t linenum, const char* funcname,
                            const std::string_view& msg = "")
        : filename_(filename)
        , linenum_(linenum)
        , funcname_(funcname)
        , msg_(msg)
    {
        spdlog::log(spdlog::source_loc{filename_, linenum_, funcname_},
                    spdlog::level::trace,
                    msg_.empty() ? "[in]" : "[in] {}",
                    msg_);
    }
    ~LogTraceScoped()
    {
        spdlog::log(spdlog::source_loc{filename_, linenum_, funcname_},
                    spdlog::level::trace,
                    msg_.empty() ? "[out]" : "[out] {}",
                    msg_);
    }

private:
    const char*       filename_;
    const int32_t     linenum_;
    const char*       funcname_;
    const std::string msg_;
};
}   // namespace _log

#define LOG_TRACE_EMPTY LOG_TRACE("")
#define LOG_TRACE_SCOPED _log::LogTraceScoped __LOGTRACESCOPED(__FILE__, __LINE__, SPDLOG_FUNCTION)
#define LOG_TRACE_SCOPED_MESSAGE(MSG) \
    _log::LogTraceScoped __LOGTRACESCOPEDMESSAGE(__FILE__, __LINE__, SPDLOG_FUNCTION, MSG)
