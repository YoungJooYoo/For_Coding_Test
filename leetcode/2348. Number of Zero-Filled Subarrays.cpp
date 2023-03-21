class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans = 0;
        long long numSubarray = 0;
        
        // 누적 카운트로 1개인경우 2개인경우 n개인경우를 동시에 카운트 해서 누적시킨다
        for (const auto& num : nums) {
            if (num == 0) ++numSubarray;
            else numSubarray ^= numSubarray;
            ans += numSubarray;
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
