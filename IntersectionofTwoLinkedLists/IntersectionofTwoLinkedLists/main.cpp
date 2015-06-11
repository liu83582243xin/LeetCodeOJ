//
//  main.cpp
//  IntersectionofTwoLinkedLists
//
//  Created by 刘相鑫 on 15/6/11.
//  Copyright (c) 2015年 lxyzk. All rights reserved.
//

#include <iostream>

using namespace std;
struct ListNode
{
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lengthA = 0,lengthB = 0;
        int gap = 0;
        ListNode* phA = headA;
        ListNode* phB = headB;
        
        while(phA)
        {
            ++lengthA;
            phA = phA->next;
        }
        
        while(phB)
        {
            ++lengthB;
            phB = phB->next;
        }
        
        if(lengthA > lengthB)
        {
            gap = lengthA - lengthB;
            phA = headA;
            phB = headB;
        }
        else
        {
            gap = lengthB - lengthA;
            phA = headB;
            phB = headA;
        }
        
        cout<<"gap "<<gap<<endl;
        
        while(gap > 0)
        {
            phA = phA->next;
            --gap;
        }
        
        while(phA && phB)
        {
            if(phA == phB)
            {
                return phA;
            }
            phA = phA->next;
            phB = phB->next;
        }
        
        return NULL;
    }
};
int main(int argc, const char * argv[]) {
    ListNode headA(1);
    ListNode headB(1);
    ListNode a1(1);
    ListNode a2(1);
    ListNode b1(1);
    ListNode b2(1);
    ListNode b3(1);
    ListNode c1(100);
    ListNode c2(1);
    ListNode c3(1);
    headA.next = &a1;
    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    c3.next = NULL;
    headB.next = &b1;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    
    cout<<"headA"<<endl;
    ListNode* pha = &headA;
    ListNode* phb = &headB;
    while(pha)
    {
        cout<<pha->val<<" ";
        pha = pha->next;
    }
    cout<<endl;
    cout<<"headB"<<endl;
    while(phb)
    {
        cout<<phb->val<<" ";
        phb = phb->next;
    }
    cout<<endl;
    Solution s;
    ListNode* ints = s.getIntersectionNode(NULL,&headB);
    if(!ints)
    {
        cout<<"NULL"<<endl;
        return 0;
    }
    cout<<"ints"<<ints->val<<endl;
    return 0;
}
