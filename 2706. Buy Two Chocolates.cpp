class Solution {
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        const size_t LEN = prices.size();

        sort(prices.begin(),prices.end());

        int temp = prices[0] + prices[1];

        if (temp > money) return money;
        else if (temp == money) return 0;
        else return money - temp;
    }
};

// https://leetcode.com/problems/buy-two-chocolates/description/
