class Solution 
{
public:
    int change(int amount, vector<int>& coins) 
    {
        int size = coins.size();
        vector<int> dp(5000 + 1, 0);   //dp 배열만들어서 진행하기 dp[0] = 1   
        
        dp[0] = 1;
        
        for (const auto& coin : coins) {
            for (int i = coin; i < amount + 1; i++) {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
};
