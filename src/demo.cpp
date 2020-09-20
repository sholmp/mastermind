#include <iostream>
#include "mastermindgame.hpp"

#include "humanplayer.hpp"
#include "fiveguessai.hpp"
#include "simpleai.hpp"
#include "cxxopts.hpp"

using namespace std;


int main(int argc, char** argv)
{
    string default_play_mode = "HvH";
    string default_colors = "123456";
    int default_code_length = 4;

    cxxopts::Options options("Mastermind", "");
    options.add_options()
        ("c,colors", "available colors [2-8]", cxxopts::value<string>()->default_value(default_colors))
        ("l,length", "code length [2-8]", cxxopts::value<int>()->default_value(to_string(default_code_length)))
        ("p,play_mode", "HvH: Human versus Human, HvS: Human vs. 'simple AI', Hv5: Human vs '5 guess AI'",
         cxxopts::value<string>()->default_value("HvH"))
        ("h,help", "display help")
    ;

    auto result = options.parse(argc, (const char**&) argv);

    if (result.count("help"))
    {
      std::cout << options.help() << std::endl;
      exit(0);
    }

    string colors = default_colors;
    string play_mode = default_play_mode;
    int code_length = default_code_length;

    if(result.count("colors"))
    {
        colors = result["colors"].as<string>();
        if(colors.length() < 2 || colors.length() > MastermindGame::max_number_of_colors)
        {
            cout << "Invalid --colors argument. Using default value.\n";
            colors = default_colors;
        }
    }

    if(result.count("length"))
    {
        code_length = result["length"].as<int>();
        if(code_length < 2 || code_length > MastermindGame::max_code_length)
        {
            cout << "Invalid --length argument. Using default value.\n";
            code_length = default_code_length;
        }
    }

    MastermindPlayer* code_maker;
    MastermindPlayer* code_breaker;
    if(result.count("play_mode"))
    {
        play_mode = result["play_mode"].as<string>();
        if(play_mode != "HvH" && play_mode != "HvS" && play_mode != "Hv5")
        {
            cout << "Invalid --play_mode argument. Using default value \n";
            play_mode = default_play_mode;
        }
    }
    if(play_mode == "HvS")
    {
        code_maker = new HumanPlayer("Human1");
        code_breaker = new SimpleAI("SimpleAI", colors, code_length);
    }
    else if(play_mode == "Hv5")
    {
        code_maker = new HumanPlayer("Human1");
        code_breaker = new FiveGuessAI("FiveGuessAI", colors, code_length);
    }
    else
    {
        code_maker = new HumanPlayer("Human1");
        code_breaker = new HumanPlayer("Human2");
    }

    cout << "Available colors: " << colors << "\n";
    cout << "Code length: " << code_length << "\n";
    cout << "Play mode: " << play_mode << "\n";

    MastermindGame game(colors, code_length);
    game.setPlayers(code_maker, code_breaker);

    game.run();

    delete code_maker;
    delete code_breaker;

    return 0;
}




