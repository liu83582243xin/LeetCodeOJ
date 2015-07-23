/*************************************************************************
	> File Name: NumberOf1Bits.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月07日 星期日 19时46分34秒
 ************************************************************************/

#include<iostream>
#include<cstdint>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while(n>0)
        {
            if(n%2 == 1)
            {
                ++count;
            }
            n /=2;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(11) << endl;
}
