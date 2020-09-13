#include <iostream>
#include "mastermind.hpp"
#include <string.h>

using namespace  std;


void printHelpInformation()
{
    cout << "Usage: ";
}

int main(int argc, char* argv[])
{

    string colors = "RGBYPM"; //Red, green, blue, yellow, purple, magenta

    //Initialize game:
    if(argc > 2)
    {
        if(strcmp(argv[1], "-h")) //print help information
        {
            cout << "Mastermind can be configured in the following way:\n";
            cout << "-h: print help information\n";
            cout << "--colors: [string]. E.g. '--colors: ABCDE'  will set the allowable color primitives to 'ABCDE'";
            cout << "--codelength: [int]. E.g. '--columns 5' will set the code length to 5) \n";
            return 0;
        }
    }

    // get secret code
    string code;
    cout << "Please enter the secret code: ";
    cin >> code;

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
