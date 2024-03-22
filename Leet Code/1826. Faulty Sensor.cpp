class Solution {
public:
    int badSensor(const vector<int>& sensor1, const vector<int>& sensor2) 
    {
        const size_t ARRAY_LENGTH = sensor1.size();

        for (size_t i = 0; i < ARRAY_LENGTH - 1; ++i) {
            if (sensor1[i] != sensor2[i]) {
                if (sensor1[i] == sensor2[i + 1] && sensor2[i] != sensor1[i + 1]) {
                    return 1;
                } 
                else if (sensor2[i] == sensor1[i + 1] && sensor1[i] != sensor2[i + 1]) {
                    return 2;
                }
            }
        }

        return -1;
    }
};

// https://leetcode.com/problems/faulty-sensor/description/
