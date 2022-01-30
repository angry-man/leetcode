/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n = s.size();
        vector<int> last(26,0);
        for(int i = 0; i < n;++i)
            last[s[i] - 'a'] = i;
        
        int start = 0;
        int end = 0;
        vector<int> result;
        for(int i = 0; i < n; ++i)
        {
            end = max(end,last[s[i] - 'a']);
            if(i == end)
            {
                result.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};
// @lc code=end

