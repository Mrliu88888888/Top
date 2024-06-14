#include <gtest/gtest.h>
#include "App.h"

TEST(App, ChangeWorkPath)
{
    ASSERT_TRUE(lm::app::ChangeWorkPath());
}
