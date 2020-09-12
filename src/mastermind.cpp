#include "mastermind.hpp"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int add(int a, int b)
{
	return a +b;
}


pair<int, int> compareInputToCode(string input, string code)
{
    int blacks = 0, whites = 0;

    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == code[i])
        {
            blacks++;
            input.erase(input.begin() + i);
            code.erase(code.begin() + i);
            i--;
        }
    }

    map<char, int> color_counts;
    for(int i = 0; i < code.size(); i++)
        color_counts[code[i]] += 1;

    for(int i = 0; i < input.size(); i++)
    {
        char ch = input[i];
        if(color_counts[ch])
        {
            whites++;
            color_counts[ch] -= 1;
        }
    }


    return {blacks, whites};
}
