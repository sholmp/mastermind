#include "mastermindgame.hpp"

//#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

MastermindGame::MastermindGame(string valid_colors, int code_length):
    valid_colors_(valid_colors),
    code_length_(code_length),
    mastermind_logic_(MastermindLogic(valid_colors, code_length))
{

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

        cout << "Please enter the secret code:\n";
        state_ = State::INPUT_CODE;
        break;

    case State::INPUT_CODE:
        cout << ">";
        cin >> code_;

        if( mastermind_logic_.inputIsValid(code_) )
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

        if( mastermind_logic_.inputIsValid(input_guess) )
        {
            BWResult result = mastermind_logic_.evaluateGuess(input_guess, code_);

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

