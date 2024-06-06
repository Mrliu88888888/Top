#pragma once

#include <string>

#ifdef _MSC_VER
#    ifdef TOP_CONV_EXPORTS
#        define TOP_CONV_API __declspec(dllexport)
#    else
#        define TOP_CONV_API __declspec(dllimport)
#    endif
#else
#    define TOP_CONV_API
#endif

namespace lm {
namespace coding {
TOP_CONV_API std::string UTF8ToGBK(const std::string& str);
TOP_CONV_API std::string GBKToUTF8(const std::string& str);
}   // namespace coding
}   // namespace lm
