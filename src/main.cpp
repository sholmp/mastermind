#include <iostream>
#include "mastermindlogic.hpp"
#include <vector>
#include <algorithm>
#include <ctime>
#include "fiveguessai.hpp"
#include "humanplayer.hpp"

//void eraseCombinationsNotMatchingResult(std::list<std::string>& S, const std::string& guess, const BWresult& result);
//std::string getOptimalGuess(const std::list<std::string>& S, const std::list<std::string>& combinations, int code_length);
//int findMaxInBWTable(const std::vector<std::vector<int>>& table);


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
    string code = "4321";
    int code_length = 4;
    string colors = "123456";

    BWresult latest_result(-1,-1);

    FiveGuessAI fg(colors, code_length);
    string guess = fg.makeGuess(latest_result);
    cout << guess << endl;

    latest_result = evaluateGuess(guess, code);
    guess = fg.makeGuess(latest_result);
    cout << guess << endl;

    latest_result = evaluateGuess(guess, code);
    guess = fg.makeGuess(latest_result);
    cout << guess << endl;

    latest_result = evaluateGuess(guess, code);
    guess = fg.makeGuess(latest_result);
    cout << guess << endl;

    latest_result = evaluateGuess(guess, code);
    guess = fg.makeGuess(latest_result);
    cout << guess << endl;

    return 0;
}




