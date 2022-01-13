// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem203.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (head == nullptr) 
        {
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;

        /*
        struct ListNode* dummyHead = new ListNode(0, head);
        struct ListNode* temp = dummyHead;
        while (temp->next != NULL) 
        {
            if (temp->next->val == val) 
                temp->next = temp->next->next; 
            else 
                temp = temp->next;
        }
        return dummyHead->next;
        */
    }
};
// @lc code=end

