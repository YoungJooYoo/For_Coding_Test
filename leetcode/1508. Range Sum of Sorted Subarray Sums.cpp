class Solution 
{
public:
    int rangeSum(const vector<int>& nums, const int n, const int left, const int right) 
    {
        const int MOD = 1e9 + 7;
        long long result = 0;
        vector<int> subarraySums;
        
        // Step 1: Compute all possible subarray sums
        for (int i = 0; i < n; ++i) 
        {
            int sum = 0;
            for (int j = i; j < n; ++j) 
            {
                sum += nums[j];
                subarraySums.push_back(sum);
            }
        }
        
        // Step 2: Sort the sums
        sort(subarraySums.begin(), subarraySums.end());
        
        // Step 3: Compute the sum of the range from left to right
        for (int i = left - 1; i <= right - 1; ++i) 
        {
            result = (result + subarraySums[i]) % MOD;
        }
        
        return static_cast<int>(result);
    }
};

// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/?envType=daily-question&envId=2024-08-04
