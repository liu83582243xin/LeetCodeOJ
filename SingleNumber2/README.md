解法如下:
大体思路就是分别统计每个位的1出现的次数，出现的不是三的整数倍的为那个没有出现三次的数的位.
one的每一位代表出现次数为1的位
two的每一位代表出现次数为2的位
three用来对出现三次的位进行清零 相当于取模
one的某一位为1，two的这一位也是1就相当于这一位出现了3次  就可以进行取模清零
```
class Solution
{
public:
    int singleNumber(vector<int> & nums)
    {
        int one=0,two=0,three=0;
        for(int i = 0;i < nums.size(); ++i)
        {
            two |= one&nums[i];
            one ^= nums[i];
            three = one&two;

            one &= ~three;
            two &= ~three;
        }

        return one | two;
    }
};
```
