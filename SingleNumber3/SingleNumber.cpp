#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> & nums)
    {
        int XOROfNums = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            XOROfNums ^= nums[i];
        }

        int positionOf1 = 0;
        while(!(XOROfNums & 1))
        {
            ++positionOf1;
            XOROfNums >>= 1;
        }

        int XOROfNums0 = 0, XOROfNums1 = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if((nums[i] >> positionOf1) & 1)
            {
                 XOROfNums1 ^= nums[i];
            }
            else
            {
                XOROfNums0 ^= nums[i];
            }
        }

        vector<int> result;
        result.push_back(XOROfNums0);
        result.push_back(XOROfNums1);

        return result;
    }
};

int main()
{
     Solution s;
     vector<int> v {1,2,1,3,2,5};
     vector<int> vv = s.singleNumber(v);

     for(int i = 0; i < vv.size(); ++i)
     {
         cout << vv[i] << endl;
     }

}
