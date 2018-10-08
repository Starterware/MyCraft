#include "StringCalculator.hpp"

#include <gtest/gtest.h>

class StringCalculatorTest : public ::testing::Test 
{
    protected:

    virtual void SetUp() {
    }
    
    virtual void TearDown() {
    }
    
    StringCalculator stringCalculator;
};

TEST_F(StringCalculatorTest, addition_of_empty_string_gives_zero)
{
    int result = stringCalculator.addition("");
    ASSERT_EQ(0, result);
}
