/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int max_num = n*n;
        int cur_num = 1;
        vector<vector<int>> matrix(n,vector<int>(n));
        int row = 0;
        int col = 0;
        vector<vector<int>> direction{{0,1},{1,0},{0,-1},{-1,0}};
        int dir_index = 0;
        while(cur_num <= max_num)
        {
            matrix[row][col] = cur_num;
            cur_num++;
            int next_row = row + direction[dir_index][0];
            int next_col = col + direction[dir_index][1];
            if(next_row >= n || next_row < 0 ||
               next_col >= n || next_col < 0 ||
               matrix[next_row][next_col] != 0)
               dir_index = (dir_index + 1) % 4;
            row = row + direction[dir_index][0];
            col = col + direction[dir_index][1];
        }
        return matrix;
    }
};
// @lc code=end

