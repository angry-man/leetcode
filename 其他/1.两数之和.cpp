/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        auto NUMS = nums;
        sort(NUMS.begin(),NUMS.end());
        int left = 0;
        int right = NUMS.size() - 1;
        while(left < right)
        {
            if(NUMS[left] + NUMS[right] == target)
                break;
            else if(NUMS[left] + NUMS[right] > target)
                right--;
            else
                left++;
        }
        int a = find(nums.begin(),nums.end(),NUMS[left]) - nums.begin();
        if(nums[a] == target - nums[a])//如果遇到相同的找一种运算保证远行后绝对和原来不同
            nums[a] = (target + 1) - nums[a];
        int b = find(nums.begin(),nums.end(),NUMS[right]) - nums.begin();

        return {a,b};
    }
};
// @lc code=end

