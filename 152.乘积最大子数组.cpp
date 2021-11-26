// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem152.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        int pre_max = nums[0];
        int pre_min = nums[0];
        int now_max = 0;
        int now_min = 0;
        int max_sub = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                now_min = min(pre_max*nums[i],nums[i]);
                now_max = max(pre_min*nums[i],nums[i]);
            }
            else
            {
                now_max = max(pre_max*nums[i],nums[i]);
                now_min = min(pre_min*nums[i],nums[i]);
            }
            max_sub = max(max(now_max,pre_max),max_sub);
            pre_max = now_max;
            pre_min = now_min;           
        }
        return max_sub;
    }
};
// @lc code=end

