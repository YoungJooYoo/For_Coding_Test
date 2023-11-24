class Solution {
public:
    int sumIndicesWithKSetBits(const vector<int>& nums, const int k) 
    {
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            int c = 0;
            int copy = i;
            while (copy != 0) {
                c+= copy & 1; // 비트에 1만 남긴다.
                copy >>= 1; // 비트 밀어내기
            }    
            if (c == k){
                res += nums[i];
            }
        }

        return res;
    }
};

// k의 숫자만큼 비트에 1이 갯수가 동일하게 존재 해야한다.

// https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/description/
