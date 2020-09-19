#include <iostream>
#include "mastermindlogic.hpp"
#include "combotree.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include "fiveguessai.hpp"

void eraseCombinationsNotMatchingResult(std::list<std::string>& S, const std::string& guess, const BWresult& result);
std::string getOptimalGuess(const std::list<std::string>& S, const std::list<std::string>& combinations, int code_length);
int findMaxInBWTable(const std::vector<std::vector<int>>& table);


clock_t START_TIMER;

clock_t tic()
{
    return START_TIMER = clock();
}

void toc(clock_t start = START_TIMER)
{
    std::cout
        << "Elapsed time: "
        << (clock() - start) / (double)CLOCKS_PER_SEC << "s"
        << std::endl;
}

#define debug(x) std::cout << #x << ": " << x << endl;


using namespace std;

int main()
{
    srand(time(NULL));
    string code = "1234";
    int code_length = 4;
    string colors = "123456";
    ComboTree tree(colors, code_length);

    list<string> combos = tree.getCombinations();
    list<string> S = combos;

//    debug(combos.size());

//    string optimal_guess = getOptimalGuess(S, combos, code_length);

//    BWresult result = evaluateGuess(optimal_guess, code);
//    eraseCombinationsNotMatchingResult(S, optimal_guess, result);

//    debug(S.size());


    MastermindGame game(colors, code_length);
    FiveGuessAI fiveGuesser(&game);
//    string optimal_guess = fiveGuesser.makeGuess();

//    cout << optimal_guess << endl;

    return 0;
}


//min max algorithm (5 guess)
//S: the set of codes that could still be the actual secret code.
//combinations: The set of possible guesses.
std::string getOptimalGuess(const std::list<std::string>& S, const std::list<std::string>& combinations, int code_length)
{
    string optimal_guess;
    int min_max = 100000;
    string best_guess;

    for(const string& g : combinations)
    {
        vector<vector<int>> bw_table(code_length + 1, vector<int>(code_length + 1)); //add 1 because of zero indexing,
                                                                                     //and whole range[0-code_len] is needed
        for(const string& s : S)
        {
            BWresult result = evaluateGuess(g, s);
            bw_table[result.blacks][result.whites] += 1;
        }

        int max = findMaxInBWTable(bw_table);
        if(max < min_max)
        {
            min_max = max;
            best_guess = g;
        }
    }

    return best_guess;
}

//guess has been compared to the code, and produced result
void eraseCombinationsNotMatchingResult(std::list<std::string>& S, const std::string& guess, const BWresult& result)
{
    static auto comp = [result, guess](string s)
    {
        return evaluateGuess(guess, s) != result;
    };

    S.erase(remove_if(S.begin(), S.end(), comp), S.end());
}


int findMaxInBWTable(const std::vector<std::vector<int>>& table)
{
    int max_value = 0;
    for(const vector<int>& row : table)
    {
        int row_max = *max_element(row.begin(), row.end());
        max_value = max(row_max, max_value);
    }
    return max_value;
}


