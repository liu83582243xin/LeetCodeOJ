#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode * left;
    TreeLinkNode * right;
    TreeLinkNode * next;

    TreeLinkNode(int x) : val(x),left(NULL),right(NULL),next(NULL)
    {

    }
};

class Solution
{
    public:

        void connectNext(queue<TreeLinkNode*> & q)
        {
            if(q.empty())
            {
                return;
            }

            queue<TreeLinkNode *> qq;

            TreeLinkNode * curr = NULL;
            TreeLinkNode * next = NULL;

            while(q.size() > 1)
            {
                curr = q.front();
                q.pop();

                next = q.front();
                curr->next = next;

                if(curr->left && curr->right)
                {
                    qq.push(curr->left);
                    qq.push(curr->right);
                }
            }

            if(!q.empty())
            {
                 curr = q.front();
                 q.pop();

                 if(curr->left && curr->right)
                 {
                     qq.push(curr->left);
                     qq.push(curr->right);
                 }
            }

            connectNext(qq);
        }

        void connect(TreeLinkNode * root)
        {
            if(!root)
            {
                return;
            }

            queue<TreeLinkNode*> q;

            q.push(root);

            connectNext(q);
        }
};

int main()
{
    TreeLinkNode * root = new TreeLinkNode(0);
    Solution solution;
    solution.connect(root);
}
