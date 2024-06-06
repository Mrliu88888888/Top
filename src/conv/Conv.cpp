#include "Conv.h"
#ifdef _WIN32
#    include <Windows.h>
#endif

namespace lm {
namespace coding {
#ifdef _WIN32
TOP_CONV_API std::string UTF8ToGBK(const std::string& str)
{
    if (str.empty()) {
        return "";
    }

    std::wstring unicodeStr;
    {
        const auto size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
        unicodeStr.resize(size);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, unicodeStr.data(), size);
    }

    std::string gbkStr;
    {
        const auto size =
            WideCharToMultiByte(CP_ACP, 0, unicodeStr.c_str(), -1, NULL, 0, NULL, NULL);
        gbkStr.resize(size);
        WideCharToMultiByte(CP_ACP, 0, unicodeStr.c_str(), -1, gbkStr.data(), size, NULL, NULL);
    }

    return gbkStr;
}

TOP_CONV_API std::string GBKToUTF8(const std::string& str)
{
    if (str.empty()) {
        return "";
    }

    std::wstring unicodeStr;
    {
        const auto size = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
        unicodeStr.resize(size);
        MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, unicodeStr.data(), size);
    }

    std::string utf8Str;
    {
        const auto size =
            WideCharToMultiByte(CP_UTF8, 0, unicodeStr.c_str(), -1, NULL, 0, NULL, NULL);
        utf8Str.resize(size);
        WideCharToMultiByte(CP_UTF8, 0, unicodeStr.c_str(), -1, utf8Str.data(), size, NULL, NULL);
    }

    return utf8Str;
}
#else

#endif
}   // namespace coding
}   // namespace lm
