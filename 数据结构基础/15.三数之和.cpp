/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.size() < 3)
            return vector<vector<int>>();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i = 0;i < nums.size() - 2;i++)
        {
            if(i == 0 || nums[i] != nums[i-1])
            {
                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right)
                {
                    if(nums[left] + nums[right] == -nums[i])
                    {
                        result.emplace_back(vector<int>{nums[left],nums[right],nums[i]});
                        right--;
                        left++;
                        while(right >= 0 && nums[right] == nums[right+1])
                            right--;
                        while(left < nums.size() && nums[left] == nums[left-1])
                            left++;
                    }
                    else if(nums[left] + nums[right] > -nums[i])
                        right--;
                    else
                        left++;
                }
            }          
        }
        return result;
    }
};
// @lc code=end

