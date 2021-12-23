/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
    {
        vector<vector<int>> list;
        int i = 0;
        int j = 0;
        while(i < firstList.size() && j < secondList.size())
        {
            int begin = max(firstList[i][0],secondList[j][0]);
            int end = min(firstList[i][1],secondList[j][1]);
            if(begin <= end)
                list.push_back(vector<int>{begin,end});
            if(firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return list;
    }
};
// @lc code=end

