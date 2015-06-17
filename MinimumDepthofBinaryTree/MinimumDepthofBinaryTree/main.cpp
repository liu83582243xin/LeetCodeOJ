//
//  main.cpp
//  MinimumDepthofBinaryTree
//
//  Created by 刘相鑫 on 15/6/17.
//  Copyright (c) 2015年 lxyzk. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    int mi(int a, int b)
    {
        if(a == 0)
            return b;
        if(b == 0)
            return a;
        return min(a,b);
    }
    int _minDepth(TreeNode *root, int depth)
    {
        if(!root)
        {
            return 0;
        }
        ++depth;
        if(!root->left && !root->right)
            return depth;
        return mi(_minDepth(root->left, depth),_minDepth(root->right, depth));
    }
    int minDepth(TreeNode* root)
    {
        return _minDepth(root, 0);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *left1= new TreeNode(1);
    root->left = left1;
    
    Solution solution;
    cout<<solution.minDepth(root)<<endl;
    return 0;
}
