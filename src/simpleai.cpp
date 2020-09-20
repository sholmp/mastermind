#include "simpleai.hpp"

using namespace std;

SimpleAI::SimpleAI(string name, std::string valid_colors, int code_length):
    valid_colors_(valid_colors), code_length_(code_length)
{
    name_ = name;
    getAllPossibleCombinations(active_set_, valid_colors_, code_length_, "");
}

string SimpleAI::makeGuess(const BWresult &latest_result)
{
    string guess;
    if(latest_result == BWresult(-1,-1))
        guess = *active_set_.begin();
    else
    {
        eraseCombinationsNotMatchingResult(active_set_, latest_guess_, latest_result);
        guess = *active_set_.begin();
    }

    latest_guess_ = guess;
    return guess;
}

string SimpleAI::makeCode()
{
    return makeRandomCode(valid_colors_, code_length_);
}
