/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> used(n,vector<bool>(m,false));

        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if(board[i][j] == word[0] && dfs(board,used,word,i,j,0))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& used, string word,int cur_i,int cur_j,int index)
    {
        if(cur_i < 0 || cur_j < 0 ||
           cur_i >= board.size() || cur_j >= board[0].size() ||
           index >= word.size() || board[cur_i][cur_j] != word[index]||
           used[cur_i][cur_j] == true)
           return false;
        used[cur_i][cur_j] = true;
        if(index == word.size() - 1)
            return true;
        int di[4] = {0,0,1,-1};
        int dj[4] = {1,-1,0,0};
        for(int i = 0;i<4;i++)
        {
            int next_i = cur_i + di[i];
            int next_j = cur_j + dj[i];
            if(dfs(board,used,word,next_i,next_j,index+1))
                return true;
        }
        used[cur_i][cur_j] = false;
        return false;
    }
};
// @lc code=end

