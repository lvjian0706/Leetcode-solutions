class MinStack {
public:
    /*
    设计常数时间内检索到最小元素的栈：
    需要定义变量存储最小值，考虑到当最小值弹出后能及时更新最小值，定义了min_stack存储截止到每个位置的最小值；
    1. push()，top()操作正常；
    2. getMin()操作直接返回min_stack的栈顶元素；
    3. push()操作：
    3.1 real_stack直接入栈；
    3.2 判断x与min_stack的栈顶元素谁小，将最小值入栈；
    */

    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        real_stack.push(x);
        if(min_stack.empty()) min_stack.push(x);
        else min_stack.push(min(x, min_stack.top()));
    }
    
    void pop() {
        real_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return real_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private:
        stack<int> real_stack;
        stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */