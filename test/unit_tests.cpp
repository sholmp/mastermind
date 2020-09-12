#include <gtest/gtest.h>
#include <mastermind.hpp>


TEST(MastermindLogic, FourColumns)
{
    EXPECT_EQ(std::make_pair(4,0), compareInputToCode("RRRR", "RRRR"));
    EXPECT_EQ(std::make_pair(0,0), compareInputToCode("ABCD", "EFGH"));
    EXPECT_EQ(std::make_pair(0,4), compareInputToCode("RBRB", "BRBR"));

    EXPECT_NE(std::make_pair(4,1), compareInputToCode("RRRR", "RRRR"));


}
