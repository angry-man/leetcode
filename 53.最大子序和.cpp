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
        if(nums.size()==1)
            return nums[0];
        int pre = nums[0];
        int max_sub = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            pre = max(pre + nums[i],nums[i]);
            max_sub = max(pre,max_sub);
        }
        return max_sub;
    }
};
// @lc code=end

