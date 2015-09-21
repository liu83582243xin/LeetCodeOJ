#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int size = prices.size();
        if(size < 1)
        {
            return 0;
        }

        int minPrice = prices[0];
        int mprofit = 0, currentProfit = 0;
        for(int i = 1;i < size; ++i)
        {
            if(prices[i] < minPrice)
            {
                minPrice =prices[i];
            }
            else
            {
                currentProfit = prices[i] - minPrice;
                mprofit = mprofit > currentProfit?mprofit:currentProfit;
            }
        }

        return mprofit;
    }
};
