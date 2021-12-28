/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> state;
        vector<bool> used(n,false);
        for(int i = 0;i<=n;i++)
            dfs(nums,state,used,i,0);
        return result;
    }

    void dfs(vector<int>& nums,vector<int>& state, vector<bool>& used,int n,int node)
    {
        if(state.size() == n)
        {
            result.emplace_back(state);
            return;
        }      
        for(int i = node;i<nums.size();i++)
        {        
            //i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false
            //满足上述条件后就会被跳过
            //当前节点等于上一个节点，且上一个节点未被使用，即生成的子串中已经
            //有这样的情况了，所以跳过，
            //used[i - 1] == false 表示正在生成的子串中没有nums[i-1]这个数
            if(i == 0 || nums[i] != nums[i - 1] || used[i - 1])
            {
                state.emplace_back(nums[i]);
                used[i] = true;
                dfs(nums,state,used,n,i+1);
                used[i] = false;
                state.pop_back();
            }
        }
    }
};
// @lc code=end

