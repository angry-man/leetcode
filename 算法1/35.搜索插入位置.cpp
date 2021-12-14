/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {   
        int len = nums.size() - 1;
        int low = 0;
        int high = len;
        while(low <=high) 
         {
            int mid = low + (high - low) / 2;
            if(nums[mid] < target) 
                low = mid + 1;
            else if(nums[mid] == target) 
                return mid;
            else 
                high = mid - 1;
        }
        return low;
    }
};
// @lc code=end

