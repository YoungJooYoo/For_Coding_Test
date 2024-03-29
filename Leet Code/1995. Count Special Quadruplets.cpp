class Solution {
public:
    int countQuadruplets(const vector<int>& nums) 
    {
        const size_t ARRAY_LENGTH = nums.size();
        int count = 0;

        for (size_t i = 0; i < ARRAY_LENGTH; ++i) {
            for (size_t j = i + 1; j < ARRAY_LENGTH; ++j) {
                for (size_t k = j + 1; k < ARRAY_LENGTH; ++k) {
                    for (size_t l = k + 1; l < ARRAY_LENGTH; ++l) {
                        if (nums[i] + nums[j] + nums[k] == nums[l]) {
                            ++count;
                        }
                    }
                }
            }
        }

        return count;
    }
};

// https://leetcode.com/problems/count-special-quadruplets/description/
