#include <gtest/gtest.h>
#include "Conv.h"

TEST(Conv, U82GBK)
{
    const auto source = std::string(u8"hello世界！.");
    const auto gbk    = lm::coding::UTF8ToGBK(source);
    ASSERT_FALSE(gbk.empty());
}

TEST(Conv, GBK2U8)
{
    const auto source = lm::coding::UTF8ToGBK(u8"hello世界！.");
    const auto utf8   = lm::coding::GBKToUTF8(source);
    ASSERT_FALSE(utf8.empty());
}
