#include <gtest/gtest.h>
#include "App.h"

TEST(App, HandlesMixedInput1)
{
    ASSERT_TRUE(lm::app::ChangeWorkPath());
}

TEST(AdditionTest, HandlesMixedInput1)
{
    EXPECT_EQ(1, 1);
}
TEST(AdditionTest, HandlesMixedInput2)
{
    EXPECT_EQ(1, 1);
}
TEST(AdditionTest, HandlesMixedInput3)
{
    EXPECT_EQ(1, 1);
}
TEST(AdditionTest, HandlesMixedInput4)
{
    EXPECT_EQ(1, 1);
}
TEST(AdditionTest, HandlesMixedInput5)
{
    EXPECT_EQ(1, 2);
}
