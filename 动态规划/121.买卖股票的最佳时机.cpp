/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size()<2)
            return 0;
        else if(prices.size()==2)
            return max(prices[1]-prices[0],0);
        int pre_dp = prices[1]-prices[0];
        int max_dp = max(pre_dp,0);
        for(int i = 2;i<prices.size();i++)
        {
            pre_dp = max(prices[i] + pre_dp,prices[i]) - prices[i-1];
            max_dp = max(max_dp,pre_dp);
        }
        return max_dp;
    }
};
// @lc code=end

