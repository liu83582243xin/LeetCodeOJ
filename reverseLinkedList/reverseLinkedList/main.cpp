//
//  main.cpp
//  reverseLinkedList
//
//  Created by 刘相鑫 on 15/6/3.
//  Copyright (c) 2015年 lxyzk. All rights reserved.
//

#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL)
    {
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p = NULL;
        ListNode* q = NULL;
        while(head)
        {
            q = new ListNode(head ->val);
            q->next = p;
            p = q;
            head=head->next;
        }
        return q;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head = new ListNode(1);
    ListNode* p = new ListNode(10);
    ListNode* p2 = new ListNode(20);
    head->next = p;
    p->next = p2;
    p2->next = NULL;
    
    Solution s;
    ListNode* reListNode = s.reverseList(head);
    
    while(head)
    {
        cout<<head->val<<endl;
        head=head->next;
    }
    while(reListNode)
    {
        cout<<reListNode->val<<endl;
        reListNode = reListNode->next;
    }
    return 0;
}
