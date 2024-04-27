class Solution {
public:
    int findDelayedArrivalTime(const int arrivalTime, const int delayedTime) 
    {
        return (arrivalTime + delayedTime) % 24;
    }
};

// https://leetcode.com/problems/calculate-delayed-arrival-time/
