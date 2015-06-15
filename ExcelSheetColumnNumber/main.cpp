#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int number = 0;
        int length = s.length();
        for(int i = 0;i < length;++i)
        {
            int dital = s.at(i) - 'A' + 1;
            double weight = pow(26.0,length - 1.0 -i);
            number += dital * weight;
        }
        return number;
    }
};
int main()
{
    string lable = "AB";
    Solution s;
    cout<<s.titleToNumber(lable)<<endl;;
    return 0;
}
