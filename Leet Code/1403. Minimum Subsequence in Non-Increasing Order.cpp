class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        vector<int> result;
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);

        sort(nums.begin(), nums.end(), greater<int>());

        int sum = 0;
        for (const auto& num : nums) { // 절반보다 크면 답으로 간주하고 진행
            sum += num;
            result.push_back(num);
            if (sum > TOTAL_SUM / 2) return result;
        }

        return result;
    }
};

// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
