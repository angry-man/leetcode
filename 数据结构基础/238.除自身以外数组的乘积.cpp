/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
            return nums;
        vector<int> acc_front(n,0);
        vector<int> acc_back(n,0);
        acc_front[0] = nums[0];
        acc_back[n - 1] = nums.back();
        for(int i = 1;i < n;++i)
        {
            acc_front[i] = acc_front[i - 1] * nums[i];
            acc_back[n - 1 - i] = acc_back[n - i] * nums[n - 1 - i];
        }
        
        vector<int> output(n,0);
        output[0] = acc_back[1];
        output[n - 1] = acc_front[n - 2];
        for(int i = 1;i < n - 1;++i)
        {
            output[i] = acc_front[i - 1] * acc_back[i + 1];
        }
        return output;
    }
};
// @lc code=end

