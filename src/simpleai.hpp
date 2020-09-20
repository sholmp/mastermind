#ifndef SIMPLEAI_HPP
#define SIMPLEAI_HPP

#include "mastermindplayer.hpp"
#include "mastermindlogic.hpp"

class SimpleAI : public MastermindPlayer
{
public:
    SimpleAI(std::string name, std::string valid_colors, int code_length);

    std::string makeGuess(const BWresult &latest_result) override;
    std::string makeCode() override;

private:
    std::list<std::string> active_set_;
    std::string first_guess_;
    std::string latest_guess_;

    int code_length_;
    std::string valid_colors_;


};

#endif // SIMPLEAI_HPP
