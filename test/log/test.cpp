#include <gtest/gtest.h>
#include "Log.h"

TEST(demo, log_count)
{
    lm::log::InitForSize("log/test.log", lm::log::LOG_LEVEL_TRACE, 1024 * 1024, 5);

    LOG_TRACE("hello world {} {}", 1, "123");
    LOG_DEBUG("hello world");
    LOG_INFO("hello world");
    LOG_WARN("hello world");
    LOG_ERROR("hello world");
    LOG_CRITICAL("hello world");
}
