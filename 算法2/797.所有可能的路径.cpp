    /*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> state;
        dfs(graph,state,n,0);
        return result;
    }
    void dfs(vector<vector<int>>& graph,vector<int>& state,int n,int node)
    {
        if(node == n - 1)
        {
            result.emplace_back(state);
            return;
        }
        if(state.size() == 0)
            state.emplace_back(0);
        for(int i = 0;i < graph[node].size();i++)
        {
            state.emplace_back(graph[node][i]);
            dfs(graph,state,n,graph[node][i]);
            state.pop_back();
        }
    }
};
// @lc code=end

