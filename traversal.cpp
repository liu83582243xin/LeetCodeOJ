#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct MyTreeNode
{
    TreeNode *treeNode;
    bool isPushed;
    MyTreeNode(TreeNode *node) : treeNode(node), isPushed(false) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> nodes;

        if(!root)
        {
             return nodes;
        }

        stack<MyTreeNode *> s;
        s.push(new MyTreeNode(root));

        while(!s.empty())
        {
             MyTreeNode *node = s.top();
             s.pop();

             if(node->isPushed)
             {
                 nodes.push_back(node->treeNode->val);
             }
             else
             {
                  node->isPushed = true;
                  s.push(node);
                  if(node->treeNode->right)
                  {
                      s.push(new MyTreeNode(node->treeNode->right));
                  }
                  if(node->treeNode->left)
                  {
                       s.push(new MyTreeNode(node->treeNode->left));
                  }
             }
        }

        return nodes;
    }
};
