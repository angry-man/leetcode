// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <map>
#include "commoncppproblem299.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int cow = 0;
        int bull = 0;
        string result = "";
        vector<int> sec_vec(10,0);
        vector<int> gue_vec(10,0);
        for(int i=0;i<secret.size();i++)
            if(secret[i] == guess[i])
                bull++;
            else
            {
                sec_vec[secret[i]-'0']++;
                gue_vec[guess[i]-'0']++;
            }
        for(int i=0;i<10;i++)
            cow += min(sec_vec[i],gue_vec[i]);
        result = result + to_string(bull) + "A" + to_string(cow) + "B";
        return result;
    }
};
// @lc code=end

