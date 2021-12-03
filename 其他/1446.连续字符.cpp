/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

// @lc code=start
class Solution {
public:
    int maxPower(string s)
    {
        int begin_index = 0;
        int max_len = 0;
        for(int i = 1;i<s.size();i++)
        {
            if(s[i]!=s[i-1])
                begin_index = i;
            max_len = max(i - begin_index +1,max_len);
        }
        return max_len == 0 ? s.size():max_len;
    }
};
// @lc code=end

