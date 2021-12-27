// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1091.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        int di[8] = {-1,-1,1,1,0,0,-1,1};
        int dj[8] = {1,-1,1,-1,1,-1,0,0};
        int len = 1;

        queue<pair<int,int>> bfs;
        bfs.emplace(0,0);
        grid[0][0] = 1;
        while(!bfs.empty())
        {
            int m = bfs.size();
            for(int i = 0;i<m;i++)  // 遍历上一次8个方向的所有可以走的点
            {
                auto [cur_i,cur_j] = bfs.front();
                bfs.pop();
                if(cur_i == n-1 && cur_j == n-1)
                    return len;
                for(int j = 0;j<8;j++) // 遍历每个可走的点的8个方向
                {
                    int next_i = cur_i + di[j];
                    int next_j = cur_j + dj[j];
                    if(next_i < 0 || next_j < 0 ||
                       next_i >= n || next_j >= n || 
                       grid[next_i][next_j] == 1)
                       continue;
                    else
                    {
                        bfs.emplace(next_i,next_j);
                        grid[next_i][next_j] = 1;
                    }
                }
            }
            len++;
        }
        return -1;
    }
};
// @lc code=end

