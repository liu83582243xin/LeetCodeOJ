#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int x):val(x),next(NULL) {}
};

class Solution
{
public:
    void swap(ListNode * a, ListNode * b)
    {
        if(a == NULL || b == NULL)
        {
            return;
        }

        if(a->val == b->val)
        {
            return;
        }

        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

    ListNode* deleteDuplicates(ListNode* head)
    {
        if(head == NULL)
        {
            return NULL;
        }

        ListNode * preOfDelNode = head;
        ListNode * currentNode = head->next;
        while(currentNode)
        {
            if(currentNode->val != preOfDelNode->val)
            {
                if(preOfDelNode->next)
                {
                     this->swap(currentNode,preOfDelNode->next);
                     preOfDelNode = preOfDelNode->next;
                }
            }
             currentNode = currentNode->next;
        }

        ListNode * c_preOfDelNode = preOfDelNode->next;
        preOfDelNode -> next = NULL;
        while(c_preOfDelNode)
        {
             ListNode * q = c_preOfDelNode;
             delete q;
             c_preOfDelNode = c_preOfDelNode->next;
        }

        return head;
    }
};
