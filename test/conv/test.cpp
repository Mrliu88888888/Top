#include <gtest/gtest.h>
#include "Conv.h"

TEST(Conv, U82GBK)
{
    const auto utf8 = std::string("hello世界！.");
    const auto gbk  = lm::coding::UTF8ToGBK(utf8);
    ASSERT_EQ(gbk, "hello\xCA\xC0\xBD\xE7\xA3\xA1.");
}

TEST(Conv, GBK2U8)
{
    const auto gbk  = lm::coding::UTF8ToGBK("hello世界！.");
    const auto utf8 = lm::coding::GBKToUTF8(gbk);
    ASSERT_EQ(utf8, std::string("hello世界！.\0"));
}

TEST(Conv, UnknownEncoding)
{
    ASSERT_EQ(lm::coding::ConvertEncoding("hello世界！", "UnknownEncoding", "UnknownEncoding"), "");
}
