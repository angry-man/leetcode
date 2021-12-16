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
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int first = 0;first < n;first++)
        {
            if(first==0 || nums[first] != nums[first-1])
            {
                int third = n - 1;
                for(int second = first+1;second < n;second++)
                {
                    if(second == first+1 || nums[second] != nums[second-1])
                    {
                        while(nums[first] + nums[second] + nums[third] > 0 && second<third)
                            third--;
                        if(second == third)
                                break;
                        if(nums[first] + nums[second] + nums[third] == 0)
                        {
                            result.push_back({nums[first],nums[second],nums[third]});
                        }
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

