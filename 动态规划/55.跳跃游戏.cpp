/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        if(nums.size()==1)
            return true;
        int max_index=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(i<=max_index&&max_index<i+nums[i])
                max_index = i+nums[i];
        }
        if(max_index>=nums.size()-1)
            return true;
        return false;
    }
};
// @lc code=end

