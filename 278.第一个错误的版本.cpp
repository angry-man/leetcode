/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        if(isBadVersion(1))
            return 1;
        int low = 1;
        int high = n;
        int mid ;
        while(low < high)
        {
            mid = low + (high - low)/2;
            if(isBadVersion(mid))
                high = mid;
            else
                low = mid + 1;            
        }    
        return low;
    }
};
// @lc code=end

