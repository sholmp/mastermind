#ifndef MASTERMINDPLAYER_HPP
#define MASTERMINDPLAYER_HPP

#include <string>

struct BWresult;

class MastermindPlayer
{
public:
    virtual std::string makeGuess(const BWresult& latest_result) = 0;
    virtual std::string makeCode() = 0;

    void addToScore(int amount);
    std::string getName();
    int getScore();

protected:
    std::string name_;
    int score_ = 0;
};

#endif
