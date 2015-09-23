#include <iostream>
#include <vector>

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        if(!nums.size())
        {
            return -1;
        }

        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;

        while(nums[left] >= nums[right] && left < right)
        {
            middle = (left + right) / 2;

            if(nums[middle] < nums[left])
            {
                left = left + 1;
                right = middle;
            }
            else if(nums[middle] > nums[left])
            {
                 left = middle + 1;
            }
            else
            {
                left++;
            }
        }

        return nums[left];
    }
};
