/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>> mp;
        for(auto str : strs)
        {
            string key = str;
            sort(key.begin(),key.end());
            mp[key].emplace_back(str);
        }

        vector<vector<string>> result;
        for(auto it = mp.begin();it != mp.end();++it)
        {
            result.emplace_back(it->second);
        }
        return result;
    }
};
// @lc code=end

