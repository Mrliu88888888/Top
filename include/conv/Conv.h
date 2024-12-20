#pragma once

#include <string>
#include "Top/global.h"

namespace lm {
namespace coding {
/// @brief 字符串编码格式转换
class TOP_API Convert
{
public:
    /// @brief 构造
    /// @param fromcode 当前编码
    /// @param tocode 目标编码
    explicit Convert(const char* fromcode, const char* tocode);
    /// @brief 析构
    ~Convert();

    /// @brief 编码转换是否可用
    /// @return true: 可用
    ///        false: 不可用
    inline bool is_valid() const { return ((void*)-1 != conv_); }

    /// @brief 转换
    /// @param str 字符串
    /// @return 空: 转换失败
    ///             目标编码的字符串
    std::string conv(const std::string& str);

private:
    void* conv_;
};

/// @brief 字符串编码格式转换
/// @param input 字符串
/// @param fromcode 当前编码
/// @param tocode 目标编码
/// @return 空: 转换失败
///             目标编码的字符串
inline std::string ConvertEncoding(const std::string& input, const char* fromcode,
                                   const char* tocode)
{
    Convert conv(fromcode, tocode);
    return conv.is_valid() ? conv.conv(input) : "";
}

/// @brief UTF-8编码字符串转GBK编码
/// @param str 字符串
/// @return 空: 转换失败
///             目标编码的字符串
inline std::string UTF8ToGBK(const std::string& str)
{
    return ConvertEncoding(str, "UTF-8", "GBK");
}

/// @brief GBK编码字符串转UTF-8编码
/// @param str 字符串
/// @return 空: 转换失败
///             目标编码的字符串
inline std::string GBKToUTF8(const std::string& str)
{
    return ConvertEncoding(str, "GBK", "UTF-8");
}
}   // namespace coding
}   // namespace lm
