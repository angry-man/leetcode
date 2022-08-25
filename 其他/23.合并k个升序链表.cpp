/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
class cmp
{
public:
    bool operator()(ListNode* l1,ListNode* l2)
    {
        return l1->val > l2->val;
    }
};
class Solution {
public:

    //优先队列
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        for(auto list : lists)
        {
            if(list != nullptr)
                q.push(list);
        }
        ListNode* dumy = new ListNode(0);
        auto head = dumy;
        while(!q.empty())
        {
            auto temp = q.top();
            q.pop();
            head->next = temp;
            head = head->next;
            if(temp->next != nullptr)
                q.push(temp->next);
        }
        return dumy->next;
    }
    /*  分治
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n = lists.size();
        if(n == 0)
            return {};
        deque<ListNode*> d;
        for(int i = 0;i < n/2;++i)
        {
            d.push_back(mergeKLists(lists[2*i],lists[2*i+1]));
        }
        if(n%2 == 1)
            d.push_back(lists.back());
        while(d.size() > 1)
        {
            ListNode* temp1 = d.front();
            d.pop_front();
            ListNode* temp2 = d.front();
            d.pop_front();
            d.push_back(mergeKLists(temp1,temp2));
        }
        return d.front();
    }
    ListNode* mergeKLists(ListNode* list1,ListNode* list2)
    {
        ListNode* dumy = new ListNode(0);
        ListNode* head = dumy;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                head->next = list1;
                list1 = list1->next;
            }
            else
            {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next; 
        }
        if(list1 == nullptr)
            head->next = list2;
        else if(list2 == nullptr)
            head->next = list1;
        return dumy->next;
    }*/
};

// @lc code=end

