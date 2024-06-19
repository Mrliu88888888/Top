#include "Conv.h"

#include <iconv.h>

namespace lm {
namespace coding {
Convert::Convert(const char* fromcode, const char* tocode)
    : conv_(NULL)
{
    conv_ = iconv_open(tocode, fromcode);
}
Convert::~Convert()
{
    if (is_valid()) {
        iconv_close(conv_);
    }
}
std::string Convert::conv(const std::string& str)
{
    auto        inBytesLeft  = str.size();
    auto        outBytesLeft = inBytesLeft * 2;
    std::string outBuf(outBytesLeft, '\0');
    auto        inPtr  = const_cast<char*>(str.data());
    auto        outPtr = outBuf.data();
    if (iconv(conv_, &inPtr, &inBytesLeft, &outPtr, &outBytesLeft) == (size_t)-1) {
        return "";
    }
    outBuf.resize(outBuf.size() - outBytesLeft);
    return outBuf;
}
}   // namespace coding
}   // namespace lm
