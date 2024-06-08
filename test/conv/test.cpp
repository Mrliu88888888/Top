#include <gtest/gtest.h>
#include "Conv.h"

TEST(Conv, U82GBK)
{
    const auto source = std::string(u8"hello世界！.");
    const auto gbk    = lm::coding::UTF8ToGBK(source);
    const auto utf8   = lm::coding::GBKToUTF8(gbk);
    ASSERT_EQ(source, utf8);
}
