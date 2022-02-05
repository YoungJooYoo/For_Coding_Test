class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int profit = 0;
        int valley;
        int peak;
        
        for (size_t i = 0; i < prices.size(); i++) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            peak = prices[i];
            profit = profit + peak - valley;
        }
        
        return profit;
    }
};

