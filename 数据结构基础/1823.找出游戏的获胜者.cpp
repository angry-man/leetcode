/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        int pre_dp = 1;
        for(int i = 2; i <= n; i++) 
        {
            pre_dp = ((pre_dp + k - 1) % i) + 1;
        }
        return pre_dp;
    }
};
// @lc code=end

