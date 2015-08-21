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
        void deleteNode(ListNode * node)
        {
            if(!node)
            {
                return;
            }

            ListNode * temp = node->next;
            node->val = node->next->val;
            node->next = node->next->next;
            delete temp;
        }
};

int main()
{
     cout << "Hello World!" << endl;
     return 0;
}
