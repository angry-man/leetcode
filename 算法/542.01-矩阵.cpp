/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        vector<vector<int>> dist(m,vector<int>(n));
        vector<vector<int>> seen(m,vector<int>(n));
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(mat[i][j] == 0)
                {
                    q.emplace(i,j);
                    seen[i][j] = 1;
                }
        
        while(!q.empty())
        {
            auto[i,j] = q.front();
            q.pop();
            for(int k = 0;k<4;k++)
            {
                int ni = i + dirs[k][0];
                int nj = j + dirs[k][1];
                if(ni>=0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj])
                {
                    q.emplace(ni,nj);
                    dist[ni][nj] = dist[i][j] + 1;
                    seen[ni][nj] = 1;
                }
            }
        }
        return dist;
    }
};
// @lc code=end

