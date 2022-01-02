/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {   
        vector<int> state;
        dfs(candidates,state,target,0);
        return result;
    }
    
    void dfs(vector<int>& candidates, vector<int>& state,int target,int index)
    {
        if(index == candidates.size())
            return ;
        if(target == 0)
        {
            result.emplace_back(state);
            return ;
        }

        dfs(candidates,state,target,index + 1);
        if(target - candidates[index] >= 0)
        {
            state.emplace_back(candidates[index]);
            dfs(candidates,state,target - candidates[index],index);
            state.pop_back();
        }
    }
};
// @lc code=end

