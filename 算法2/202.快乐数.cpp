/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) 
    {
        unordered_set<int> result;
        int sum = sum_squre(n);
        while(sum != 1)
        {
            if(result.find(sum) == result.end())
                result.insert(sum);
            else
                return false;
            sum = sum_squre(sum);
        }
        return true;
    }

    int sum_squre(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            sum += ((n%10)*(n%10));
            n = n/10;
        }
        return sum;
    }
};
// @lc code=end

