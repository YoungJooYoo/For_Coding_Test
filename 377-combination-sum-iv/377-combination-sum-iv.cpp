class Solution {
public:

    int recursive(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target < 0) return 0;
        if (dp[target] != -1) return dp[target];
        
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            count += recursive(nums, target - nums[i], dp);
        }
        
        dp[target] = count;
        
        return count;
    }
    
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int> dp(target + 1, -1);
        dp[0]=1;
        
        recursive(nums, target, dp);
        return dp[target];
    }
};