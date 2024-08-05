class MyStack {
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) { q1.push(x); }

    int pop() {
        if (empty()) {
            return -1;
        }
        return top(true);
    }

    int top(bool pop = false) {
        if (q1.size() == 0)
            return -1;
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        if (pop)
            q1.pop();
        else {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }

    bool empty() { return q1.size() == 0 && q2.size() == 0; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */