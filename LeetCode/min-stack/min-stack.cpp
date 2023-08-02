class MinStack {
private:
    int st_top;
    int st_buttom;
    int min_val;
    vector<int> st;
    
public:
    MinStack(): st_top(-1), st_buttom(0), st(10000){}
    
    void push(int val) {
        st_top++;
        st[st_top] = val;
    }
    
    void pop() {
        st_top--;
        return;
    }
    
    int top() {
        return st[st_top];
    }
    
    int getMin() {
        if (st_top < 0) {
            return st[st_buttom];
        }
        min_val = INT_MAX;
        for (int i = st_buttom; i <= st_top; i++) {
            if (min_val > st[i]) {
                min_val = st[i];
            }
        }
        return min_val;
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