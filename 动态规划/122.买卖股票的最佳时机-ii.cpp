/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int pre_dp0 = 0;
        int pre_dp1 = -prices[0];
        for(int i=0;i<n;i++)
        {
            int cur_dp0 = max(pre_dp0,pre_dp1+prices[i]);
            int cur_dp1 = max(pre_dp1,pre_dp0-prices[i]);
            pre_dp0 = cur_dp0;
            pre_dp1 = cur_dp1;
        }
        return pre_dp0;
    }
};
// @lc code=end

