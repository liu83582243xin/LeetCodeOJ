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
        void traversal(TreeNode * root, vector<int> & nodes)
        {
            if(!root)
            {
                return;
            }

            if(root->left)
            {
                traversal(root->left,nodes);
            }

            nodes.push_back(root->val);

            if(root->right)
            {
                traversal(root->right,nodes);
            }
        }

        vector<int> inorderTraversal(TreeNode * root)
        {
            vector<int> nodes;

            traversal(root,nodes);

            return nodes;
        }
};

int main()
{
     cout << "Hello World" << endl;
}
