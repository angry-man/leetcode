/*
 * @lc app=leetcode.cn id=1557 lang=cpp
 *
 * [1557] 可以到达所有点的最少点数目
 */

// @lc code=start
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> result;
        vector<int> indegrees(n,1);
        for(auto edge : edges)
        {
            indegrees[edge[1]] = 0;
        }
        for(int i = 0;i < n;++i)
        {
            if(indegrees[i] == 1)
                result.push_back(i);
        }
        return result;
    }
};
// @lc code=end

