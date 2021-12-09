/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(grid[i][j] == 2)
                    q.emplace(i,j);
        
        int times = 0;
        
        while(!q.empty())
        {
            int num = q.size();
            bool flag = 0;
            for(int k = 0;k<num;k++)
            {
                auto [cur_i,cur_j] = q.front();
                q.pop();               
                for(int i = 0;i<4;i++)
                {
                    int next_i = cur_i + dirs[i][0];
                    int next_j = cur_j + dirs[i][1];
                    if(next_i>=0 && next_i<m && next_j>=0 && next_j<n 
                        && grid[next_i][next_j]==1)
                    {
                        grid[next_i][next_j] = 2;
                        q.emplace(next_i,next_j);
                        flag = 1;
                    }
                }
            }
            if(flag)
            {
                times++;
                flag = 0;
            }
        }
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(grid[i][j] == 1)
                    return -1;
        return times;
    }
};
// @lc code=end

