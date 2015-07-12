#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x),left(NULL),right(NULL)
    {

    }
};

class Solution
{
    public:
        void traversal(TreeNode * root, vector<int>& v)
        {
            if(!root)
            {
                return;
            }

            v.push_back(root->val);

            traversal(root->left,v);
            traversal(root->right,v);
        }

        vector<int> preorderTraversal(TreeNode * root)
        {
             vector<int> nodes;
             traversal(root,nodes);
             return nodes;
        }
};

int main()
{
     cout << "Hello World!" << endl;
}
