class Solution {
    int fib_result[40];
    
public:
    int fib(int n) 
    {
        fib_result[0] = 0;
        fib_result[1] = 1;
        
        if (n < 2) {
            return fib_result[n];
        }
        
        for (size_t i = 2; i <= n; i++) {
            fib_result[i] = fib_result[i- 1] + fib_result[i - 2];
        }
        
        return fib_result[n];
    }
};