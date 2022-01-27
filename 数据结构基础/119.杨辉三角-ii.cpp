/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> pre_dp(1,1);
        if(rowIndex==0)
            return pre_dp;
        for(int i = 1;i<=rowIndex;i++)
        {
            vector<int> cur_dp;
            cur_dp.emplace_back(1);
            for(int j = 1;j<i;j++)
            {
                cur_dp.emplace_back(pre_dp[j-1] + pre_dp[j]);
            }
            cur_dp.emplace_back(1);
            pre_dp = cur_dp;
        }
        return pre_dp;
    }
};
// @lc code=end

