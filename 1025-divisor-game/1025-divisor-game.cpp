class Solution {
public:
    bool divisorGame(int n) 
    {
        bool dp[n + 1];
        memset(dp, false, n + 1);
        
        for (size_t i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++){ 
                if (i % j == 0 && !dp[i - j]) {
                    dp[i] = true;
                }
            }
        }
        
        return dp[n];
    }
};