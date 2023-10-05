class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        const size_t LEN = nums.size();
        const int DIAMETER = 2 * k + 1;
        vector<int> result(LEN, -1);

        if (k == 0) {
            return nums;
        }
        if (LEN < DIAMETER) {
            return result;
        }

        // 첫번쨰 평균 구하기
        long long sum = 0;
        for (size_t i = 0; i < DIAMETER; ++i) {
            sum += nums[i];    
        }
        result[k] = sum / DIAMETER;

        // 하나 더하고 하나 빼면서 계산하기
        for (size_t i = DIAMETER; i < LEN; ++i) {
            sum += nums[i];
            sum -= nums[i - DIAMETER];
            result[i - k] = sum / DIAMETER;
        }
        
        return result;
    }    
};

// https://leetcode.com/problems/k-radius-subarray-averages/description/
