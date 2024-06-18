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
class TOP_CONV_API Convert
{
public:
    explicit Convert(const char* fromcode, const char* tocode);
    ~Convert();

    inline bool is_open() const { return ((void*)-1 != conv_); }
    std::string conv(const std::string& str);

private:
    void* conv_;
};

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
