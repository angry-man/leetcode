/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] == target)
            {
                int temp_mid = mid;
                result[0] = mid;
                result[1] = mid;
                while(--temp_mid>=0 && nums[temp_mid] == target)
                    result[0] = temp_mid;
                while(++mid<nums.size() && nums[mid] == target)
                    result[1] = mid;
                return result;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }        
        return result;
    }
};
// @lc code=end

