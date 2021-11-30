/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> P(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        
        vector<vector<int>> answer(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int ik = max(i-k,0),jk = max(j-k,0);
                int ik1 = min(i+k+1,m),jk1 = min(j+k+1,n);
                answer[i][j] = P[ik1][jk1] - P[ik][jk1] - P[ik1][jk] + P[ik][jk];
            }
        return answer;
    }
};
// @lc code=end

