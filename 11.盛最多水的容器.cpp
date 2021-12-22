/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;
        int m = 0;
        while(left < right)
        {
            m = max(m,min(height[left],height[right]) * (right - left));
            if(height[left] > height[right])
                right--;
            else
                left++;
        }
        return m;
    }
};
// @lc code=end

