#Two solutions

###There is an easy iterative solution and a recursive solution as follows:

####iterative solution

```c++
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* pre = root;
        TreeLinkNode* cur = NULL;
        while (pre) {
            cur = pre;
            while (cur && cur -> left) {
                cur -> left -> next = cur -> right;
                if (cur -> next)
                    cur -> right -> next = cur -> next -> left;
                cur = cur -> next;
            }
            pre = pre -> left;
        }
    }
};
```

###recursive solution
```c++
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root -> left) {
            root -> left -> next = root -> right;
            if (root -> next)
                root -> right -> next = root -> next -> left;
        }
        connect(root -> left);
        connect(root -> right);
    }
};
```
