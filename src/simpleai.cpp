#include "simpleai.hpp"
#include <iostream>

using namespace std;

SimpleAI::SimpleAI(string name, std::string valid_colors, int code_length):
    valid_colors_(valid_colors), code_length_(code_length)
{
    name_ = name;
    getAllPossibleCombinations(possible_guesses_, valid_colors_, code_length_, "");
    active_set_ = possible_guesses_;
}

string SimpleAI::makeGuess(const BWresult &latest_result)
{
    string guess;
    if(latest_result == BWresult(-1,-1))
    {
        guess = *active_set_.begin();
        active_set_ = possible_guesses_;
    }
    else
    {
        eraseCombinationsNotMatchingResult(active_set_, latest_guess_, latest_result);
        guess = *active_set_.begin();
    }

    cout << guess << "\n"; //To beautify the console output from statemachine

    latest_guess_ = guess;
    return guess;
}

string SimpleAI::makeCode()
{
    return makeRandomCode(valid_colors_, code_length_);
}
