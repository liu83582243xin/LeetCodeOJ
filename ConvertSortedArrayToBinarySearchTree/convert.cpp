#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode * toBST(vector<int>& nums, int left, int right)
    {
        if(left > right)
        {
            return NULL;
        }

        double m = (left + right) / 2.0;
        int middle = (int)ceil(m);

        TreeNode * node = new TreeNode(nums[middle]);
        node->left = toBST(nums,left,middle - 1);
        node->right = toBST(nums,middle + 1,right);

        return node;
    }

    TreeNode * sortedArrayToBST(vector<int>& nums)
    {
        if(!nums.size())
        {
             return NULL;
        }

        return toBST(nums,0,nums.size());
    }
};

int main()
{
     cout << "Hello World!" << endl;
}
