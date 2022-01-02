/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> state;
        vector<bool> used(n,false);
        dfs(nums,state,used);
        return result;
    }

    void dfs(vector<int>& nums,vector<int>& state,vector<bool>& used)
        {
            if(state.size() == nums.size())
            {
                result.emplace_back(state);
                return;
            }
                for(int i = 0;i<nums.size();i++)
                {
                    if(!used[i] && (i == 0 || nums[i] != nums[i - 1] || used[i - 1]))
                    {
                        state.emplace_back(nums[i]);
                        used[i] = true;
                        dfs(nums,state,used);
                        used[i] = false;
                        state.pop_back();
                    }
                }
        }
};
// @lc code=end

