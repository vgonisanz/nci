#include "gtest/gtest.h"
#include "gmock/gmock.h"

/**
 * Common main Source code. Link against every test just to run all tests
 */
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
