#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(!l1)
        {
            return l2;
        }

        if(!l2)
        {
            return l1;
        }

        ListNode *current= NULL;
        ListNode * p1 = l1;
        ListNode * p2 = l2;

        if(l1->val < l2->val)
        {
             current= l1;
             p1 = p1->next;
        }
        else
        {
            current= l2;
            p2 = p2->next;
        }

        ListNode *head = current;

        while(p1 && p2)
        {
             if(p1->val < p2->val)
             {
                 current->next = p1;
                 p1 = p1->next;
             }
             else
             {
                  current->next = p2;
                  p2 = p2->next;
             }
        }

        ListNode * p = p1?p1:(p2?p2:NULL);
        current->next = p;

        return head;
    }
};
