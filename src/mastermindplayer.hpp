#ifndef MASTERMINDPLAYER_HPP
#define MASTERMINDPLAYER_HPP

#include <string>

class MastermindPlayer
{
public:
    virtual std::string makeGuess() = 0;
    virtual std::string makeCode() = 0;

private:


};

#endif
