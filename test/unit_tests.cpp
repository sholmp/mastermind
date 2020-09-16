#include <gtest/gtest.h>

#include <mastermindgame.hpp>
#include <mastermindlogic.hpp>



TEST(InputTest, inputIsValidTest)
{
    MastermindLogic mml("rgbypm", 4);

    EXPECT_TRUE(mml.inputIsValid("rgbb"));
    EXPECT_TRUE(mml.inputIsValid("rrrr"));
    EXPECT_TRUE(mml.inputIsValid("ypmr"));

    EXPECT_FALSE(mml.inputIsValid("qqqq"));
    EXPECT_FALSE(mml.inputIsValid("12345"));
    EXPECT_FALSE(mml.inputIsValid("rrrrr"));
    EXPECT_FALSE(mml.inputIsValid("rrr"));
    EXPECT_FALSE(mml.inputIsValid(""));
}

TEST(LogicTest, evaluateGuessTest)
{
    MastermindLogic mml("", 0);

    EXPECT_EQ(BWResult(4,0), mml.evaluateGuess("RRRR", "RRRR"));
    EXPECT_EQ(BWResult(0,0), mml.evaluateGuess("ABCD", "EFGH"));
    EXPECT_EQ(BWResult(0,4), mml.evaluateGuess("RBRB", "BRBR"));


    EXPECT_EQ(BWResult(1,0), mml.evaluateGuess("q", "qq"));
    EXPECT_EQ(BWResult(1,0), mml.evaluateGuess("q", "qq"));

}



