/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int count = 0;
        auto start = nums.begin();
        auto index = find(start,nums.end(),0);
        while(index != nums.end())
        {
            count++;
            nums.erase(index);
            start = index;
            index = find(start,nums.end(),0);
        }
        for(int i = 0;i<count;i++)
            nums.push_back(0);

        /*
        int n = nums.size();
        int left = 0;
        int right = 0;
        while(right < n)
        {
            if(nums[right])
            {
                swap(nums[left],nums[right]);
                left++;
            }  
            right++;         
        }
        */
    }
};
// @lc code=end

