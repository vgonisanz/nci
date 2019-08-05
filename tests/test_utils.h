#ifndef __TEST_UTILS_HEADER_FILE_H
#define __TEST_UTILS_HEADER_FILE_H

#include <fstream>

/**
 * Check if a file exists
 */
inline ::testing::AssertionResult FileExist(std::string filename)
{
    std::ifstream infile(filename.c_str());
    if(infile.good())
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure()
            << "File: " << filename << " no exists.";
}
/**
 * All utils for testing are here
 */
inline ::testing::AssertionResult IsBetween(int val, int a, int b)
{
    if((val >= a) && (val <= b))
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure()
            << val << " is outside the range " << a << " to " << b;
}

#endif  /* __TEST_UTILS_HEADER_FILE_H */
