/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_map<int,unordered_set<char>> row;
        unordered_map<int,unordered_set<char>> col;
        unordered_map<int,unordered_set<char>> nine;
        for(int i = 0;i < 9;i++)
        {
            for(int j = 0;j < 9;j++)
            {
                if(board[i][j] != '.')
                {
                    if(find(row[i].begin(),row[i].end(),board[i][j]) != row[i].end())
                        return false;
                    else
                        row[i].insert(board[i][j]);
                    
                    if(find(col[j].begin(),col[j].end(),board[i][j]) != col[j].end())
                        return false;
                    else
                        col[j].insert(board[i][j]);
                    
                    int index = (i/3)*3+(j/3);
                    if(find(nine[index].begin(),nine[index].end(),board[i][j]) != nine[index].end())
                        return false;
                    else
                        nine[index].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
// @lc code=end

