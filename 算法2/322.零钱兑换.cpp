/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        if(n == 0)
            return -1;
        vector<int> dp(amount+1,0);
        for(int i=1;i<amount+1;i++)
        {
            int min_coin = amount;
            for(int j = 0;j<coins.size();j++)
                if(coins[j] <= i)
                    min_coin = min(min_coin,dp[max(i-coins[j],0)]);
            dp[i] = min_coin + 1;
        }
        return dp.back() > amount ? -1:dp.back();
    }
};
// @lc code=end

