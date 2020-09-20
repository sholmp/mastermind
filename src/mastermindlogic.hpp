#ifndef MASTERMINDLOGIC_HPP
#define MASTERMINDLOGIC_HPP

#include <string>
#include <list>


struct BWresult;

BWresult evaluateGuess(std::string guess, std::string code);
bool codeIsValid(std::string code, std::string valid_colors, int code_length);
bool guessIsValid(std::string guess, std::string valid_colors, int code_length);

void getAllPossibleCombinations(std::list<std::string>& combos, const std::string& colors,
                                int code_length, std::string current_string);

void eraseCombinationsNotMatchingResult(std::list<std::string>& combinations,
                                        const std::string& guess, const BWresult& result);

std::string makeRandomCode(const std::string valid_colors, int code_length);


struct BWresult
{
    int blacks;
    int whites;

    BWresult(){}
    BWresult(int b, int w) : blacks(b), whites(w){}
    bool operator==(const BWresult& rhs) const {
        return blacks == rhs.blacks && whites == rhs.whites;
    }
    bool operator !=(const BWresult& rhs) const {
        return !(*this == rhs);
    }
};

#endif
