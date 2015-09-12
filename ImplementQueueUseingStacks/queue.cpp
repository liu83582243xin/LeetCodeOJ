#include <iostream>
#include <stack>

using namespace std;

class Queue {
protected:
    stack<int> s1,s2;

    void moveElement(stack<int>& source,stack<int>& target)
    {
        if(source.empty())
        {
            return;
        }

        while(!source.empty())
        {
            target.push(source.top());
            source.pop();
        }
    }

public:
    // Push element x to the back of queue.
    void push(int x)
    {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void)
    {
        if(this->empty())
        {
            return;
        }

        if(s2.empty())
        {
            this->moveElement(s1,s2);
        }

        s2.pop();
    }

    // Get the front element.
    int peek(void)
    {
        if(this->empty())
        {
             return -1;
        }

        if(s2.empty())
        {
            this->moveElement(s1,s2);
        }

        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return s1.empty() && s2.empty();
    }
};
