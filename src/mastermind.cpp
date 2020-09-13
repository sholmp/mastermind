#include "mastermind.hpp"
#include <vector>
#include <map>
#include <iostream>

using namespace std;




pair<int, int> compareInputToCode(string input, string code)
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

//    for(int i = 0; i < input.size(); i++)
//    {
//        if(input[i] == code[i])
//        {
//            blacks++;
//            input.erase(input.begin() + i);
//            code.erase(code.begin() + i);
//            i--;
//        }
//    }
