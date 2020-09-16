#ifndef MASTERMINDGAME_H
#define MASTERMINDGAME_H

#include <unordered_set>
#include <string>
#include "mastermindlogic.hpp"

//struct BWResult;

class MastermindGame
{
public:
    MastermindGame(std::string valid_colors, int code_length);
    void run();

    static const int max_code_length = 8;
    static const int max_colors = 8;

private:
    BWResult evaluateGuess(std::string input, std::string code) const;
    bool inputIsValid(std::string input) const;
    void fsm();

private:
    enum class State
    {
        INIT, INPUT_CODE, INPUT_GUESS, GAME_OVER
    };
    State state_ = State::INIT;
    int attempts_ = 3;
    int code_length_;
    std::string code_;
    std::string valid_colors_;
    MastermindLogic mastermind_logic_;

};


#endif // MASTERMINDGAME_H
