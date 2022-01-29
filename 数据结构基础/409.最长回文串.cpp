/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char,int> m;
        for(auto c : s)
        {
            m[c]++;
        }
        int count = 0;
        bool flag = false;
        for(auto it = m.begin();it != m.end();++it)
        {
            if(it->second % 2 == 0)
                count += it->second;
            else
            {
                count += (it->second - 1);
                flag = true;
            }             
        }
        return flag ? count + 1 : count;
    }
};
// @lc code=end

