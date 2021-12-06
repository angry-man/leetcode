/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int end = 0;
        unordered_set<char> long_str;
        int max_len = 0;
        for(int i = 0;i<s.size();i++)
        {
            while(end < s.size() && !long_str.count(s[end]))
                long_str.insert(s[end++]);
            max_len = max(max_len,end - i);
            long_str.erase(s[i]);
        }
        return max_len;
    }
};
// @lc code=end

