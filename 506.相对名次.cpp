/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<string> answer;
        vector<int> s(score);
        sort(score.begin(),score.end());
        unordered_map<int,string> m;
        m.insert(pair<int,string>(score[score.size()-1],"Gold Medal"));
        if(score.size()>1)
        {
            m.insert(pair<int,string>(score[score.size()-2],"Silver Medal"));
            if(score.size()>2)
            {
                m.insert(pair<int,string>(score[score.size()-3],"Bronze Medal"));
                if(score.size()>3)
                {
                    for(int i = 0;i<score.size()-3;i++)
                        m.insert(pair<int,string>(score[i],to_string (score.size() - i)));  
                }
            }            
        } 
        for(int i = 0;i<s.size();i++)
            answer.emplace_back(m[s[i]]);          
        return answer;
    }
};
// @lc code=end

