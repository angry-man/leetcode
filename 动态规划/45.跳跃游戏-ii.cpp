/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        vector<int>dp(nums.size(),0);
        for(int i=1;i<nums.size();i++)
        {
            int minjump=10000;
            for(int j=0;j<i;j++)
            {   
                if((j+nums[j]>=i)&&dp[j]<minjump)
                    minjump = dp[j];
            }
            dp[i] = minjump + 1;
        }
        return dp.back();
    }
};
// @lc code=end

