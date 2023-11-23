class Solution {
public:
    vector<int> findIndices(const vector<int>& nums, const int indexDifference, const int valueDifference) 
    {
        const size_t LEN = nums.size();
        int idx1;
        int idx2;

        for (int i = 0; i < LEN; ++i) {
            for (int j = i + 1; j < LEN; ++j) {
                if (abs(nums[i] - nums[j]) >= valueDifference && abs(i - j) >= indexDifference) {
                    return {i, j};
                }        
            }
        } 

        return {-1, -1};
    }
};

// https://leetcode.com/problems/find-indices-with-index-and-value-difference-i/description/
