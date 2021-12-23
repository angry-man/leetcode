// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem209.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();        
        int min_len = INT_MAX;
        for(int left = 0;left < n;left++)
        {
            int right = left;
            int sum = 0;
            while(sum < target && right < n)
            {
                sum += nums[right++];
            }
            if(sum >= target)
                min_len = min(min_len,right - left);
        }
        return min_len == INT_MAX ? 0:min_len;
    }
};
// @lc code=end

