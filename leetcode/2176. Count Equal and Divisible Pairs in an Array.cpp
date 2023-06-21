class Solution {
public:
    int countPairs(vector<int>& nums, int k) 
    {
        int count = 0;
        const size_t LEN = nums.size();

        for (size_t i = 0; i < LEN; ++i) {
            for (size_t j = i + 1 ; j < LEN; ++j) {
                if (nums[i] == nums[j]) {
                    int temp = i * j;
                    if (temp % k == 0) ++count;
                }
            }
        }

        return count;
    }
};


// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/
