#ifndef SIMPLEAI_HPP
#define SIMPLEAI_HPP

#include "mastermindplayer.hpp"
#include "mastermindlogic.hpp"

class SimpleAI : MastermindPlayer
{
public:
    SimpleAI(std::string valid_colors, int code_length);

    std::string makeGuess(const BWresult &previous_result) override;
    std::string makeCode() override;

private:
    std::list<std::string> S_;
    std::list<std::string> possible_guesses_;
    std::string first_guess_;
    std::string latest_guess_;

    int code_length_;
    std::string valid_colors_;


};

#endif // SIMPLEAI_HPP
