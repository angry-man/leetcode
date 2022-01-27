/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<m;i++)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(matrix[i][j]==target)
                    return true;
                else if(matrix[i][j]>target)
                    continue;
                else
                    break;
            }
        }
        return false;
    }
};
// @lc code=end

