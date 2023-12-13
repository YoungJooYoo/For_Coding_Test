class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        int count = 0;

        // sort 1
        while (nums[0] != 1) {
            for (size_t i = 1; i < LEN; ++i) {
                if (nums[i] == 1) {
                    swap(nums[i - 1], nums[i]);
                    ++count;
                    break;
                }
            }
        } 
        // sort n
        while (nums[LEN - 1] != LEN) {
            for (size_t i = 0; i < LEN - 1; ++i) {
                if (nums[i] == LEN) {
                    swap(nums[i], nums[i + 1]);
                    ++count;
                    break;
                }
            }
        }

        return count;
    }
};

/*
1과 n이 시작과 끝으로 가도록 최소로 정렬하는 횟수
*/

// https://leetcode.com/problems/semi-ordered-permutation/description/
