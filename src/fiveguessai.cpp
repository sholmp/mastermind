#include "fiveguessai.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;


FiveGuessAI::FiveGuessAI(const std::string& name, const string &valid_colors, int code_length):
   valid_colors_(valid_colors), code_length_(code_length)
{
    name_ = name;
    getAllPossibleCombinations(possible_guesses_, valid_colors_, code_length_, "");
    active_set_ = possible_guesses_;
    first_guess_ = getOptimalGuess();
}

std::string FiveGuessAI::makeCode()
{
    return makeRandomCode(valid_colors_, code_length_);
}

std::string FiveGuessAI::makeGuess(const BWresult& latest_result)
{
    string guess;
    if(latest_result == BWresult(-1,-1))
    {
        active_set_ = possible_guesses_;
        guess = first_guess_;
    }
    else
    {
        eraseCombinationsNotMatchingResult(active_set_, latest_guess_, latest_result);
        guess = getOptimalGuess();
    }

    cout << guess << "\n"; //To beautify the console output from statemachine

    latest_guess_ = guess;
    return guess;
}


string FiveGuessAI::getOptimalGuess()
{
    if(active_set_.size() == 1)
        return *active_set_.begin();

    string optimal_guess;
    int min_max = 100000; //pow(valid_colors_.length(), code_length_); //1296 for 6 colors and length 4.

    for(const string& g : possible_guesses_)
    {
        vector<vector<int>> bw_table(code_length_ + 1, vector<int>(code_length_ + 1)); //add 1 because of zero indexing,
                                                                                       //and whole range[0-code_len] is needed
        for(const string& s : active_set_)
        {
            BWresult result = evaluateGuess(g, s);
            bw_table[result.blacks][result.whites] += 1;
        }

        int max = findMaxInBWTable(bw_table);
        if(max < min_max)
        {
            min_max = max;
            optimal_guess = g;
        }
    }

    return optimal_guess;
}

int FiveGuessAI::findMaxInBWTable(const std::vector<std::vector<int>>& table)
{
    int max_value = 0;
    for(const vector<int>& row : table)
    {
        int row_max = *max_element(row.begin(), row.end());
        max_value = max(row_max, max_value);
    }
    return max_value;
}

