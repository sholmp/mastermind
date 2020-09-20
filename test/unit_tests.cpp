#include <gtest/gtest.h>
#include <string>

#include <mastermindgame.hpp>
#include <mastermindlogic.hpp>
#include <fiveguessai.hpp>
#include <cmath>


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



TEST(LogicTest, getCombinationsTest)
{
    std::string valid_colors = "123456";
    int code_length = 4;
    std::list<std::string> combinations;
    getAllPossibleCombinations(combinations, valid_colors, code_length, "");

    EXPECT_EQ(combinations.size(), std::pow(valid_colors.length(), code_length)); // e.g. combinations.size() == 1296, for 6 colors, and code_len = 4
}


TEST(PlayerTest, FiveGuessAI)
{
    srand(time(NULL));
    int code_length = 4;
    std::string colors = "123456";

    FiveGuessAI fg(colors, code_length);
    std::string code = fg.makeCode();
    BWresult latest_result(-1,-1);

    int guess_count = 0;
    std::string guess;

    while(latest_result.blacks != code_length)
    {
        guess = fg.makeGuess(latest_result);
        latest_result = evaluateGuess(guess, code);
        guess_count++;
    }

    EXPECT_EQ(guess, code);
    EXPECT_LE(guess_count, 5);
}




