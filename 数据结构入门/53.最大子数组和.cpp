/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums.back();
        int cur_dp = nums[0];
        int next_dp = 0;
        int max_dp = cur_dp;
        for(int i = 1;i<nums.size();i++)
        {        
            next_dp = max(nums[i],cur_dp + nums[i]);
            cur_dp = next_dp;
            max_dp = max(max_dp,next_dp);
        }
        return max_dp;
    }
};
// @lc code=end

