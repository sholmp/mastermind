#include "mastermindlogic.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

BWresult evaluateGuess(string guess, string code)
{
    int blacks = 0, whites = 0;
    int n = code.size();

    map<char, int> color_counts;
    vector<bool> already_used(n, false);

    for(const char& ch: code)
        color_counts[ch] += 1;

    for(int i = 0; i < n; i++)
    {
        if(guess[i] == code[i])
        {
            blacks++;
            already_used[i] = true;
            color_counts[code[i]] -= 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        char ch = guess[i];
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

void getAllPossibleCombinations(std::list<string> &combos, const string &colors, int code_length, string current_string)
{
    if(code_length == 0)
    {
        combos.push_back(current_string);
        return;
    }
    for(const char& ch: colors)
        getAllPossibleCombinations(combos, colors, code_length - 1, current_string + ch);

}


void eraseCombinationsNotMatchingResult(list<string>& combinations, const string& guess, const BWresult& result)
{
    auto comp = [&guess, &result](const string& s)
    {
        return evaluateGuess(guess, s) != result;
    };

    combinations.erase(remove_if(combinations.begin(), combinations.end(), comp), combinations.end());
}

string makeRandomCode(const string valid_colors, int code_length)
{
    string code;
    for(int i = 0; i < code_length; i++)
        code += valid_colors[rand() % valid_colors.length()];

    return code;
}


