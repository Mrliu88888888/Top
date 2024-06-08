#include <gtest/gtest.h>
#include "App.h"

TEST(App, HandlesMixedInput1)
{
    ASSERT_TRUE(lm::app::ChangeWorkPath());
}
