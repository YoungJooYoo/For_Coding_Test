class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) 
    {
        if (mainTank < 5) {
            return mainTank * 10; 
        }

        int count = 0;
        while (mainTank >= 5) {
            mainTank -= 5;
            ++count;
            if (additionalTank >= 1) {
                ++mainTank;
                --additionalTank;
            }
        }

        return (count * 50) + (mainTank * 10);
    }
};
// 10 km -> 1-liter

// https://leetcode.com/problems/total-distance-traveled/description/
