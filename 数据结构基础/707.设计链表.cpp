/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(nullptr){}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* head;
public:
    MyLinkedList():head(nullptr) {}
    
    int get(int index) 
    {
        auto temp = head;
        for(int i = 0;i < index && temp != nullptr;i++)
        {
            temp = temp->next;
        }
        return temp == nullptr ? -1 : temp->val;
    }
    
    void addAtHead(int val) 
    {
        ListNode* H = new ListNode(val,head);
        head = H;
    }
    
    void addAtTail(int val) 
    {
        auto temp = head;
        if(head == nullptr)
        {
            head = new ListNode(val,nullptr);
            return ;
        }       
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = new ListNode(val,nullptr);
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index <= 0)
        {
            addAtHead(val);
            return ;
        }         
        auto temp = head;
        for(int i = 0;i < index - 1 && temp != nullptr;i++)
        {
            temp = temp->next;
        }
        if(temp != nullptr)
        {
            ListNode* node = new ListNode(val);
            node->next = temp->next;
            temp->next = node;
        }
    }
    
    void deleteAtIndex(int index) 
    {
        if(index == 0 && head != nullptr)
        {
            head = head->next;
            return ;
        }
        auto temp = head;
        for(int i = 0;i < index - 1 && temp != nullptr;i++)
        {
            temp = temp->next;
        }
        if(temp != nullptr && temp->next != nullptr)
        {
            temp->next = temp->next->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

