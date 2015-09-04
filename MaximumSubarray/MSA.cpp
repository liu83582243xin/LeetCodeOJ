#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int max(int a,int b)
    {
        if(a > b)
            return a;
        return b;
    }

    int maxSubArray(vector<int>& nums)
    {
        int maxSum = nums[0];
        int currentMaxSum = maxSum;
        for(int i = 1; i < nums.size();++i)
        {
            currentMaxSum = max(nums[i],currentMaxSum + nums[i]);
            maxSum = max(maxSum,currentMaxSum);
        }

        return maxSum;
    }
};

int main()
{
     vector<int> v {-2,1,-3,4,-1,2,1,-5,4};
     Solution s;
     cout << s.maxSubArray(v) << endl;
}
