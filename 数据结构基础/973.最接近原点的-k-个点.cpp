/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
public:
    static bool cmp(pair<int,int> m, pair<int,int> n)
    {
        return m.second < n.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        //unorder_map<int,double> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> q(cmp);

        for(int i = 0;i < points.size();++i)
        {
            int distence = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if(q.size() == k)
            {
                if(q.top().second > distence)
                {
                    q.pop();
                    q.emplace(i,distence);
                }
            }
            else
                q.emplace(i,distence);
        }

        vector<vector<int>> result;
        while(!q.empty())
        {
            result.emplace_back(points[q.top().first]);
            q.pop();
        }
        return result;
    }
};
// @lc code=end

