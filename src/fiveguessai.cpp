#include "fiveguessai.hpp"
#include <algorithm>
#include <cmath>

using namespace std;


FiveGuessAI::FiveGuessAI(const string &valid_colors, int code_length):
    valid_colors_(valid_colors), code_length_(code_length)
{
    ComboTree tree(valid_colors, code_length);
    possible_guesses_ = tree.getCombinations();
    S_ = possible_guesses_;
    first_guess = getOptimalGuess();
}

FiveGuessAI::FiveGuessAI(MastermindGame *game_ptr):
    game_ptr_(game_ptr)
{
    code_length_ = game_ptr->getCodeLength();
    valid_colors_ = game_ptr->getValidColors();

    ComboTree tree(valid_colors_, code_length_);
    possible_guesses_ = tree.getCombinations();
    S_ = possible_guesses_;
    first_guess = getOptimalGuess();
}

std::string FiveGuessAI::makeCode()
{
    string code;
    for(int i = 0; i < code_length_; i++)
        code += valid_colors_[rand() % valid_colors_.length()];

    return code;
}

std::string FiveGuessAI::makeGuess() //BWresult previous_result?
{
    string guess;

    return getOptimalGuess();
}


string FiveGuessAI::getOptimalGuess()
{
    string optimal_guess;
    int min_max = 100000; //pow(valid_colors_.length(), code_length_); //1296 for 6 colors and length 4.

    for(const string& g : possible_guesses_)
    {
        vector<vector<int>> bw_table(code_length_ + 1, vector<int>(code_length_ + 1)); //add 1 because of zero indexing,
                                                                                       //and whole range[0-code_len] is needed
        for(const string& s : S_)
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

//guess has been compared to the code, and produced result
void FiveGuessAI::eraseCombinationsNotMatchingResult(std::list<std::string>& S, const std::string& guess, const BWresult& result)
{
    static auto comp = [result, guess](string s)
    {
        return evaluateGuess(guess, s) != result;
    };

    S.erase(remove_if(S.begin(), S.end(), comp), S.end());
}

