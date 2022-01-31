/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        if(n<2)
            return s;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        int max_len = 1;
        int begin = 0;
        for(int j = 1;j<n;j++)
            for(int i = 0;i<j;i++)
            {
                if(s[i] == s[j])
                {
                    if(j-i>2)
                        dp[i][j] = dp[i+1][j-1];
                    else
                        dp[i][j] = 1;
                }
                if(dp[i][j] == 1 && j-i+1>max_len)
                {
                    max_len = j-i+1;
                    begin = i;
                }
            }
        return s.substr(begin, max_len);
    }
};
// @lc code=end

