/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int lcs = longestCommonSubsequence(word1,word2);
        return (word1.size() - lcs) + (word2.size() - lcs);
    }

    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1;i<m+1;i++)
            for(int j = 1;j<n+1;j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        return dp[m][n];
    }
};
// @lc code=end

