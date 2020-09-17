#include <iostream>
#include "inputparser.hpp"
#include "mastermindgame.hpp"

using namespace std;

string help_message = "The default code length is 4, with 6 default colors:'r, g, b, y, p, m'\n\n"
                      "The default parameters can be configured in the following way: \n"
                      "--colors: <string> with length [2-8]. E.g. '--colors rgb'\n"
                      "--codelength: <int> with a value in the range [2-8]. E.g. '--length 7'\n";

int main(int argc, char** argv)
{
    string colors = "rgbypm";
    int code_length = 4;

    InputParser parser(argc, argv);
    if(parser.cmdOptionExists("-h"))
    {
        cout << help_message;
        exit(0);
    }

    if(parser.cmdOptionExists("--colors"))
    {
        colors = parser.getCmdOption("--colors");
        if(colors.empty() || colors.length() > MastermindGame::max_colors || colors.length() < 2)
        {
            cout << "Invalid --colors argument";
            exit(0);
        }
    }
    if(parser.cmdOptionExists("--codelength"))
    {
        try //'stoi' throws invalid_argument if specified option is not numeric
        {
            code_length = stoi(parser.getCmdOption("--codelength"));
            if(code_length > MastermindGame::max_code_length || code_length < 2)
                throw(invalid_argument(""));
        }
        catch(invalid_argument e)
        {
            cout << "Invalid --codelength argument\n";
            exit(0);
        }
    }

    MastermindGame game(colors, code_length);

    game.run();

    return 0;
}




