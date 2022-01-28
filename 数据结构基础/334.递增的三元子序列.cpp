/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int n = nums.size();
        if(n < 3)
            return false;
        int first = nums.front();
        int second = INT_MAX;
        for(auto num : nums)
        {
            if(num > second)
                return true;
            else if(num > first)
                second = num;
            else
                first = num;
        }   
        return false;
    }
};
// @lc code=end

