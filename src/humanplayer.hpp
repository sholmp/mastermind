#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "mastermindplayer.hpp"
#include "mastermindlogic.hpp"

class HumanPlayer : public MastermindPlayer
{
public:
    HumanPlayer(std::string name);

    std::string makeGuess(const BWresult& previous_result) override;
    std::string makeCode() override;

};

#endif // HUMANPLAYER_HPP
