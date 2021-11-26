// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem918.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums,bool minORman) 
    {
        if(nums.size()==1)
            return nums[0];
        int pre = nums[0];
        int sub_sum = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            if(minORman)
            {
                pre = max(pre + nums[i],nums[i]);
                sub_sum = max(pre,sub_sum);
            }
            else
            {
                pre = min(pre + nums[i],nums[i]);
                sub_sum = min(pre,sub_sum);
            }
            
        }
        return sub_sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        int sum_nums = 0;
        for(int i=0;i<nums.size();i++)
            sum_nums += nums[i];

        int max_sum = maxSubArray(nums,true);

        int back = nums.back();
        nums.pop_back();
        int min_sum1 = maxSubArray(nums,false);
        nums.emplace_back(back);
        nums.erase(nums.begin());
        int min_sum2 = maxSubArray(nums,false);

        int min_sum = min(min_sum1,min_sum2);
        
        
        int sub_sum = max(max_sum,sum_nums-min_sum);
        return sub_sum;
    }
};
// @lc code=end

