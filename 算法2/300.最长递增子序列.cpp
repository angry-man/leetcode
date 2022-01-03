/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.size()<2)
            return nums.size();
        vector<int> dp(nums.size(),1);
        int max_len = 0;
        for(int i = 1;i < nums.size();i++)
        {
            int max_j = 0;
            for(int j = 0;j < i;j++)
            {
                if(nums[j] < nums[i])
                    max_j = max(max_j,dp[j]);
            }
            dp[i] = max_j + 1;
            max_len = max(max_len,dp[i]);
        }
        return max_len;
    }
};
// @lc code=end

