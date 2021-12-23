/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> result;
        int m = p.size();
        int n = s.size();
        if(m > n)
            return result;
        vector<int> num(26,0);
        for(int i = 0;i<m;i++)
        {
            num[p[i] - 'a']++;
            num[s[i] - 'a']--;
        }
        if(find_if(num.begin(),num.end(),[](int i){return i != 0;}) == num.end())
            result.emplace_back(0);    
        for(int i = 1;i < n - m + 1;i++)
        {
            num[s[i-1] - 'a']++;
            num[s[i+m-1] - 'a']--;
            if(find_if(num.begin(),num.end(),[](int ii){return ii != 0;}) == num.end())
                result.emplace_back(i);
        }
        return result;
    }
};
// @lc code=end

