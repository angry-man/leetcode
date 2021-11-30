/*
 * @lc app=leetcode.cn id=1567 lang=cpp
 *
 * [1567] 乘积为正数的最长子数组长度
 */

// @lc code=start
class Solution {
public:
    int getMaxLen(vector<int>& nums) 
    {
        if(nums.size()==1&&nums[0]>0)
            return 1;
        
        int pre_positive_len = 0;
        int pre_negitive_len = 0;
        int cur_positive_len = 0;
        int cur_negitive_len = 0;
        int max_len = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                cur_positive_len = pre_positive_len + 1;
                if(pre_negitive_len > 0)
                    cur_negitive_len = pre_negitive_len + 1;
                else 
                    cur_negitive_len = 0;
            }
            else if(nums[i]<0)
            {
                if(pre_negitive_len > 0)
                    cur_positive_len = pre_negitive_len + 1;
                else
                    cur_positive_len = 0;
                cur_negitive_len = pre_positive_len + 1;
            }
            else
            {
                cur_positive_len = 0;
                cur_negitive_len = 0;
            }
            max_len = max(cur_positive_len,max_len);
            pre_positive_len = cur_positive_len;
            pre_negitive_len = cur_negitive_len;
        }
        return max_len;
    }
};
// @lc code=end

