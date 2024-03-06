class Solution {
public:
    int minOperations(vector<int>& nums, const int k) 
    {
        sort(begin(nums), end(nums));

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] >= k) return i;
        }
        
        return 0;
    }
};

// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/
