class MaxStack {
public:
    MaxStack() {}
    
    void push(int x) 
    {
        stack.push_back(x);
    }
    
    int pop() 
    {
        if (stack.empty()) {
            return -1;
        }
        int result = stack.back();
        stack.pop_back();
        return result;
    }
    
    int top() 
    {
        if (stack.empty()) {
            return -1;
        }
        return stack.back();
    }
    
    int peekMax() 
    {
        if (stack.empty()) {
            return -1;
        }
        return *max_element(stack.begin(), stack.end());
    }
    
    int popMax() 
    {
        if (stack.empty()) {
            return -1;
        }
        int result = *max_element(stack.begin(), stack.end());
        stack.erase((find(stack.rbegin(), stack.rend(), result) + 1).base());
        return result;
    }

private:
    vector<int> stack;
};
