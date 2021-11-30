/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> wordDictset;
        for(auto word : wordDict)
            wordDictset.insert(word);
        
        auto dp = vector<bool> (s.size()+1);
        dp[0] = true;
        for(int i=0;i<=s.size();i++)
            for(int j = 0;j<i;j++)
                if(dp[j] && wordDictset.find(s.substr(j,i-j))!=wordDictset.end())
                {
                    dp[i] = true;
                    break;
                }
        return dp.back();
    }
};
// @lc code=end

