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
    ASSERT_EQ(lm::app::SingleApp(),
#ifdef __linux__
              0
#else
              1
#endif   // __linux__
    );
}
