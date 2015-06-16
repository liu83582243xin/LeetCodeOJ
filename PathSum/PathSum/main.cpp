//
//  main.cpp
//  PathSum
//
//  Created by 刘相鑫 on 15/6/16.
//  Copyright (c) 2015年 lxyzk. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL)
    {
    }
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(!root)
        {
            return false;
        }
        cout << root->val << endl;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        if(root->val == sum &&!left && !right)
        {
            return true;
        }
        
        return (left && hasPathSum(left, sum-root->val)) || (right && hasPathSum(right, sum-root->val));
    }
};
int main(int argc, const char * argv[]) {
    TreeNode root(5);
    TreeNode node1(4);
    TreeNode node2(8);
    TreeNode node3(11);
    TreeNode node4(13);
    TreeNode node5(4);
    TreeNode node6(7);
    TreeNode node7(2);
    TreeNode node8(1);
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node3.left = &node6;
    node3.right = &node7;
    node2.left = &node4;
    node2.right = &node5;
    node5.right = &node8;
    
    TreeNode root2(-2);
    root2.right = new TreeNode(-3);
    
    Solution s;
    cout<<s.hasPathSum(&root2, -5)<<endl;
    return 0;
}
