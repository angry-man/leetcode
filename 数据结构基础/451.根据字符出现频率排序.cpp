/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    static bool cmp(pair<char, int>& m, pair<char, int>& n)
    {
        return m.second < n.second;
    }

    string frequencySort(string s) 
    {
        unordered_map<char,int> m;
        for(auto& c : s)
            m[c]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(&cmp)> q(cmp);

        for(auto [ch,count] : m)
        {
            q.emplace(ch,count);
        }

        string result;
        while(!q.empty())
        {
            for(int i = 0;i < q.top().second; ++i)
                result.push_back(q.top().first);
            q.pop();
        }
        return result;
    }
    
};
// @lc code=end

