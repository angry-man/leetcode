/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        if(nums.size() == 1)
            return nums[0]==target ? 0:-1;
        int rotate = 0;
        while(rotate<nums.size()-1 && nums[rotate] < nums[rotate + 1])
            rotate++;
        int low, high;
        if(rotate == nums.size() - 1)
        {
            low = 0;
            high = rotate;
        }
        else
        {
            if(target >= nums[0])
            {
                low = 0;
                high = rotate;
            }
            else
            {
                low = rotate + 1;
                high = nums.size() - 1;
            }
        }       
        int mid = (low + high) / 2;
        while(low<=high)
        {
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
            mid = (low + high) / 2;
        }
        return -1;
    }
};
// @lc code=end

