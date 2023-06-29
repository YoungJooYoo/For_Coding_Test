class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int max_altitude = 0;
        int previous = 0;

        for (const int& elem : gain) {
            previous = previous + elem;
            max_altitude = max(max_altitude, previous);
        }
        
        return max_altitude;
    }
};

// https://leetcode.com/problems/find-the-highest-altitude/description/
