class MinStack {
public:
    stack<long long> minStack;
    long long int min;
    MinStack() {
        min = LLONG_MAX;
    }
    
    void push(int val) {
        long long x = val;
        if(minStack.empty()){
            minStack.push(x);
            min = val;
        }
        else if(x >= min){
            minStack.push(x);
        }
        else if(x < min){
            int old = min;
            min = x;
            minStack.push(2*min - old);
        }
    }
    
    void pop() {
        long long int top = minStack.top();
        if(top < min) min = 2*min - top;
        minStack.pop();
    }
    
    int top() {
        long long int top = minStack.top();
        if(top < min) return min;
        return top;
    }
    
    int getMin() {
        return min;
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