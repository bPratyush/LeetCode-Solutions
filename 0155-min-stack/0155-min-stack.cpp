class MinStack {
public:
    vector<vector<int>>s;
    MinStack() {
        
    }
    
    void push(int val) {
        int minval=getMin();
        if(s.empty()||minval>val) minval=val;
        s.push_back({val,minval});
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.empty()?-1:s.back()[0];
    }
    
    int getMin() {
        return s.empty()?-1:s.back()[1];
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