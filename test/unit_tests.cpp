#include <gtest/gtest.h>
#include <mastermind.hpp>


TEST(MastermindLogic, FourColumns)
{
    EXPECT_EQ(BWResult(4,0), compareInputToCode("RRRR", "RRRR"));
    EXPECT_EQ(BWResult(0,0), compareInputToCode("ABCD", "EFGH"));
    EXPECT_EQ(BWResult(0,4), compareInputToCode("RBRB", "BRBR"));
    EXPECT_NE(BWResult(4,1), compareInputToCode("RRRR", "RRRR"));
}


TEST(InputTest, TestIsValidCode)
{
    using namespace std;
    uint code_length = 4;
    set<char> valid_colors = {'r', 'g', 'b', 'y', 'p', 'm'};
}

