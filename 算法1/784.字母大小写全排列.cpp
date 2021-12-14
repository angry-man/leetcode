/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    vector<string> letterCasePermutation(string s) 
    {
        dfs(s,0);
        return result;
    }

    void dfs(string &s,int state)
    {
        if(state == s.size())
            result.push_back(s);
        else
        {
            
            if(isdigit(s[state]))
                dfs(s,state+1);
            else
            {
                s[state] = tolower(s[state]);
                dfs(s,state + 1);

                s[state] = toupper(s[state]);
                dfs(s,state + 1);
            }
            
            /*
           dfs(s,state + 1);
           if(s[state] >= 'a' && s[state] <= 'z')
           {
                s[state] = toupper(s[state]);
                dfs(s,state + 1);
           }
           else if(s[state] >= 'A' && s[state] <= 'Z')
           {
                s[state] = tolower(s[state]);
                dfs(s,state + 1);
           }
            */
        }
    }
};
// @lc code=end

