/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> state;
        for(int i = 0;i<=n;i++)
            dfs(nums,state,i,0);
        return result;
    }

    void dfs(vector<int>& nums,vector<int>& state,int n,int node)
    {
        if(state.size() == n)
        {
            result.emplace_back(state);
            return;
        }
        for(int i = node;i<nums.size();i++)
        {
            state.emplace_back(nums[i]);
            dfs(nums,state,n,i+1);
            state.pop_back();
        }
    }
};
// @lc code=end

