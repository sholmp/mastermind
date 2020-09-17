#ifndef MASTERMINDLOGIC_HPP
#define MASTERMINDLOGIC_HPP

#include <string>

struct BWresult;

BWresult evaluateGuess(std::string input, std::string code);

bool codeIsValid(std::string code, std::string valid_colors, int code_length);
bool guessIsValid(std::string guess, std::string valid_colors, int code_length);

struct BWresult
{
    int blacks;
    int whites;

    //For google unit testing:
    BWresult(int b, int w) : blacks(b), whites(w){} //Made a constructor, because brace initialization not working inside gtest's EXPECT_EQ()
    bool operator==(const BWresult& rhs) const {
        return blacks == rhs.blacks && whites == rhs.whites;
    }
    bool operator !=(const BWresult& rhs) const {
        return !(*this == rhs);
    }
};

#endif
