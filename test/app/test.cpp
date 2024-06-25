#include <gtest/gtest.h>
#include "App.h"

TEST(App, ChangeWorkPath)
{
    ASSERT_TRUE(lm::app::ChangeWorkPath());
}

TEST(App, SingleApp)
{
    ASSERT_EQ(lm::app::SingleApp(), 0);
}

TEST(App, SingleApp2)
{
#ifdef _WIN32
    ASSERT_EQ(lm::app::SingleApp(), 1);
#elif __linux__
    ASSERT_EQ(lm::app::SingleApp(), 0);
#else
    ASSERT_TRUE(false);
#endif   // _WIN32
}
