//
//  main.cpp
//  ValidPalindrome
//
//  Created by 刘相鑫 on 15/6/15.
//  Copyright (c) 2015年 lxyzk. All rights reserved.
//

#include <iostream>
//#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        auto length = s.length();
        char s_char[length];
        int j = 0;
        for(auto i = 0;i < length; ++i)
        {
            if(isalnum(s.at(i)))
            {
                s_char[j++] = tolower(s.at(i));
            }
        }
        
        for(auto i = 0;i <= j - 1 - i;++i)
        {
            if(s_char[i] != s_char[j - 1 - i])
                return false;
        }
        return true;
    }
};
int main(int argc, const char * argv[])
{
    string s("race a car");
    Solution solution;
    cout<<solution.isPalindrome(s)<<endl;
    return 0;
}
