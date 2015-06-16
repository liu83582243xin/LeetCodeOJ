//
//  main.cpp
//  Pascal'sTriangle2
//
//  Created by 刘相鑫 on 15/6/16.
//  Copyright (c) 2015年 lxyzk. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    
    vector<int> generate(int numRows)
    {
        
        vector<vector<int>> vv;
        vector<int> v;
        if(numRows == 0)
        {
            v.push_back(1);
            return v;
        }
        for(int i = 0;i <= numRows;++i)
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
        return vv[numRows];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v = s.generate(0);
    for(int i = 0;i < v.size(); ++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
