#include "mastermindplayer.hpp"

void MastermindPlayer::addToScore(int amount)
{
    score_ += amount;
}

std::string MastermindPlayer::getName()
{
    return name_;
}

int MastermindPlayer::getScore()
{
    return score_;
}
