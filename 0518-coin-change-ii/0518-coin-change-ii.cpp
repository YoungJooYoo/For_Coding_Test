class Solution 
{
public:
    int change(int amount, vector<int>& coins) 
    {
        int size = coins.size();
        vector<int> dp(ARR_LENGTH + 1, 0);   //dp 배열만들어서 진행하기 dp[0] = 1   
        
        dp[0] = 1;
        
        for (const auto& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
    
private:
    enum { ARR_LENGTH = 5000 };
};
