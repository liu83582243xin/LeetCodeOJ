#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
    public:
        int sumOfAq(int a1,int q,int n)
        {
            return a1 * (1 - pow(q,n)) / (1 - q);
        }

        int numTrees(int n)
        {
            if(n == 1)
                return 1;
            if(n < 1)
                return 0;

            return pow(2,n-1) + sumOfAq(1, 4, n - 2) ;
        }
};

int main()
{
    int n;
    Solution s;
    while(cin >> n)
    {
        cout << s.numTrees(n) << endl;
    }
}
