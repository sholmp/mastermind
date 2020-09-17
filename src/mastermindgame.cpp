#include "mastermindgame.hpp"

#include <vector>
#include <map>
#include <iostream>

using namespace std;

MastermindGame::MastermindGame(string valid_colors, int code_length):
    valid_colors_(valid_colors),
    code_length_(code_length)
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
    string guess;
    switch(state_)
    {
    case State::INIT:
        cout << "Please enter the secret code:\n";
        state_ = State::INPUT_CODE;
        break;

    case State::INPUT_CODE:
        cout << ">";
        cin >> code_;

        if(codeIsValid(code_, valid_colors_, code_length_))
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
        cin >> guess;

        if(guessIsValid(guess, valid_colors_, code_length_))
        {
            BWresult result = evaluateGuess(guess, code_);

            if(result.blacks == code_length_)
            {
                cout << "Congratulations you guessed the secret code\n";
                state_ = State::GAME_OVER;
                break;
            }
            cout << "Blacks: " << result.blacks << "\n";
            cout << "Whites: " << result.whites << "\n";
            attempts_--;
        }
        else
            cout << "Invalid guess, please try again\n";
        break;

    case State::GAME_OVER:
        cout << "Game over!!!\n";
        exit(0);
        break;

    }
}

