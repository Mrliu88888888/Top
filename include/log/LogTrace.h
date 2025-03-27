#pragma once

#include "Log.h"

namespace _log {
class LogScoped final
{
public:
    explicit LogScoped(const char* filename, const int32_t linenum, const char* funcname,
                       const spdlog::level::level_enum level, const std::string_view& msg)
        : source_loc_({filename, linenum, funcname})
        , level_(level)
        , msg_(msg)
    {
        spdlog::log(source_loc_, level_, msg_.empty() ? "[in]" : "[in] {}", msg_);
    }
    ~LogScoped() { spdlog::log(source_loc_, level_, msg_.empty() ? "[out]" : "[out] {}", msg_); }

private:
    const spdlog::source_loc        source_loc_;
    const spdlog::level::level_enum level_;
    const std::string               msg_;
};
}   // namespace _log

#define __CALL_LOGSCOPED(LEVEL, MSG) \
    _log::LogScoped __LOGSCOPED(__FILE__, __LINE__, SPDLOG_FUNCTION, LEVEL, MSG)

#define LOG_TRACE_SCOPED_MESSAGE(MSG) __CALL_LOGSCOPED(spdlog::level::trace, MSG)
#define LOG_TRACE_SCOPED LOG_TRACE_SCOPED_MESSAGE("")

#define LOG_DEBUG_SCOPED_MESSAGE(MSG) __CALL_LOGSCOPED(spdlog::level::debug, MSG)
#define LOG_DEBUG_SCOPED LOG_DEBUG_SCOPED_MESSAGE("")

#define LOG_INFO_SCOPED_MESSAGE(MSG) __CALL_LOGSCOPED(spdlog::level::info, MSG)
#define LOG_INFO_SCOPED LOG_INFO_SCOPED_MESSAGE("")
