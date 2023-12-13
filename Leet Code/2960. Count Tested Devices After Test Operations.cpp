class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) 
    {
        const size_t LEN = batteryPercentages.size();
        int result = 0;

        for (size_t i = 0 ; i < LEN; ++i) {
            if (batteryPercentages[i] - result > 0) ++result;
        }

        return result;
    }
};

// https://leetcode.com/problems/count-tested-devices-after-test-operations/description/
