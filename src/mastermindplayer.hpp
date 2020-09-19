#ifndef MASTERMINDPLAYER_HPP
#define MASTERMINDPLAYER_HPP

#include <string>

struct BWresult;

class MastermindPlayer
{
public:
    virtual std::string makeGuess(const BWresult& previous_result) = 0;
    virtual std::string makeCode() = 0;

private:


};

#endif
