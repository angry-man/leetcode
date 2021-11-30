/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        if (n==0)
            return 0;
        
        vector<int> leftmax(n,0);//leftmax[i]表示i左边的数中最大的值
        vector<int> rightmax(n,0);//rightmax[i]表示i右边的数中最大的值
        leftmax[0] = height[0];
        rightmax[n-1] = height[n-1];
        for(int i = 1;i<n;i++)
            leftmax[i] = max(leftmax[i-1],height[i]);
        for(int i = n-2;i>=0;i--)
            rightmax[i] = max(rightmax[i+1],height[i]);
        
        int sum_rain = 0;
        for(int i = 0;i<n;i++)
            sum_rain += min(leftmax[i],rightmax[i]) - height[i];
        
        return sum_rain;
    }
};
// @lc code=end

