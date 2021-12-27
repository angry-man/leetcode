/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        if(nums.size()<3)
            return 0;
        if(nums.size()==3 && nums[0]+nums[2]==2*nums[1])
            return 1;
        int pre_dp = 0;       
        int sum_dp = 0;
        for(int i=2;i<nums.size();i++)
        {
            int cur_dp = 0;
            if(2*nums[i-1]==nums[i-2]+nums[i])
                cur_dp = pre_dp + 1;
            sum_dp += cur_dp;
            pre_dp = cur_dp;
        }
        return sum_dp;
    }
};
// @lc code=end

