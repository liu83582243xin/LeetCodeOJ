#include <iostream>
#include <vector>
#include <iterator>
#include <map>

using namespace std;
class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int majority = nums[0];
        int majority_count = 1;

        map<int,int> nums_count;
        nums_count.insert(pair<int,int>(nums[0],1));

        for(int i = 1; i < nums.size(); ++i)
        {
            auto curNum = nums_count.find(nums[i]);
            if(curNum == nums_count.end())
            {
                nums_count.insert(pair<int,int>(nums[i],1));
            }
            else
            {
                ++curNum->second;
                if(curNum->second >= majority_count)
                {
                    majority = curNum->first;
                    majority_count = curNum->second;
                }
            }
        }
        return majority;
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);

    Solution s;
    cout << s.majorityElement(nums) << endl;
    return 0;
}
