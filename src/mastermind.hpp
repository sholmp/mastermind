#ifndef MASTERMIND_HPP
#define MASTERMIND_HPP

#include <string>
#include <set>


//output: {blacks, whites}

struct BWResult
{
    int blacks;
    int whites;

    //For google unit testing:
    BWResult(int b, int w) : blacks(b), whites(w){} //Made a constructor, because brace initialization not working inside gtest's EXPECT_EQ()
    bool operator==(const BWResult& rhs) const {
        return blacks == rhs.blacks && whites == rhs.whites;
    }
    bool operator !=(const BWResult& rhs) const {
        return !(*this == rhs);
    }
};

BWResult compareInputToCode(std::string input, std::string code);

struct InputException
{
    InputException(std::string message) : message_(message) {}
    std::string message_;
};

bool codeIsValid(std::string code, std::set<char> valid_colors, int code_length);


#endif
