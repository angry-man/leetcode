/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    stack<int> minelement;
    stack<int> minstack;
public:
    MinStack() {}
    
    void push(int val) 
    {
        if(minelement.empty() || val <= minelement.top())
            minelement.push(val);
        minstack.push(val);
    }
    
    void pop() 
    {
        if(minstack.top() == minelement.top())
            minelement.pop();
        minstack.pop();
    }
    
    int top() 
    {
        return minstack.top();
    }
    
    int getMin() 
    {
        return minelement.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

