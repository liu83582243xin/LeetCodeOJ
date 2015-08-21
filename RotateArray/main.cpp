#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        if(k%nums.size() == 0)
            return;
        vector<int> c_nums(nums);
        nums.clear();
        int nums_end = c_nums.size() - k%c_nums.size();
        for(int i = nums_end;i < c_nums.size();++i)
        {
            nums.push_back(c_nums[i]);
        }
        for(int i = 0;i < nums_end;++i)
        {
            nums.push_back(c_nums[i]);
        }
    }
};
int main()
{
    vector<int> nums;
    for(int i = 1; i <= 1;++i)
    {

        nums.push_back(i);
    }
    Solution s;
    s.rotate(nums,2);
    for(auto ite = nums.begin();ite != nums.end();++ite)
    {
        cout<<*ite<<" ";
    }
    cout<<endl;
    return 0;
}
