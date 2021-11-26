/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> triangle;
        triangle.emplace_back(vector<int>(1,1));
        for(int i = 1;i<numRows;i++)
        {
            vector<int> temp;
            temp.emplace_back(1);
            for(int j = 1;j<i;j++)
            {
                temp.emplace_back(triangle[i-1][j-1]+
                triangle[i-1][j]);
            }
            temp.emplace_back(1);
            triangle.emplace_back(temp);
        }
        return triangle;
    }
};
// @lc code=end

