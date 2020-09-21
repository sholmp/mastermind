#ifndef FIVEGUESSAI_HPP
#define FIVEGUESSAI_HPP

#include "mastermindgame.hpp"
#include "mastermindlogic.hpp"
#include "mastermindplayer.hpp"
#include <list>
#include <string>
#include <vector>

class FiveGuessAI : public MastermindPlayer
{
public:
    FiveGuessAI(const std::string& name, const std::string& valid_colors, int code_length);

    std::string makeGuess(const BWresult &latest_result) override;
    std::string makeCode() override;

private:
    std::string getOptimalGuess();
    int findMaxInBWTable(const std::vector<std::vector<int>>& table);

private:
    std::list<std::string> active_set_;
    std::list<std::string> possible_guesses_;
    std::string first_guess_;
    std::string latest_guess_;
    MastermindGame* game_ptr_;

    int code_length_;
    std::string valid_colors_;

};

#endif // FIVEGUESSAI_HPP
