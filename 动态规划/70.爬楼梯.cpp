/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) 
    {
        if(n<=3)
            return n;
        int a = 1;
        int b = 2;
        int c = 3;
        for(int i=3;i<n;i++)
        {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};
// @lc code=end

