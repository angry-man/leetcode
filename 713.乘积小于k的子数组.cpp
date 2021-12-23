/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if(k == 0 || k == 1)
            return 0;
        int count = 0;
        int multi = 1;
        int n = nums.size();
        for(int left = 0,right = 0;right < n;right++)
        {
            multi *= nums[right];
            while(multi >= k && left<=right)
            {
                multi /= nums[left++];
            }
            count += right - left + 1;
        }
        return count;
    }
};
// @lc code=end

