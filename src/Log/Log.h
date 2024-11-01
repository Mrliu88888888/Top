#pragma once

#include <fmt/format.h>
#include "Top/global.h"

namespace lm {
namespace log {
constexpr int LOG_LEVEL_TRACE    = 0;
constexpr int LOG_LEVEL_DEBUG    = 1;
constexpr int LOG_LEVEL_INFO     = 2;
constexpr int LOG_LEVEL_WARN     = 3;
constexpr int LOG_LEVEL_ERROR    = 4;
constexpr int LOG_LEVEL_CRITICAL = 5;

/// @brief 初始化日志 按文件大小
/// @param logname 日志文件名
/// @param level 日志等级
/// @param maxfilesize 0: 输出到控制台
///                    >0: 输出到文件 字节 (KB)
///                                   1024 * 1024 = 1MB
///                                   1024 * 1024 * 1024 = 1GB
/// @param maxfiles 最大日志文件数
TOP_API void InitForSize(const std::string& logname, const int level, const uint32_t maxfilesize,
                         const uint32_t maxfiles);

/// @brief 初始化日志 按天数
/// @param logname 日志文件名
/// @param level 日志等级
/// @param maxfiles 最大日志文件数 0: 输出到控制台
///                               >0: 保存maxfiles天文件
TOP_API void InitForDaily(const std::string& logname, const int level, const uint32_t maxfiles);

/// @brief 输出日志
/// @param level 日志等级
/// @param msg 输出消息
/// @param filename 源码文件名
/// @param linenum 源码行号
/// @param funcname 函数名
TOP_API void Log(const int level, const std::string_view& msg, const char* filename,
                 const int linenum, const char* funcname);
}   // namespace log
}   // namespace lm

#define LOG_OUT(LEVEL, MSG) \
    ::lm::log::Log(LEVEL, MSG, __FILE__, __LINE__, static_cast<const char*>(__FUNCTION__))
#define LOG_FORMAT(LEVEL, MSG, ...) LOG_OUT(LEVEL, ::fmt::format(MSG, ##__VA_ARGS__))

#define LOG_1(LEVEL) LOG_OUT(LEVEL, "")
#define LOG_2(LEVEL, MSG) LOG_OUT(LEVEL, MSG)
#define LOG_3(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_4(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_5(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_6(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_7(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_8(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_9(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_10(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_11(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_12(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_13(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_14(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_15(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_16(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_17(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_18(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_19(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_20(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_21(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_22(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_23(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_24(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_25(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_26(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_27(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_28(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_29(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_30(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_31(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_32(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_33(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_34(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_35(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_36(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_37(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_38(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_39(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_40(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_41(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_42(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_43(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_44(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_45(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_46(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_47(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_48(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_49(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_50(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_51(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_52(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_53(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_54(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_55(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_56(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_57(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_58(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_59(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_60(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_61(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_62(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_63(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)
#define LOG_64(LEVEL, MSG, ...) LOG_FORMAT(LEVEL, MSG, ##__VA_ARGS__)

#define PRIVATE_MACRO_VAR_ARGS_IMPL_COUNT(_1,  \
                                          _2,  \
                                          _3,  \
                                          _4,  \
                                          _5,  \
                                          _6,  \
                                          _7,  \
                                          _8,  \
                                          _9,  \
                                          _10, \
                                          _11, \
                                          _12, \
                                          _13, \
                                          _14, \
                                          _15, \
                                          _16, \
                                          _17, \
                                          _18, \
                                          _19, \
                                          _20, \
                                          _21, \
                                          _22, \
                                          _23, \
                                          _24, \
                                          _25, \
                                          _26, \
                                          _27, \
                                          _28, \
                                          _29, \
                                          _30, \
                                          _31, \
                                          _32, \
                                          _33, \
                                          _34, \
                                          _35, \
                                          _36, \
                                          _37, \
                                          _38, \
                                          _39, \
                                          _40, \
                                          _41, \
                                          _42, \
                                          _43, \
                                          _44, \
                                          _45, \
                                          _46, \
                                          _47, \
                                          _48, \
                                          _49, \
                                          _50, \
                                          _51, \
                                          _52, \
                                          _53, \
                                          _54, \
                                          _55, \
                                          _56, \
                                          _57, \
                                          _58, \
                                          _59, \
                                          _60, \
                                          _61, \
                                          _62, \
                                          _63, \
                                          _64, \
                                          N,   \
                                          ...) \
    N
#define PRIVATE_MACRO_VAR_ARGS_IMPL(args) PRIVATE_MACRO_VAR_ARGS_IMPL_COUNT args
#define COUNT_MACRO_VAR_ARGS(...)             \
    PRIVATE_MACRO_VAR_ARGS_IMPL((__VA_ARGS__, \
                                 64,          \
                                 63,          \
                                 62,          \
                                 61,          \
                                 60,          \
                                 59,          \
                                 58,          \
                                 57,          \
                                 56,          \
                                 55,          \
                                 54,          \
                                 53,          \
                                 52,          \
                                 51,          \
                                 50,          \
                                 49,          \
                                 48,          \
                                 47,          \
                                 46,          \
                                 45,          \
                                 44,          \
                                 43,          \
                                 42,          \
                                 41,          \
                                 40,          \
                                 39,          \
                                 38,          \
                                 37,          \
                                 36,          \
                                 35,          \
                                 34,          \
                                 33,          \
                                 32,          \
                                 31,          \
                                 30,          \
                                 29,          \
                                 28,          \
                                 27,          \
                                 26,          \
                                 25,          \
                                 24,          \
                                 23,          \
                                 22,          \
                                 21,          \
                                 20,          \
                                 19,          \
                                 18,          \
                                 17,          \
                                 16,          \
                                 15,          \
                                 14,          \
                                 13,          \
                                 12,          \
                                 11,          \
                                 10,          \
                                 9,           \
                                 8,           \
                                 7,           \
                                 6,           \
                                 5,           \
                                 4,           \
                                 3,           \
                                 2,           \
                                 1))

#define PRIVATE_MACRO_CHOOSE_HELPER2(M, count) M##count
#define PRIVATE_MACRO_CHOOSE_HELPER1(M, count) PRIVATE_MACRO_CHOOSE_HELPER2(M, count)
#define PRIVATE_MACRO_CHOOSE_HELPER(M, count) PRIVATE_MACRO_CHOOSE_HELPER1(M, count)

#ifdef WIN32
#    define EXPAND(...) __VA_ARGS__
#    define LOG(...) \
        EXPAND(PRIVATE_MACRO_CHOOSE_HELPER(LOG_, COUNT_MACRO_VAR_ARGS(__VA_ARGS__))(__VA_ARGS__))
#else
#    define LOG(...) \
        PRIVATE_MACRO_CHOOSE_HELPER(LOG_, COUNT_MACRO_VAR_ARGS(__VA_ARGS__))(__VA_ARGS__)
#endif

#define LOG_TRACE(...) LOG(::lm::log::LOG_LEVEL_TRACE, ##__VA_ARGS__)
#define LOG_DEBUG(...) LOG(::lm::log::LOG_LEVEL_DEBUG, ##__VA_ARGS__)
#define LOG_INFO(...) LOG(::lm::log::LOG_LEVEL_INFO, ##__VA_ARGS__)
#define LOG_WARN(...) LOG(::lm::log::LOG_LEVEL_WARN, ##__VA_ARGS__)
#define LOG_ERROR(...) LOG(::lm::log::LOG_LEVEL_ERROR, ##__VA_ARGS__)
#define LOG_CRITICAL(...) LOG(::lm::log::LOG_LEVEL_CRITICAL, ##__VA_ARGS__)
