/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) 
    {
        if(head == nullptr)
            return NULL;
        auto temp = head;
        if(head->next!=nullptr)
        {
            auto list = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return list;
            /*head = list;
            while (list->next != nullptr)
                list = list->next;
            list->next = temp;
            temp->next = NULL;*/
        }
        return head;
        /*
        auto list = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return list;
        */
    }
};
// @lc code=end

