class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        const size_t n = nums.size();
        int count = 0;

        if (n == 1) {
            return 0;
        }
            
        for (size_t i = 1; i < n; i++) {
            const int sticktly_increasing_num = nums[i - 1] + 1;
            if (nums[i - 1] >= nums[i]) {
                count += abs(sticktly_increasing_num - nums[i]);
                nums[i] = sticktly_increasing_num;
            }
        }

        return count;
    }
};

/*
example 2)
1 5 2 4 1
1 5 6 7 8 -> 증가된 배열
0 0 4 3 7 -> 증가된 숫자  => 14
*/

// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/description/
