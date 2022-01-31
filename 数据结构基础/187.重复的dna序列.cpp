/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
    const int L = 10;
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        if(s.size() < 10)
            return vector<string> {};
        unordered_map<string,int> mp;
        vector<string> result;
        for(int i = 0;i < s.size() - L + 1;++i)
        {
            string key = s.substr(i,L);
            mp[key]++;
            if(mp[key] == 2)
                result.emplace_back(key);
        }
        return result;
    }
};
// @lc code=end

