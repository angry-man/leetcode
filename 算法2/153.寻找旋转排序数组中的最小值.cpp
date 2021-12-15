/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        //sort(nums.begin(),nums.end());
        //return nums[0];
        return *min_element(nums.begin(),nums.end());
    }
};
// @lc code=end

