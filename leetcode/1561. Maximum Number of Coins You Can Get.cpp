class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        const int n = piles.size() / 3;
        int totalCoins = 0;
        
        sort(piles.begin(), piles.end(), greater<int>());

        for (int i = 0; i < n; ++i) {
            totalCoins += piles[2 * i + 1];
        }
        
        return totalCoins;
    }
};
// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/
