/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int add  = 0;
        string result = "";
        while(i >= 0 || j >= 0 || add != 0)
        {
            int x = i < 0 ? 0 : (num1[i] - '0');
            int y = j < 0 ? 0 : (num2[j] - '0'); 
            result = to_string((x + y + add) % 10) + result;
            add = (x + y + add) / 10;
            i--;
            j--;
        }
        return result;
    }
};
// @lc code=end

