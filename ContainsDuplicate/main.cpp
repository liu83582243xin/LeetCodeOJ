#include <iostream>
#include <set>
#include <iterator>
#include <vector>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        set<int> s;
        for(int i = 0;i < nums.size();++i)
        {
            auto value = s.find(nums[i]);
            if(value == s.end())
            {
                s.insert(nums[i]);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    Solution s;
    cout<< s.containsDuplicate(v) << endl;
    return 0;
}
