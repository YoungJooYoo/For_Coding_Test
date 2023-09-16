class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) 
    {
        int count = 0;

        for (size_t i = 0; i < startTime.size(); ++i) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
                ++count;
            }
        }   

        return count; 
    }
};

// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/description/
