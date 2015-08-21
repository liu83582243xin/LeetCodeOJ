//
//  main.cpp
//  singleNumber
//
//  Created by 刘相鑫 on 15/7/11.
//  Copyright (c) 2015年 lxyzk. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> & nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            auto ite = s.find(nums[i]);
            if (ite == s.end()) {
                s.insert(nums[i]);
            }
            else
            {
                s.erase(ite);
            }
        }
        
        auto ite = s.begin();
        return *ite;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    Solution s;
    cout << s.singleNumber(v)<<endl;
    return 0;
}
