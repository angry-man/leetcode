/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<int> visited(n);
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(isConnected,visited,n,i);
                count++;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& isConnected,vector<int>& visited,int n,int cur_i)
    {
        for(int i = 0;i < n;i++)
        {
            if(!visited[i] && isConnected[cur_i][i] == 1)
            {
                visited[i] = 1;
                dfs(isConnected,visited,n,i);
            }
        }
    }
};
// @lc code=end

