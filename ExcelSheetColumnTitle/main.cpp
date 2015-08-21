#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;
class Solution
{
public:
    string convertToTitle(int n)
    {
        vector<char> title;
        int dital = 0;
        while(n>0)
        {
            dital = n % 26;
            if(dital == 0)
                --n;
            title.push_back((26 + dital - 1) % 26 + 'A');
            n /= 26;
        }

        string lable(title.rbegin(),title.rend());
        return lable;
    }
};
int main()
{
    int number = 53;
    Solution s;
    cout<< s.convertToTitle(number)<<endl;
    return 0;
}
