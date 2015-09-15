#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL) {}
};

class Solution {
public:
    void swap(ListNode **p,ListNode **q)
    {
        (*p)->next = (*q)->next;
        (*q)->next = (*p);
    }

    ListNode* swapPairs(ListNode* head)
    {
        if(!head)
        {
            return NULL;
        }

        ListNode *swapedHead = head;
        ListNode *lastPointer = swapedHead;
        ListNode *currentPointer = head;
        ListNode *prePointer = head->next;

        if(prePointer)
        {
             this->swap(&currentPointer,&prePointer);
             lastPointer = currentPointer;
             swapedHead = prePointer;

             currentPointer = currentPointer->next;
             if(currentPointer)
             {
                 prePointer = currentPointer->next;
             }
        }

        while(currentPointer && prePointer)
        {
             this->swap(&currentPointer,&prePointer);
             lastPointer->next = prePointer;
             lastPointer = currentPointer;

             currentPointer = currentPointer->next;
             if(currentPointer)
             {
                 prePointer = currentPointer->next;
             }
        }

        return swapedHead;
    }
};

