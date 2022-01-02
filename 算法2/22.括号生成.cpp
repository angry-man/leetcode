/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
/*
    vector<string> result;
    vector<string> generateParenthesis(int n) 
    {
        //先把n对括号生成出来，然后开始有重复数的全排列，
        //在得到排列结果后就判断是否合法，合法则添加结果
        string state;
        string parentheses;
        vector<bool> used(2*n,false);
        for(int i = 0;i < n;i++)
            parentheses += "(";
        for(int i = 0;i < n;i++)
            parentheses += ")";    
        dfs(parentheses,state,used,n);
        return  result;
    }

    void dfs(string parentheses,string state,vector<bool>& used,int n)
    {
        if(state.size() == 2*n && Islegal(state))
        {
            result.emplace_back(state);
            return ;
        }
        for(int i = 0;i < parentheses.size();i++)
        {
            if(!used[i] && (i == 0 || parentheses[i] != parentheses[i - 1] || used[i - 1]))
            {
                state += parentheses[i];
                used[i] = true;
                dfs(parentheses,state,used,n);
                used[i] = false;
                state = state.substr(0,state.size() - 1);
            }
        }
    }

    bool Islegal(string state)
    {
        stack<char> temp;
        for(int i = 0;i < state.size();i++)
        {
            if(state[i] == '(')
                temp.push('(');
            else if(!temp.empty() && state[i] == ')' && temp.top() == '(')
                temp.pop();
            else
                return false;     
        }
        return true;
    }
*/
void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }

};
// @lc code=end

