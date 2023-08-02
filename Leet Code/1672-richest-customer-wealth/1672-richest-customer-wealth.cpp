class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int max_wealth = INT_MIN;
        int sum;
        
        for (const auto& account : accounts) {
            sum = 0;
            for (const auto& ele : account) {
                sum += ele;
            }
            max_wealth = max(max_wealth, sum);
            
        }
        
        return max_wealth;
    }
};