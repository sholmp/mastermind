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
    switch(state_)
    {
    case State::INIT:
        attempts_ = 5;
        latest_result_ = BWresult(-1,-1);
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
    {
        if(attempts_ == 0)
        {
            state_ = State::ROUND_OVER;
            cout << "No more attempts left. The code was " <<  code_ << "\n";
            break;
        }
        cout << ">";
        string guess = code_breaker_->makeGuess(latest_result_);

        if(guessIsValid(guess, valid_colors_, code_length_))
        {
            latest_result_ = evaluateGuess(guess, code_);

            if(latest_result_.blacks == code_length_)
            {
                cout << code_breaker_->getName() << " guessed the secret code (" << code_ << ")\n";
                state_ = State::ROUND_OVER;
                break;
            }
            cout << "Blacks: " << latest_result_.blacks << "\n";
            cout << "Whites: " << latest_result_.whites << "\n";
            code_maker_->addToScore(10);
            attempts_--;
        }
        else
            cout << "Invalid guess, please try again\n";
        break;
    }
    default:
        break;
    case State::ROUND_OVER:
        cout << code_maker_->getName() << " has " << code_maker_->getScore() << " points.\n";
        cout << code_breaker_->getName() << " has " << code_breaker_->getScore() << " points.\n";
        cout << "Continue [y/n]?\n";
        string answer;
        cin >> answer;
        if(answer == "y")
        {
            state_ = State::INIT;
            swap(code_maker_, code_breaker_);
        }
        else
            state_ = State::GAME_OVER;

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

