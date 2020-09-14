#include <iostream>
#include "mastermind.hpp"
#include <string.h>
#include <set>

using namespace  std;

uint attempts = 3;
uint code_length = 4;
set<char> valid_colors = {'r', 'g', 'b', 'y', 'p', 'm'};
int player1score = 0;

enum class State
{
    INIT, INPUT_CODE, INPUT_GUESS, GAME_OVER
};


int main()
{
    State state = State::INIT;
    string code;
    string guess;
    while(true)
    {
        switch(state)
        {
        case State::INIT:
            cout << "Please enter the secret code:" << endl;
            state = State::INPUT_CODE;
            break;
        case State::INPUT_CODE:
            cout << ">";
            cin >> code;

            if(codeIsValid(code, valid_colors, code_length))
            {
                state = State::INPUT_GUESS;
                cout << "Please enter your guess:\n";
            }
            else
                cout << "Invalid code, please try again\n";
            break;

        case State::INPUT_GUESS:
            if(attempts == 0)
            {
                state = State::GAME_OVER;
                break;
            }
            cout << ">";
            cin >> guess;

            if(codeIsValid(guess, valid_colors, code_length))
            {
                BWResult result = compareInputToCode(guess, code);

                if(result == BWResult{4,0})
                {
                    cout << "Congratulations you guessed the secret code\n";
                    state = State::GAME_OVER;
                    break;
                }
                cout << "Blacks: " << result.blacks << endl;
                cout << "Whites: " << result.whites << endl;
                attempts--;
            }
            else
                cout << "Invalid guess, please try again\n";
            break;

        case State::GAME_OVER:
            cout << "Game over!!!" << endl;
            break;

        default:
            cout << "In default state" << endl;
            break;
        }

        State s = State::INPUT_CODE;


    }
    //    cout << s;

    return 0;
}


/*
bool isValidCode(string code)
{

}

string getSecretCode(set<char> available_colors)
{
    string code;
    cout << "Please enter the secret code: ";
    cin >> code;

    if(code.length() < code_length)
        throw("Inputted code is too short");
    else if(code.length() > code_length)
        throw("Inputted code is too long");

    for(int i = 0; i < code_length; i++)
    {
        if(available_colors.count(code[i]) == 0)
            throw("Inputted code contains non valid colors");
    }

    return code;
}


int main(int argc, char* argv[])
{

    string code;
    try
    {
        code = getSecretCode({'r','g','b'});
    }
    catch(const char* error)
    {
        cout << error << endl;
    }
    cout << code;

    int attempts = 5;
    string guess;
    cout << "Please enter your guess: " << endl;
    while(attempts)
    {
        cout << ">";
        cin >> guess;
        cout << endl;

        pair<int, int> result = compareInputToCode(code, guess);
        int num_blacks = result.first;
        int num_whites = result.second;

        cout << "Blacks: " << num_blacks << endl;
        cout << "Whites: " << num_whites << endl;

        attempts--;
    }

    return 0;
}
*/
