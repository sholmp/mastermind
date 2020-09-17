#include <gtest/gtest.h>
#include <string>

//#include <mastermind.hpp>
#include <mastermindgame.hpp>
#include <mastermindlogic.hpp>


TEST(LogicTest, evaluateGuessTest)
{
    EXPECT_EQ(BWresult(4,0), evaluateGuess("RRRR", "RRRR"));
    EXPECT_EQ(BWresult(0,0), evaluateGuess("ABCD", "EFGH"));
    EXPECT_EQ(BWresult(0,4), evaluateGuess("RBRB", "BRBR"));

    EXPECT_EQ(BWresult(1,0), evaluateGuess("q", "qq"));
    EXPECT_EQ(BWresult(1,0), evaluateGuess("q", "qq"));
}

TEST(LogicTest, guessIsValidTest)
{
    std::string valid_colors = "rgbypm";

    EXPECT_TRUE(guessIsValid("rgbr", valid_colors, 4));
    EXPECT_TRUE(guessIsValid("rgbb", valid_colors, 4));
    EXPECT_TRUE(guessIsValid("rrrr", valid_colors, 4));
    EXPECT_TRUE(guessIsValid("ypmr", valid_colors, 4));

    //Using non valid colors:
    EXPECT_FALSE(guessIsValid("qqqq", valid_colors, 4));
    EXPECT_FALSE(guessIsValid("1234", valid_colors, 4));

    //Using inputs with wrong lengths:
    EXPECT_FALSE(guessIsValid("", valid_colors, 4));
    EXPECT_FALSE(guessIsValid("r", valid_colors, 4));
    EXPECT_FALSE(guessIsValid("rgbbbbb", valid_colors, 4));
    EXPECT_FALSE(guessIsValid("rrrr", valid_colors, 7));
}





