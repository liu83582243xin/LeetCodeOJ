//
//  main.cpp
//  Pascal'sTriangle
//
//  Created by 刘相鑫 on 15/6/15.
//  Copyright (c) 2015年 lxyzk. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> generate(int numRows)
    {
        
        vector<vector<int>> vv;
        vector<int> v;
        if(numRows == 0)
            return vv;
        for(int i = 0;i <numRows;++i)
        {
            if(i == 0)
            {
                v.push_back(1);
                vv.push_back(v);
            }
            else
            {
                v.clear();
                v.push_back(1);
                for(int j = 1;j < vv[i-1].size();++j)
                {
                    v.push_back(vv[i-1][j-1] + vv[i-1][j]);
                }
                v.push_back(1);
                vv.push_back(v);
            }
        }
        return vv;
    }
};
int main(int argc, const char * argv[])
{
    int numRows = 6;
    Solution s;
    vector<vector<int>> v = s.generate(numRows);
    for(int i = 0; i < v.size();++i)
    {
        for(int j = 0;j < v[i].size();++j)
        {
            cout << v[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}
