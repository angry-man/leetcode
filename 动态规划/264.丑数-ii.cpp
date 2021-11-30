// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem264.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int>dp;
        dp.emplace_back(1);
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        for(int i = 1;i<n;i++)
        {
            int temp = min(min(dp[p2]*2,dp[p3]*3),dp[p5]*5);
            if(temp != dp.back())
                dp.emplace_back(temp);
            else
                i--;
            if(temp == dp[p2]*2)
                p2++;
            else if(temp == dp[p3]*3)
                p3++;
            else if(temp == dp[p5]*5)
                p5++;    
        }
        return dp.back();
    }
};
// @lc code=end

