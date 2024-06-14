#include <gtest/gtest.h>
#include "Log.h"

TEST(demo, log_count)
{
    lm::log::Init("log/test.log", lm::log::LOG_LEVEL_TRACE, 100, 5);

    LOG_DEBUG("hello world");
    LOG_INFO("hello world");
    LOG_WARN("hello world");
    LOG_ERROR("hello world");
    LOG_CRITICAL("hello world");

    ASSERT_EQ(
        []() -> int {
            // TODO 获取目录下的文件个数

            return 5;
        }(),
        5);
}
