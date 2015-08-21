/*************************************************************************
	> File Name: ReverseBits.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月07日 星期日 20时11分32秒
 ************************************************************************/
#include<iostream>
#include<cstdint>
#include<cmath>
using namespace std;
class Solution {
    public:
    void showBits(int* bits)
    {
        for(int i = 0;i < 32; ++i)
        {
            cout<<bits[i]<<" ";
        }
        cout<<endl;
    }
    uint32_t reverseBits(uint32_t n) 
    {
        int bits[32] = {0};
        for(int i = 0;n>0;++i)
        {
            bits[i] = n%2;
            n/=2;
        }

        //this->showBits(bits);

        uint32_t newInt = 0;
        for(int i = 0;i < 32;++i)
        {
            if(bits[i])
            {
                newInt+=pow(2,31-i);
            }
        }

        return newInt;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseBits(43261596)<<endl;
}
