/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n = num1.size();
        int m = num2.size();
        vector<string> res;
        int flag = 0;
        for(int i = m - 1;i >= 0;--i)
        {
            int add = 0;
            string ans = "";
            for(int j = n - 1;j >= 0 || add != 0;--j)
            {
                int x = i < 0 ? 0 : (num2[i] - '0');
                int y = j < 0 ? 0 : (num1[j] - '0');
                int temp = x * y + add;
                add = temp/10;
                ans = to_string(temp%10) + ans;
            }
            for(int k = 0;k < flag; ++k)
                ans += '0';
            flag++;
            res.emplace_back(ans);
        }
        string result = "";
        for(auto s : res)
        {
            result = addStrings(result,s);
        }
        return result;
    }
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

