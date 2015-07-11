There is a 20ms solution as follows:

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
```
*the ^ operator is XOR*

For example:

`1^1=0`

`0^0=0`

`1^0=1`

`0^1=1`
