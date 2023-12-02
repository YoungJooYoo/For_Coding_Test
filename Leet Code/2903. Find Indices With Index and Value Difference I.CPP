class Solution {
public:
    vector<int> findIndices(const vector<int>& nums, const int indexDifference, const int valueDifference) 
    {
        const size_t LEN = nums.size();

        for (int i = 0; i < LEN; ++i) {
            for (int j = i; j < LEN; ++j) {
                if (abs(j - i) >= indexDifference && abs(nums[j] - nums[i]) >= valueDifference) {
                    return {i, j};
                }        
            }
        } 

        return {-1, -1};
    }
};

// https://leetcode.com/problems/find-indices-with-index-and-value-difference-i/description/
