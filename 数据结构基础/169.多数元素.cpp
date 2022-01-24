/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> count;
        int result = 0;
        for(auto num : nums)
        {
            count[num]++;
            if(count[num] > nums.size()/2)
            {
                result = num;
                break;
            }    
        }
        return result;
    }
};
// @lc code=end

