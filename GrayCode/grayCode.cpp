#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    void computeLastCodes(vector<int>& codes,int n)
    {

        int addNumber = 2 << (n - 2);
        int begin = 0,end = (2 << (n - 1)) - 1;

        while(begin < end)
        {
            codes[end] = codes[begin] + addNumber;
            ++begin;
            --end;
        }
    }

    void computePreCodes(vector<int>& codes,int n)
    {

        if(n == 0)
        {
            codes[0] = 0;
            return;
        }

        if(n == 1)
        {
            codes[0] = 0;
            codes[1] = 1;
            return;
        }

        computePreCodes(codes,n-1);
        computeLastCodes(codes,n);
    }

    vector<int> grayCode(int n) {
        int size =  2 << (n - 1);
        vector<int> codes(size,0);
        computePreCodes(codes,n);
        return codes;
    }
};

int main()
{
     int n = 0;
     cin >> n;
     Solution s;
     vector<int> result =s.grayCode(n);
     for(int i = 0;i < result.size();++i)
     {
          cout << result[i] << " ";
     }
     cout << endl;
}
