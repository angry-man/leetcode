/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(dfs(grid,i,j) != 0)
                    count++;
            }
        }
        return count;
    }

    int dfs(vector<vector<char>>& grid,int cur_i,int cur_j)
    {
        if(cur_i < 0 || cur_i >= grid.size() ||
           cur_j < 0 || cur_j >= grid[0].size() || 
           grid[cur_i][cur_j] == '0')
           return 0;
        grid[cur_i][cur_j] = '0';
        int area = 1;
        int di[4] = {0,0,1,-1};
        int dj[4] = {1,-1,0,0};
        for(int i = 0;i < 4;i++)
        {
            int next_i = cur_i + di[i];
            int next_j = cur_j + dj[i];
            area += dfs(grid,next_i,next_j);
        }
        return area;
    }
};
// @lc code=end

