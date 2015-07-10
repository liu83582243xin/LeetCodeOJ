#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

class Solution
{
public :
	int max_Depth = 0;
	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	int maxDepth(TreeNode * root)
	{
		if (!root)
		{
			return 0;
		}

		if (root->left == NULL && root->right == NULL)
		{
			return 1;
		}

		return max(maxDepth(root->left), maxDepth(root->right))+1;
	}

};

int main()
{
	TreeNode * root = new TreeNode(0);
	TreeNode * right = new TreeNode(1);
	root->right = right;

	Solution solution;
	cout << solution.maxDepth(root) << endl;
}