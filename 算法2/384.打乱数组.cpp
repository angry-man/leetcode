/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
private:
    vector<int> array;
public:
    Solution(vector<int>& nums) 
    {
        array = nums;
        n = nums.size();
    }
    
    vector<int> reset() 
    {
        return array;
    }
    
    vector<int> shuffle() 
    {
        vector<int> temp;
        temp = array;
        random_shuffle(temp.begin(),temp.end());
        return temp;
        //也可以全排列之后随机选一个组合
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

