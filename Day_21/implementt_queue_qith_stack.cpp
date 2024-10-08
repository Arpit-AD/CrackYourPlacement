class MyQueue {
    stack<int> st1, st2;
    int front;
public:
    MyQueue() {
        front = -1;
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st1.size() == 0 && st2.size() == 0) return -1;
        int x = peek();
        st2.pop();
        return x;
    }
    
    int peek() {
        if(st2.empty())
        {
            while(!st1.empty())
                st2.push(st1.top()), st1.pop();
        }
        
        return st2.top();
    }
    
    bool empty() {
        return st1.size() == 0 && st2.size() == 0;
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