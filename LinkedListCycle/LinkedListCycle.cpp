#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int x) : val(x),next(NULL)
    {

    }
};

class Solution
{
    public:
        bool hasCycle(ListNode * head)
        {
            if(!head)
            {
                return false;
            }

            ListNode * mark = new ListNode(0);

            ListNode * curr = head;
            ListNode * next = head->next;
            while(next)
            {
                curr->next = mark;
                if(next == mark)
                {
                    return true;
                }
                curr = next;
                next = curr->next;
            }

            return false;
        }
};

int main()
{
     cout << "Hello World" << endl;
}
