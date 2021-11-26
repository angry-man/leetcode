/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size()<2)
            return 0;
        if(prices.size()==2)
            return max(prices[1]-prices[0],0);
        int pre_dp0 = max(0,prices[1]-prices[0]);
        int pre_pre_dp0 = 0;
        int pre_dp1 = max(-prices[0],-prices[1]);
        int pre_pre_dp1 = -prices[0];

        int max_dp = 0;
        for(int i=2;i<prices.size();i++)
        {
            int cur_dp0 = max(pre_dp0,pre_dp1+prices[i]);
            int cur_dp1 = max(pre_dp1,pre_pre_dp0-prices[i]);
            pre_pre_dp0 = pre_dp0;
            pre_pre_dp1 = pre_dp1;
            pre_dp0 = cur_dp0;
            pre_dp1 = cur_dp1;
            max_dp = max(cur_dp0,max_dp);
        }
        return max_dp;
    }
};
// @lc code=end

