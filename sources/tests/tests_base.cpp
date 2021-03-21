#include <string>
#include "gtest/gtest.h"

TEST(FirstTest, Test)
{
    bool expected = true;
    bool got = true;
    EXPECT_EQ(got, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}