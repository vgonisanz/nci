#include "gmock/gmock.h"
#include "../test_utils.h"

//#include "nci.h"

//using namespace nci;

using namespace ::testing;

struct TextCase
{
    /* inputs */
    std::string _text;

    TextCase(std::string text):
        _text(text) {}
};

class DisplayText: public TestWithParam<TextCase>
{
public:
};

TextCase test_text_cases[] = {
    TextCase("This is a test")
};

TEST_P(DisplayText, GivenTextExpectedDisplayProper)
{
    TextCase input = GetParam();

    /* Preconditions */
    EXPECT_TRUE(true);
}
INSTANTIATE_TEST_SUITE_P(BulkTest, DisplayText, ValuesIn(test_text_cases));
