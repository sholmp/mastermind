#ifndef MASTERMINDGAME_H
#define MASTERMINDGAME_H

#include <unordered_set>
#include <string>


struct BWResult;

class MastermindGame
{
public:
    MastermindGame();
    MastermindGame(std::string valid_colors, int code_length);
    void run();

private:
    BWResult compareInputToCode(std::string input, std::string code);
    bool inputIsValid(std::string input);
    void fsm();

private:
    enum class State
    {
        INIT, INPUT_CODE, INPUT_GUESS, GAME_OVER
    };
    State state_ = State::INIT;
    std::unordered_set<char> valid_colors_ = {'r','g','b','y','p','m','R','G','B','Y','P','M'};
    int code_length_ = 4;
    int attempts_ = 3;
    std::string code_;

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

#endif // MASTERMINDGAME_H
