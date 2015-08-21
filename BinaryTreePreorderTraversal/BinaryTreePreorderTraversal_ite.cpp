#include <iostream>
#include <vector>
#include <stack>

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
        vector<int> preorderTraversal(TreeNode * root)
        {
            vector<int> nodes;
            stack<TreeNode*> s;

            if(!root)
            {
                 return nodes;
            }


            while(root)
            {
                nodes.push_back(root->val);

                if(root->left)
                {
                     s.push(root);
                     root = root->left;
                }
                else if(root->right)
                {
                    root = root->right;
                }
                else
                {
                        if(s.empty())
                        {
                             break;
                        }
                    root = s.top();
                    s.pop();
                    while(!root->right)
                    {
                         root = s.top();
                         s.pop();
                    }
                    root = root->right;
                }
            }
            return nodes;
        }
};

int main()
{
     cout << "Hello World!" << endl;
}
