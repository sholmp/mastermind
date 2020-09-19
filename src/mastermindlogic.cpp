#include "mastermindlogic.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <unordered_set>

using namespace std;

BWresult evaluateGuess(string input, string code)
{
    int blacks = 0, whites = 0;
    int n = code.size();

    map<char, int> color_counts;
    vector<bool> already_used(n, false);

    for(const char& ch: code)
        color_counts[ch] += 1;

    for(int i = 0; i < n; i++)
    {
        if(input[i] == code[i])
        {
            blacks++;
            already_used[i] = true;
            color_counts[code[i]] -= 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        char ch = input[i];
        if(color_counts[ch] > 0 && !already_used[i])
        {
            whites++;
            color_counts[ch] -= 1;
        }
    }

    return {blacks, whites};
}


bool codeIsValid(string code, string valid_colors, int code_length)
{
    if(code.length() != code_length)
        return false;

    unordered_set<char> valid_colors_set;
    for(const char& ch : valid_colors)
        valid_colors_set.insert(ch);

    for(const char& ch : code)
        if(valid_colors_set.count(ch) == 0)
            return false;

    return true;
}


bool guessIsValid(string guess, string valid_colors, int code_length)
{
    return codeIsValid(guess, valid_colors, code_length);
}
