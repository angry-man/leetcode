/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) 
    {
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 1;
        int max_dp = 0;
        for(int i = 3;i<n+1;i++)
        {
            for(int j = 1;j<i;j++)
            {
                int temp = (dp[i-j]<i-j ? i-j:dp[i-j])*(dp[j]<j ? j:dp[j]);
                max_dp = max(max_dp,temp);
            }
            dp[i] = max_dp;
        }
        return dp.back();
    }
};
// @lc code=end

