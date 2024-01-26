class Solution {
public:
    vector<int> findErrorNums(const vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        map<int, int> freq;

        for (const auto num : nums) {
            ++freq[num];
        }

        int duplicate = 0;
        int missing = 0;
        for (size_t i = 1; i <= LEN; ++i) {
            if (freq.find(i) == freq.end()) {
                missing = i; // 누락된 숫자 찾기
            }
            if (freq[i] == 2) {
                duplicate = i; // 중복된 숫자 찾기
            }
        }

        return {duplicate, missing};
    }
};

// https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22
