/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {

        deque<int> d(deque<int>{nums.begin(),nums.end()});
        for(int i = 0;i<k;i++)
        {
            int back = d.back();
            d.pop_back();
            d.push_front(back);
        } 
        nums = vector<int>{d.begin(),d.end()};
    }
};
// @lc code=end

