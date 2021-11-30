/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(int i = 0;i<target+1;i++)
            for(auto num : nums)
                if(num <= i && dp[i - num] < INT_MAX - dp[i])
                    dp[i] += dp[i - num];
        return dp.back();
    }
};
// @lc code=end

