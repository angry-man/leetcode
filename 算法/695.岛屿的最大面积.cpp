/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
//深度优先搜索 快一点
/*
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size(),m = grid[0].size();
        int area = 0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                area = max(area,dfs(grid,i,j));
        return area;
    }

    int dfs(vector<vector<int>>& grid,int cur_i,int cur_j)
    { 
        if(cur_i < 0 || cur_j < 0 ||
           cur_i >= grid.size() || cur_j >= grid[0].size() ||
           grid[cur_i][cur_j] == 0)
           return 0;
        grid[cur_i][cur_j] = 0;
        int area = 1;
        int di[4] = {0,0,1,-1};
        int dj[4] = {1,-1,0,0};
        for(int i = 0;i<4;i++)
        {
            int next_i = cur_i + di[i];
            int next_j = cur_j + dj[i];
            area += dfs(grid,next_i,next_j);
        }
        return area;
    }
    */
//广度优先搜索 慢一点
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int max_area = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                int area = 0;
                queue<int> que_i;
                queue<int> que_j;
                que_i.push(i);
                que_j.push(j);
                while(!que_i.empty())
                {
                    int cur_i = que_i.front();
                    int cur_j = que_j.front();
                    que_i.pop();
                    que_j.pop();
                    if(cur_i < 0 || cur_j < 0 ||
                        cur_i >= grid.size() || cur_j >= grid[0].size() ||
                        grid[cur_i][cur_j] == 0)
                        continue;

                    area++;

                    grid[cur_i][cur_j] = 0;//防止重复搜索
                    int di[4] = {0,0,1,-1};
                    int dj[4] = {1,-1,0,0};
                    for(int index = 0;index < 4;index++)
                    {
                        int next_i = cur_i + di[index];
                        int next_j = cur_j + dj[index];
                        que_i.push(next_i);
                        que_j.push(next_j);
                    }
                }
                max_area = max(max_area,area);
            }
        }
        return max_area;
    }
};
// @lc code=end

