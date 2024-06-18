#pragma once

#include <string>

#ifdef _MSC_VER
#    ifdef TOP_CONV_EXPORTS
#        define TOP_CONV_API __declspec(dllexport)
#    else
#        define TOP_CONV_API __declspec(dllimport)
#    endif

#    ifdef TOP_CONV_STATIC
#        undef TOP_CONV_API
#        define TOP_CONV_API
#    endif
#else
#    define TOP_CONV_API
#endif

namespace lm {
namespace coding {
/// @brief 字符串编码格式转换
class TOP_CONV_API Convert
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
    inline bool is_open() const { return ((void*)-1 != conv_); }

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
    return conv.is_open() ? conv.conv(input) : "";
}

inline std::string UTF8ToGBK(const std::string& str)
{
    return ConvertEncoding(str, "UTF-8", "GBK");
}
inline std::string GBKToUTF8(const std::string& str)
{
    return ConvertEncoding(str, "GBK", "UTF-8");
}
}   // namespace coding
}   // namespace lm
