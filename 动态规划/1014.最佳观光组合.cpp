/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        if(values.size()==2)
            return values[0]+values[1]-1;
        int pre_dp = values[0]+values[1]-1;
        int max_dp = pre_dp;
        for(int i = 2;i<values.size();i++)
        {
            pre_dp = max(pre_dp-values[i-1],values[i-1])+values[i]-1;
            max_dp = max(pre_dp,max_dp);
        }
        return max_dp;
    }
};
// @lc code=end

