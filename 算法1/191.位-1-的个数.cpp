// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem191.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int count = 0;
        
        for(int i = 0;i<32;i++)
        {
            if(n & 1<<i)
                count++;
        }   
         
       /*  
        while(n != 0)
        {
            count ++;
            n = n & (n-1);
        }
        */
        return count;
    }
};
// @lc code=end

