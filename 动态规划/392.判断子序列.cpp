// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem392.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int begin = 0;
        for(int i = 0;i<s.size();i++)
        {
            int pos = t.find(s[i],begin);
            if(pos == -1)
                return false;
            else
                begin = pos+1;
        }
        return true;
    }
};
// @lc code=end

