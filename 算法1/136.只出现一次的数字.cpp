/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        /*
        if(nums.size() == 1)
            return nums.back();
        sort(nums.begin(),nums.end());
        for(int i = 1;i<nums.size() - 1;i++)
        {
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
                return nums[i];
        }
        return nums[0]==nums[1]?nums.back():nums[0];
        */
        int result = 0;
        for(auto num : nums)
        {
            result ^= num;//^=是异或
        }
        return result;
    }
};
// @lc code=end

