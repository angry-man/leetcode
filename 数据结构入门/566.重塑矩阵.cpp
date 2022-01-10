/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c)
            return mat;
        vector<vector<int>> result(r,vector<int>(c,0));
        int x = 0;
        int y = 0;
        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++)
            {
                if(y == n)
                {
                    x++;
                    y = 0;
                }
                result[i][j] = mat[x][y++];
            }
        return result;
    }
};
// @lc code=end

