/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) 
    {
        int begin = 0;
        int end;
        for(int i = 0;i<=s.size();i++)
        {
            if(s[i] == ' ' || s[i] == '\0')
            {
                end = i - 1;
                for(int j = begin;j<end;j++,end--)
                    swap(s[j],s[end]);
                begin = i + 1;
            }
        }
        return s;
    }
};
// @lc code=end

