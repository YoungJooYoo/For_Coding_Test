class Solution {
public:
    long long maximumTripletValue(const vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        long long result = 0;

        for (size_t i = 0; i < LEN; ++i) {
            for (size_t j = i + 1; j < LEN; ++j) {
                for (size_t k = j + 1; k < LEN; ++k) {
                    const long long temp = (nums[i] - nums[j]) * (long long)nums[k];
                    result = max(result, temp);
                }
            } 
        }

        return result;
    }
};


// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/
