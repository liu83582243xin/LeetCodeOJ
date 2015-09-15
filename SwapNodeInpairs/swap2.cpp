#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL) {}
};

class Solution
{
public:
    ListNode* swap(ListNode *next,ListNode *prev)
    {

        if(next==NULL)
           return prev;
        else if(next->next==NULL)
        {
          next->next=prev;
          prev->next=NULL;
          return next;
        }
        ListNode* nextNode=next->next;
        next->next=prev;
        prev->next=swap(nextNode->next,nextNode);
        return next;
    }

    ListNode* swapPairs(ListNode* head) {
    if(head==NULL||head->next==NULL)
        return head;
    else
    {
        ListNode* newHead=head;
        newHead=newHead->next;
        swap(head->next,head);
        return newHead;
    }
}
};
