class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        const size_t n = nums.size();
        int sum = 0;

        while (k-- > 0) {
            nums[0] *= -1; // 가장 작은값에 -1을 곱하고 다시 정렬
            sort(nums.begin(), nums.end());
        }

        for (size_t i = 0; i < n; ++i) {
            sum += nums[i];
        }

        return sum;
    }
};

https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/
