class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) {
            return false;
        }

        sum = sum >> 1; // sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (const auto num : nums) {
            for (int i = sum; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[sum];
    }
};

/*
풀이법 :

2개의 서브셋을 찾아야 하므로,
전체합에서 절반이 되는 값을 찾는 것이 문제 푸는 방향의 키이다.


ex) 
Input: nums = [1,5,11,5]
resultant_sum = 1 + 5 + 11 + 5 = 22 [EVEN NUMBER]

여기서 최종합이 짝수가아니면, 답을 구할 수 없으므로 false 반환


*/

// https://leetcode.com/problems/partition-equal-subset-sum/description/
