#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Solution
{
public:
    int StringToInt(string s)
    {
        stringstream ss;
        ss<<s;
        int number;
        ss>>number;
        return number;
    }
    int compareVersion(string version1, string version2)
    {
        if(version1 == version2)
            return 0;

        int l_v1 = -1,l_v2 = -1;
        int r_v1 = 0,r_v2 = 0;
        int n_v1 = 0,n_v2 = 0;
        while(l_v1 < version1.length() && l_v2 < version2.length())
        {
            r_v1 = version1.find(".",l_v1 + 1);
            r_v2 = version2.find(".",l_v2 + 1);

            cout<<r_v1<<","<<r_v2<<endl;

            if(r_v1 == version1.npos)
            {
                r_v1 = version1.length() - 1;
            }
            if(r_v2 == version2.npos)
            {
                r_v2 = version2.length() - 1;
            }

//            n_v1 = this->StringToInt(version1.substr(l_v1,r_v1 - l_v1));
//            n_v2 = this->StringToInt(version2.substr(l_v2,r_v2 - l_v2));

            cout<<"n_v1"<<n_v1<<endl;
            cout<<"n_v2"<<n_v2<<endl;

            l_v1 = r_v1 + 1;
            l_v2 = r_v2 + 1;

//            if(n_v1 > n_v2)
//                return 1;
//            if(n_v1 < n_v2)
//                return -1;
        }
    }
};
int main()
{
    string version1 = "0.1";
    string version2 = "1.2";
    Solution s;
    cout<<s.compareVersion(version2,version1)<<endl;
    return 0;
}
