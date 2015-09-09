代码如下：
```c++
class Solution
{
public:
    int min(int a,int b)
    {
        if(a < b)
            return a;
        return b;
    }

    vector<int> product(vector<int> & nums,int n)
    {

        vector<int> results{0,0,0};
        if(!n || !nums.size())
        {
            return results;
        }

        results[2] = 1;
        n = min(n,nums.size());

        for(int i = 0;i < n; ++i)
        {
            if(nums[i] != 0)
            {
                results[2] *= nums[i];
            }
            else
            {
                results[0]++;
            }
        }

        return results;
    }

    vector<int> productExceptSelf(vector<int> & nums)
    {
        vector<int> * products = new vector<int>();

        vector<int> results = product(nums,nums.size());

        if(results[0] > 1)
        {
             results[2] = results[1] = 0;
        }
        else if(results[0] == 0)
        {
             results[1] = results[2];
        }

        for(int i = 0;i < nums.size(); ++i)
        {
            if(nums[i])
            {
             products->push_back(results[1] / nums[i]);
            }
            else
            {
                products->push_back(results[2]);
            }
        }

        return *products;
    }
};
```
其中 `results[0]`代表有几个0，`results[1]`代表所有数相乘的积,`results[2]`代表排除所有零以外的所有数的积
