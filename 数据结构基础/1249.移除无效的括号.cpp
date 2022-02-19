/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 *
 * [1249] 移除无效的括号
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int> parentheses;
        int length = s.size();
        for(int i = 0;i < length;++i)
        {
            if(s[i] == '(')
                parentheses.push(i);
            else if(s[i] == ')')
            {
                if(parentheses.empty())
                {
                    s.erase(i,1);
                    --length;
                    --i;
                }
                else
                    parentheses.pop();
            }
        }
        while(!parentheses.empty())
        {
            int index = parentheses.top();
            s.erase(index,1);
            parentheses.pop();
        }
        return s;
    }
};
// @lc code=end

