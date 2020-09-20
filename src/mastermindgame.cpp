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
    while(state_ != State::GAME_OVER)
    {
        statemachine();
    }
}

void MastermindGame::statemachine()
{
    string guess;
    switch(state_)
    {
    case State::INIT:
        cout << code_maker_->getName() << ", please enter the secret code:\n";
        state_ = State::INPUT_CODE;
        break;

    case State::INPUT_CODE:
        cout << ">";
        code_ = code_maker_->makeCode();

        if(codeIsValid(code_, valid_colors_, code_length_))
        {
            state_ = State::INPUT_GUESS;
            cout << code_breaker_->getName() << ", please enter your guess:\n";
        }
        else
            cout << "Invalid code, please try again\n";
        break;

    case State::INPUT_GUESS:
        if(attempts_ == 0)
        {
            state_ = State::GAME_OVER;
            cout << "You used all your attempts\n";
            break;
        }
        cout << ">";
        guess = code_breaker_->makeGuess(BWresult(-1,-1));

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
    }
}

void MastermindGame::setPlayers(MastermindPlayer *code_maker, MastermindPlayer *code_breaker)
{
    code_maker_ = code_maker;
    code_breaker_ = code_breaker;
}

int MastermindGame::getCodeLength() const
{
    return code_length_;
}

string MastermindGame::getValidColors() const
{
    return valid_colors_;
}

