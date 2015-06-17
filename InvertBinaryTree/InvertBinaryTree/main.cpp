//
//  main.cpp
//  InvertBinaryTree
//
//  Created by 刘相鑫 on 15/6/17.
//  Copyright (c) 2015年 lxyzk. All rights reserved.
//

#include <iostream>

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
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root)
        {
            return NULL;
        }
        
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        return root;
    }
};
int main(int argc, const char * argv[]) {
    return 0;
}
