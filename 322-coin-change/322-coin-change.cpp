class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, amount + 1); // i <= amount 까지므로 배열 길이는 amount + 1
        dp[0] = 0; 
        
        for (size_t i = 1; i <= amount; i++) { 
            for (const int& coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};