#include "humanplayer.hpp"
#include <iostream>

using namespace std;
HumanPlayer::HumanPlayer()
{

}

string HumanPlayer::makeGuess(const BWresult &previous_result)
{
    string guess;
    cin >> guess;
    return guess;
}

string HumanPlayer::makeCode()
{
    string code;
    cin >> code;
    return code;
}

