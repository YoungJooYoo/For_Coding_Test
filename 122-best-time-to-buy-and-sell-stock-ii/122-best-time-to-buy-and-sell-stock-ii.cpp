class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int bottom;
        int top;
        
        for (size_t i = 0; i < prices.size(); i++) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            bottom = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            top = prices[i];
            profit = profit + top - bottom;
        }
        
        return profit;
    }
};

