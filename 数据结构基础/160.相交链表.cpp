/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* Pa = headA;
        auto Pb = headB;
        while(Pa != Pb)
        {
            Pa = Pa == nullptr ? headB : Pa->next;
            Pb = Pb == nullptr ? headA : Pb->next;
        }
        return Pa;
    }
};
// @lc code=end

