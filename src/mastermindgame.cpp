#include "mastermindgame.hpp"

#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
//#include <cstdio> //to_upper

using namespace std;

MastermindGame::MastermindGame()
{

}

MastermindGame::MastermindGame(string valid_colors, int code_length): code_length_(code_length)
{
    valid_colors_.clear();
    for(const char& c : valid_colors)
    {
        valid_colors_.insert(c);
        valid_colors_.insert(toupper(c));
    }
}

void MastermindGame::run()
{
    while(true)
    {
        fsm();
    }
}

void MastermindGame::fsm()
{
    string input_guess;
    switch(state_)
    {
    case State::INIT:
        cout << "Please enter the secret code:" << endl;
        state_ = State::INPUT_CODE;
        break;
    case State::INPUT_CODE:
        cout << ">";
        cin >> code_;

        if(inputIsValid(code_))
        {
            state_ = State::INPUT_GUESS;
            cout << "Please enter your guess:\n";
        }
        else
            cout << "Invalid code, please try again\n";
        break;

    case State::INPUT_GUESS:
        if(attempts_ == 0)
        {
            state_ = State::GAME_OVER;
            break;
        }
        cout << ">";
        cin >> input_guess;

        if(inputIsValid(input_guess))
        {
            BWResult result = compareInputToCode(input_guess, code_);

            if(result.blacks == code_length_)
            {
                cout << "Congratulations you guessed the secret code\n";
                state_ = State::GAME_OVER;
                break;
            }
            cout << "Blacks: " << result.blacks << endl;
            cout << "Whites: " << result.whites << endl;
            attempts_--;
        }
        else
            cout << "Invalid guess, please try again\n";
        break;

    case State::GAME_OVER:
        cout << "Game over!!!" << endl;
        break;

    }
}


BWResult MastermindGame::compareInputToCode(string input, string code)
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
        if(input[i] == code[i])
        {
            blacks++;
            marked[i] = true;
            color_counts[code[i]] -= 1;
        }
    }

    for(i = 0; i < n; i++)
    {
        char ch = input[i];
        if(color_counts[ch] > 0 && !marked[i])
        {
            whites++;
            color_counts[ch] -= 1;
        }
    }


    return {blacks, whites};
}


bool MastermindGame::inputIsValid(string input)
{
    if(input.length() != code_length_)
        return false;

//    auto lambda = [this](const char& c){
//        return this->valid_colors_.count(c) != 0;};

//    return all_of(input.begin(), input.end(), lambda); //Returns true if lambda evaluates to true for every element

    for(const char& ch : input)
        if(valid_colors_.count(ch) == 0)
            return false;

    return true;

}

