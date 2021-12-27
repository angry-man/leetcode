/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> marked(n,vector<int>(m,0));
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                    dfs(board,marked,i,j);
        for(int i = 1;i<n-1;i++)
            for(int j = 1;j<m-1;j++)
                if(board[i][j] == 'O' && marked[i][j] == 0)
                    board[i][j] = 'X';
    }

    void dfs(vector<vector<char>>& board,vector<vector<int>>& marked,int cur_i,int cur_j)
    {
        if(cur_i >= 0 && cur_j >= 0 && 
           cur_i < board.size() && cur_j < board[0].size() && 
           board[cur_i][cur_j] == 'O' && marked[cur_i][cur_j] == 0)
        {
            marked[cur_i][cur_j] = 1;
            int di[4] = {0,0,-1,1};
            int dj[4] = {-1,1,0,0};
            for(int i = 0;i<4;i++)
            {
                int next_i = cur_i + di[i];
                int next_j = cur_j + dj[i];
                dfs(board,marked,next_i,next_j);
            }
        }
    }
};
// @lc code=end

