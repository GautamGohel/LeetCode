class MyQueue {
public:
    stack<int>in,op;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(!op.empty()){
            int topp=op.top();
            op.pop();
            return topp;
        }
        while(!in.empty()){
            op.push(in.top());
            in.pop();
        }
        int topp=op.top();
        op.pop();
        return topp;
    }
    
    int peek() {
        if(!op.empty()){
            return op.top();
        }
        while(!in.empty()){
            op.push(in.top());
            in.pop();
        }
        return op.top();
    }
    
    bool empty() {
        return in.empty() and op.empty();
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