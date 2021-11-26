/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        if(n==1)
            return matrix[0][0];    
        int min_path = 1000000;
        for(int i=1;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(j==0)
                    matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j+1]);
                else if(j==n-1)
                    matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j-1]);
                else
                    matrix[i][j] += min(matrix[i-1][j-1],
                                    min(matrix[i-1][j],matrix[i-1][j+1]));
                if(i==n-1)
                    min_path = min(min_path,matrix[i][j]);
            }
        return min_path;
    }
};
// @lc code=end

