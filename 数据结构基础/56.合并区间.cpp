/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        vector<vector<int>> result;
        //vector<int> state;
        
        sort(intervals.begin(),intervals.end());
        for(int i = 0;i < n;i++)
        {
            int low = intervals[i][0];
            int high = intervals[i][1];
            if(! result.size() || result.back()[1] < low)
                result.push_back({low,high});
            else
                result.back()[1] = max(result.back()[1],high);
        }
        return result;
    }
};
// @lc code=end

