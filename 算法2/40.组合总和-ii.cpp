/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<int> state;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,state,target,0);
        return result;
    }

    void dfs(vector<int>& candidates, vector<int>& state,int target,int index)
    {
        if(target == 0)
        {
            result.emplace_back(state);
            return;
        }

        for(int i = index;i < candidates.size() && target - candidates[i] >= 0;i++)
        {
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            state.emplace_back(candidates[i]);
            dfs(candidates,state,target - candidates[i],i+1);
            state.pop_back();
        }
    }
};
// @lc code=end

