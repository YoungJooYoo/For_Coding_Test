class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        int count = 0;
        int sum = 0;

        sort(costs.begin(), costs.end());

        for (const auto& cost : costs) {
            if (sum + cost > coins) {
                break;
            }
            sum += cost;
            ++count;
        }

        return count;
    }
};


// https://leetcode.com/problems/maximum-ice-cream-bars/description/
