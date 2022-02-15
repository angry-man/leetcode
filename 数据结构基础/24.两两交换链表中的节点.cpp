/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        auto result = head->next;
        if(head != nullptr && head->next != nullptr)
        {
            ListNode* temp = new ListNode;
            temp = head->next;
            head->next = swapPairs(head->next->next);
            temp->next = head;
        }
        return result;
    }
};
// @lc code=end

