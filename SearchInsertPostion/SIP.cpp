#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> & nums,int target)
    {
        int left = -1,right = nums.size();
        int middle = 0;
        while(left + 1 < right)
        {
            middle = (left + right) / 2;
            if(target <= nums[middle])
            {
                right = middle;
            }
            else
            {
                left = middle;
            }
        }

        return right;
    }
};

int main()
{
     vector<int> nums;
     int target = 0;
     int size = 0;
     cin >> size >> target;
     for(int i = 0;i < size; ++i)
     {
         cin >> nums[i];
     }

     Solution s;
     cout << s.searchInsert(nums,target) << endl;
}
