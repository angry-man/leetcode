/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        return max_element(nums.begin(),nums.end()) - nums.begin();
    }
};
// @lc code=end

