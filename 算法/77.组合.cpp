/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> state;
        dfs(n,k,state);
        return result;
    }

    void dfs(int n,int k,vector<int>& state)
    {
        if(state.size() == k)
            result.push_back(state);
        else
        {
            for(int i = state.empty()? 0: state.back();i<n;i++)
            {
                state.push_back(i+1);
                dfs(n,k,state);
                state.pop_back();
            }
        }
    }
};
// @lc code=end

