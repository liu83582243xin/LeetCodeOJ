#include <iostream>

using namespace std;

class Solution {
private:
    int paths[101][101];

public:
    int computePaths(int m, int n)
    {

        if(m ==1 || n==1)
        {
            return 1;
        }

        if(!paths[m][n])
        {
            paths[m][n] = computePaths(m-1,n) + computePaths(m,n-1);
        }

        return paths[m][n];
    }

    int uniquePaths(int m, int n)
    {
        if(m == 1 || n==1)
        {
            return 1;
        }
        return computePaths(m-1,n) + computePaths(m,n-1);
    }
};
