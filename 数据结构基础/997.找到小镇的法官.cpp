/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> indegrees(n + 1);
        vector<int> outdegrees(n + 1);
        for(auto edge : trust)
        {
            ++indegrees[edge[1]];
            ++outdegrees[edge[0]];
        }
        for(int i = 1;i <= n;++i)
        {
            if(indegrees[i] == n-1 && outdegrees[i] == 0)
                return i;
        }
        return -1;
    }
};
// @lc code=end

