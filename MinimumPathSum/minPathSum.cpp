#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        if(!m)
        {
            return 0;
        }
        int n = grid[0].size();
        int sums[m][n] = {0};
        for(int i = 0;i < m; ++i)
        {
            vector<int> sum;
            for(int j = 0;j < n; ++j)
            {
                if(!i)
                {
                    if(!j)
                    {
                        sums[i][j] = grid[0][0];
                    }
                    else
                    {
                        sums[i][j] = sums[i][j-1] + grid[i][j];
                    }
                }
                else if(!j)
                {
                    sums[i][j] = grid[i][j] + sums[i-1][j];
                }
                else
                {
                    sums[i][j] = min(sums[i-1][j],sums[i][j-1]) + grid[i][j];
                }
            }
        }
        
        return sums[m-1][n-1];
    }
};