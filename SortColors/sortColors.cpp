#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int size = nums.size();

        if(!size)
        {
            return;
        }

        int colorArray[3] = {0};
        for(int i = 0;i < size; ++i)
        {
            ++colorArray[nums[i]];
        }

        for(int i = 0; i < 3; ++i)
        {
            cout << colorArray[i] << endl;
        }

        int k = 0;
        for(int i = 1; i <= 3; ++i)
        {
            for(int j = 0;j < colorArray[i]; ++j)
            {
                nums[k++] = i;
            }
        }
    }
};

int main()
{
     vector<int> v {0,1,2,1,2,0};
     Solution s;
     s.sortColors(v);
}
