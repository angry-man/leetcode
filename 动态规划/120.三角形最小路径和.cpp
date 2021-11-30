/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        if(n==1)
            return triangle[0][0];
        int min_path = 1000000;
        for(int i = 1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if(j == i)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
                if(i==n-1)
                    min_path = min(min_path,triangle[i][j]);
            }
        }
        return min_path;
    }
};
// @lc code=end

