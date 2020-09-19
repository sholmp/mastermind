#ifndef MASTERMINDGAME_HPP
#define MASTERMINDGAME_HPP

#include <string>
#include "mastermindlogic.hpp"
#include "mastermindplayer.hpp"

class MastermindGame
{
public:
    MastermindGame(std::string valid_colors, int code_length);
    void run();
    void setPlayers(MastermindPlayer* code_maker, MastermindPlayer* code_breaker);

    int getCodeLength();
    std::string getValidColors();


    static const int max_code_length = 8;
    static const int max_colors = 8;

private:
    void fsm();

private:
    enum class State
    {
        INIT, INPUT_CODE, INPUT_GUESS, GAME_OVER
    };
    State state_ = State::INIT;
    int attempts_ = 5;
    int code_length_;
    std::string code_;
    std::string valid_colors_;

    MastermindPlayer* code_maker_;
    MastermindPlayer* code_breaker_;

};


#endif // MASTERMINDGAME_H
