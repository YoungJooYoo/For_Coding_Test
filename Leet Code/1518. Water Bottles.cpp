class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int sum = numBottles;

        while (numBottles >= numExchange) {
            const int full_bottle = (numBottles / numExchange);
            const int empty_bottle = (numBottles % numExchange);
            sum += full_bottle;
            numBottles = full_bottle + empty_bottle;
        }

        return sum;
    }
};

// https://leetcode.com/problems/water-bottles/
