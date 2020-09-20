#include "simpleai.hpp"

SimpleAI::SimpleAI(std::string valid_colors, int code_length):
    valid_colors_(valid_colors), code_length_(code_length)
{
    getAllPossibleCombinations(S_, valid_colors_, code_length_, "");
    possible_guesses_ = S_;
}

std::string SimpleAI::makeGuess(const BWresult &previous_result)
{
    return "";
}

std::string SimpleAI::makeCode()
{
    return makeRandomCode(valid_colors_, code_length_);
}
