/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == nullptr)
            return head;
        ListNode* dummy = new ListNode;
        dummy->val = (head->val) - 1;
        dummy->next = head;
        auto temp = dummy;
        while(temp != nullptr && temp->next != nullptr)
        {
            if(temp->val == temp->next->val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return dummy->next;
    }
};
// @lc code=end

