/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.size();
        int m = s2.size();
        if(n>m)
            return false;

        vector<int> cnt(26,0);
        for(int i = 0;i<n;i++)
        {
            cnt[s1[i]-'a']--;
            cnt[s2[i]-'a']++;
        }
        int diff = 0;
        for(int c : cnt)
            if(c!=0)
                diff++;
        if(diff == 0)
            return true;
        for(int i = n;i<m;i++)
        {
            int in_str = s2[i] - 'a';
            int out_str = s2[i-n] - 'a';

            if(in_str != out_str)
            {
                if(cnt[in_str] == 0)
                    diff++;
                cnt[in_str]++;
                if(cnt[in_str] == 0)
                    diff--;
                
                if(cnt[out_str] == 0)
                    diff++;
                cnt[out_str]--;
                if(cnt[out_str] == 0)
                    diff--;
                if(diff == 0)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

