#include "mastermind.hpp"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

BWResult compareInputToCode(string input, string code)
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

bool codeIsValid(string code, std::set<char> valid_colors, int code_length)
{
    if(code.length() != code_length)
        return false;

    for(int i = 0; i < code_length; i++)
    {
        if(valid_colors.count(code[i]) == 0)
            return false;
    }
    return true;
}


//bool codeIsValid(std::string code) {
//  if (code.length() != 4)
//    return false;
//  static const std::set<char> valid_colors = { 'R', 'B', 'G', 'Y' };
//  return std::all_of(code.begin(), code.end(),
//                     [](char c) { return valid_colors.count(c) != 0; });
//}
