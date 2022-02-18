/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == nullptr)
            return nullptr;
        auto first = head;
        int count;
        for(count = 0;count < k - 1 && head->next != nullptr;++count)
        {
            head = head->next;
        }
        if(count == k - 1)
        {
            auto end = reverseKGroup(head->next,k);
            for(int i = 0;i < k;++i)
            {
                auto curr = first;
                first = first->next;
                curr->next = end;
                end = curr;
            }
            first = head;
        }
        return first;
    }
};
// @lc code=end

