/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        if(n <= 2)
            return n;
        
        int count = 0;
        for(int i = 0;i < n;i++)
        {
            unordered_map<int,int> slope;
            if(count >= n-i || count > n/2)
                break;
            for(int j = i + 1;j < n;j++)
            {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if(x == 0)
                    y = 1;
                else if(y == 0)
                    x = 1;
                else
                {
                    if(y < 0)
                    {
                        x = -x;
                        y = -y;
                    }
                    int gcdxy = gcd(abs(x),abs(y));
                    x /= gcdxy;
                    y /= gcdxy;
                }
                slope[y + x * 20001]++;
            }
            int maxn = 0;
            for(auto [_,num] : slope)
                maxn = max(maxn,num + 1);
            count = max(count,maxn);
        }
        return count;
    }

    int gcd(int a, int b) 
    {
        return b ? gcd(b, a % b) : a;
    }
};
// @lc code=end

