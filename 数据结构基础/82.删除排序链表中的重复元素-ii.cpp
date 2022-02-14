/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        ListNode* dumy = new ListNode(0,head);
        auto temp = dumy;
        while(temp->next != nullptr && temp->next->next != nullptr)
        {
            if(temp->next->val == temp->next->next->val)
            {
                auto h = temp->next;
                while(h != nullptr && h->val == temp->next->val)
                    h = h->next;
                temp->next = h;
            }
            else 
                temp = temp->next;
        }
        return dumy->next;
    }
};
// @lc code=end

