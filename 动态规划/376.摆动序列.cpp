// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem376.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<2)
            return n;
        int pre_up = 1;
        int pre_down = 1;
        int cur_up, cur_down;
        for(int i = 1;i < n;i++)
        {  
            if(nums[i]>nums[i-1])
            {
                cur_up = max(pre_up,pre_down+1);
                cur_down = pre_down;
            }
            else if(nums[i] == nums[i-1])
            {
                cur_up = pre_up;
                cur_down = pre_down;
            }
            else
            {
                cur_up = pre_up;
                cur_down = max(pre_up+1,pre_down);
            }
            pre_down = cur_down;
            pre_up = cur_up;
        }
        return max(cur_down,cur_up);
    }
};
// @lc code=end
