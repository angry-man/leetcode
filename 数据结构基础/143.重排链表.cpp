/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ;
        auto first  = head;
        while(first->next != nullptr && first->next->next != nullptr)
            first = first->next;
        auto temp = head->next;
        head->next = first->next;
        first->next = nullptr;
        reorderList(temp);
        head->next->next = temp;
    }
};
// @lc code=end

