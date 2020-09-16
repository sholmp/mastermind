#ifndef MASTERMINDLOGIC_H
#define MASTERMINDLOGIC_H

#include <unordered_set>
#include <string>

struct BWResult;

class MastermindLogic
{
public:
    MastermindLogic(std::string valid_colors, int code_length);
    BWResult evaluateGuess(std::string input, std::string code) const;
    bool inputIsValid(std::string guess) const;
private:
    int code_length_;
    std::unordered_set<char> valid_colors_;

};

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


#endif // MASTERMINDLOGIC_H
