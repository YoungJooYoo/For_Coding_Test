class Solution {
public:
    int racecar(int target) 
    {
        if (dp[target] > 0) {
            return dp[target];
        }
        
        int n = floor(log2(target)) + 1; // 내림함수 floor,   (2^n) - 1 = 누적속도,
        int res;
        
        if ( 1 << n == target + 1) {
            dp[target] = n;
        }
        else {
            dp[target] = racecar((1 << n) - 1 - target) + n + 1;
            for (int m = 0; m < n - 1; ++m) {
                dp[target] = min(dp[target], racecar(target - (1 << (n - 1)) + (1 << m)) + n + m + 1);
            }
        }
        
        return dp[target];
    }
    
private:    
    int dp[10001];
};