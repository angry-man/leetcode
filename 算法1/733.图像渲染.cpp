/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        if(image[sr][sc] == newColor)
            return image;
        int n = image.size(),m = image[0].size();
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        if(sr+1<n && image[sr+1][sc] == color)
            floodFill(image,sr+1,sc,newColor);
        if(sr-1>=0 && image[sr-1][sc] == color)
            floodFill(image,sr-1,sc,newColor);
        if(sc+1<m && image[sr][sc+1] == color)
            floodFill(image,sr,sc+1,newColor);
        if(sc-1>=0 && image[sr][sc-1] == color)
            floodFill(image,sr,sc-1,newColor);

        return image;
    }
};
// @lc code=end

