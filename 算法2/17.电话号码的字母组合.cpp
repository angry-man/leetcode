/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    map<int,string> m = {{2,"abc"},
                         {3,"def"},
                         {4,"ghi"},
                         {5,"jkl"},
                         {6,"mno"},
                         {7,"pqrs"},
                         {8,"tuv"},
                         {9,"wxyz"}};
    vector<string> letterCombinations(string digits) 
    {
        int n = digits.size();
        if(n == 0)
            return ;
        string state;
        dfs(digits,state,0);
        return result;
    }

    void dfs(string digits,string state,int node)
    {
        if(state.size() == digits.size())
        {
            result.emplace_back(state);
            return ;
        }
        for(int i = 0;i < m[digits[node] - '0'].size();i++)
        {
            state += m[digits[node] - '0'][i];
            dfs(digits,state,node+1);
            state = state.substr(0,state.size() - 1);
        }
    }
};
// @lc code=end

