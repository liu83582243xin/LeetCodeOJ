#include <iostream>

using namespace std;

class Solution
{
    public:
        int addDigits(int num)
        {
            if(num == 0)
                return 0;

            int result = num % 9;

            if(result == 0)
            {
                return 9;
            }

            return result;
        }
};

int main()
{
    int num = 0;
    Solution s;
    while(cin >> num)
    {
       cout << s.addDigits(num) << endl;
    }

    return 0;
}
