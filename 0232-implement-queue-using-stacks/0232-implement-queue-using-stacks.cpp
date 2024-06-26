class MyQueue {
public:
    MyQueue() {
        
    }
    /*
        void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(p.empty())
        {
            while(!q.empty())
            {
                    p.push(q.top());
                    q.pop();
            }
        }
        int x = p.top();
        p.pop();
        return x;
    }
    
    int peek() {
        if(p.empty())
        {
           while(!q.empty())
            {
                    p.push(q.top());
                    q.pop();
            }
        }
        int x = p.top();
        return x;
    }
    
    bool empty() {
        if(!q.empty() || !p.empty())
        {
            return false;
        }
        return true;
    }
    */
    stack<int>inp,out;
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        if(out.empty()){
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
            int val=out.top();
            out.pop();
            return val;
        }
        else{
         int val=out.top();
         out.pop();
         return val;
        }
    }
    
    int peek() {
               if(out.empty()){
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
            return out.top();
        }
        else{
         return out.top();
        }
    }
    
    bool empty() {
        if(!inp.empty() or !out.empty()) return false;
        else
         return true;
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