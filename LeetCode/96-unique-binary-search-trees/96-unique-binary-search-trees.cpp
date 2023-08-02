class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> dp(30, 0);
        dp[0] = 1;
        dp[1] = 1;

        if (n == 1) {
            return 1;
        }
        
        for (size_t i = 2; i <= n; i++) {
            for (size_t j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];    
            }
        }
        
        return dp[n];
    }
};

/*
dp 점화식은


dp[4] = dp[0] * dp[3] +
        dp[1] * dp[2] +
        dp[2] * dp[1] +
        dp[3] * dp[1] 

dp[i] = dp[j] + dp[i - j - 1]
*/