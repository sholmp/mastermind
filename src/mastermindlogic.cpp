#include "mastermindlogic.hpp"
#include <map>
#include <vector>

using namespace std;

MastermindLogic::MastermindLogic(std::string valid_colors, int code_length):
    code_length_(code_length)
{
    for(const char& ch : valid_colors)
    {
        valid_colors_.insert(ch);
        valid_colors_.insert(toupper(ch));
    }
}


BWResult MastermindLogic::evaluateGuess(string guess, string code) const
{
    int blacks = 0, whites = 0;
    int n = code.size();
    int i;

    map<char, int> color_counts;
    vector<bool> marked(n, false);
    for(i = 0; i < n; i++)
        color_counts[code[i]] += 1;

    for(i = 0; i < n; i++)
    {
        if(guess[i] == code[i])
        {
            blacks++;
            marked[i] = true;
            color_counts[code[i]] -= 1;
        }
    }

    for(i = 0; i < n; i++)
    {
        char ch = guess[i];
        if(color_counts[ch] > 0 && !marked[i])
        {
            whites++;
            color_counts[ch] -= 1;
        }
    }

    return {blacks, whites};
}

bool MastermindLogic::inputIsValid(string guess) const
{
    if(guess.length() != code_length_)
        return false;

    for(const char& ch : guess)
        if(valid_colors_.count(ch) == 0)
            return false;

    return true;
}
