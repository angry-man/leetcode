/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        int first = 0;
        int second = 0;
        vector<int> result;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(first < nums1.size() && second < nums2.size())
        {
            if(nums1[first] == nums2[second])
            {
                result.emplace_back(nums1[first]);
                first++;
                second++;
            }
            else if(nums1[first] > nums2[second])
                second++;
            else
                first++;
        }
        return result;
    }
};
// @lc code=end

