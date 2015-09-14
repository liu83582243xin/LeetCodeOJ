#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int size = nums.size();

        if(size == 0)
        {
            return 0;
        }

        int k = 0;
        if(size % 2)
        {
            k = (size-1) / 2;
        }

        int sum = (size-1) * (size / 2) + k;
        int psum = 0;
        for(int i = 0; i < size; ++i)
        {
            psum += nums[i];
        }

        int difference = psum - sum;

        if(!difference)
        {
             return size;
        }
        return size - difference;
    }
};

int main()
{
     vector<int> v {0,1,2};
     Solution s;
     cout << s.missingNumber(v) << endl;
}
