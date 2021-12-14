/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        auto row = upper_bound(matrix.begin(),matrix.end(),target,
            [](int tar,vector<int>& mat)
            {return tar < mat[0];});
        if(row-- == matrix.begin())
            return false;
        return binary_search(row->begin(),row->end(),target);
    }
};
// @lc code=end

