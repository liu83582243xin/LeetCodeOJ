//
//  main.cpp
//  Min Stack
//
//  Created by 刘相鑫 on 15/6/14.
//  Copyright (c) 2015年 lxyzk. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

struct MinStackNode
{
    int val;
    MinStackNode* next;
    MinStackNode* pre;
    MinStackNode* currMin;
    
    MinStackNode(int value):val(value),next(nullptr),pre(nullptr)
    {
        
    }
};
class MinStack {
public:
    MinStackNode* head;
    MinStackNode* tral;
    set<MinStackNode> s;
    
    MinStack()
    {
        this->head = new MinStackNode(0);
        this->tral = new MinStackNode(0);
        tral->pre = head;
        head->next =tral;
        
    }
    
    void push(int x)
    {
        MinStackNode* curr = new MinStackNode(x);
        tral->pre->next = curr;
        curr->pre = tral->pre;
        curr->next = tral;
        tral->pre = curr;
       
        if(curr->pre == head)
        {
            curr->currMin = curr;
        }
        else
        {
            curr->currMin = curr->val < curr->pre->currMin->val ? curr : curr->pre->currMin;
        }
    }
    
    void pop()
    {
        MinStackNode* curr = tral->pre;
        curr->pre->next = tral;
        tral->pre = curr->pre;
        delete curr;
    }
    
    int top()
    {
        return tral->pre->val;
    }
    
    int getMin()
    {
        return this->tral->pre->currMin->val;
    }
};
int main(int argc, const char * argv[])
{
    MinStack ms;
    ms.push(-2),ms.push(0),ms.push(-1);
    MinStackNode* q = ms.head;
    while(q!=ms.tral)
    {
        cout<<q->val<<" "<<q->currMin->val<<endl;
        q = q->next;
    }
    
    cout<<ms.getMin()<<","<<ms.top()<<",";
    ms.pop();
    cout<<ms.getMin()<<endl;
    return 0;
}
