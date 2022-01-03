/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),1);
        vector<int> cn(nums.size(),1);

        int maxLen = 0;
        int ans = 0;
        for(int i = 0;i < nums.size();i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(nums[j] < nums[i])
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cn[i] = cn[j];
                    }
                    else if(dp[j] + 1 == dp[i])
                        cn[i] += cn[j];
                }
            }
            if (dp[i] > maxLen) 
            {
                maxLen = dp[i];
                ans = cn[i]; 
            }
            else if (dp[i] == maxLen) 
                ans += cn[i];
        }
        return ans;
    }
};
// @lc code=end

