/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
    stack<int> mystack;
    int front;
public:
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    { 
        if(mystack.empty())
            front = x;
        stack<int> temp;
        while(!mystack.empty())
        {
            temp.push(mystack.top());
            mystack.pop();
        }
        mystack.push(x);
        while(!temp.empty())
        {
            mystack.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() 
    {
        int a = mystack.top();
        mystack.pop();
        if(!mystack.empty())
            front = mystack.top();
        return a;
    }
    
    int peek() 
    {
        return front;
    }
    
    bool empty() 
    {
        return mystack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

