#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.length() != t.length())
        {
            return false;
        }

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s == t)
        {
            return true;
        }
        return false;

    }
};

int main()
{
     string s("hello");
     string t = "helol";

     Solution solution;
     cout << solution.isAnagram(s,t) << endl;
}
