// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem844.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        string ss;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '#' && ss.length()>0)
                ss = ss.substr(0,ss.length()-1);
            else if(s[i] != '#')
                ss+=s[i];
        }
        string tt;
        for(int i = 0;i<t.size();i++)
        {
            if(t[i] == '#' && tt.length()>0)
                tt = tt.substr(0,tt.length()-1);
            else if(t[i] != '#')
                tt+=t[i];
        }
        return ss==tt;
    }
};
// @lc code=end

