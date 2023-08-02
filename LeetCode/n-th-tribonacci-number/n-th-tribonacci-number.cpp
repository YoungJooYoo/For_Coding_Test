class Solution {
private:
    int ans[10000] = {0, };
    
public:
    int tribonacci(int n) {
        if (n == 0 or n == 1) {
            return n;
        }
        if (n == 2) {
            return 1;
        }
        
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 1;
        
        for (size_t i = 3; i < n + 1; i++) {
            ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
            cout <<"ans["<< i << "] : "<< ans[n] << endl;
        }
        
        return ans[n];
    }
};