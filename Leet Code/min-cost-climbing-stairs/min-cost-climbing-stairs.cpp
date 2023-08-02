class Solution {
public:
   int minCostClimbingStairs(vector<int>& cost) {
       const size_t cost_length = cost.size(); 
       
        for (size_t i = 2; i < cost_length; i++) {
            cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
        }
       
        return min(cost[cost_length - 1],cost[cost_length - 2]);
    }
};

