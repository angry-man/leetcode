// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem20.h"
#include <stack>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) 
    {
        if(s.size() == 1)
            return false;
        int n = s.size();
        stack<char> Parenthesis;
        for(auto c : s)
        {
            if(c == '(' || c == '[' || c == '{')
                Parenthesis.push(c);
            else if(!Parenthesis.empty() && 
                   ((c == ')' && Parenthesis.top() == '(') ||
                   (c == ']' && Parenthesis.top() == '[') ||
                   (c == '}' && Parenthesis.top() == '{')))
                {
                   Parenthesis.pop();
                }
            else 
                return false;
        }
        return Parenthesis.empty() ? true : false;
    }
};
// @lc code=end

