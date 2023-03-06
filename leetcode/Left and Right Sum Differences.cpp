class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) 
    {
        const int SIZE = nums.size();
        vector<int> left_sum(SIZE, 0);
        vector<int> right_sum(SIZE, 0);
        int sum = 0;

        for (int i = 0, j = i + 1; i < SIZE; ++i) {
            sum += nums[i];
            if (j < SIZE) {
                left_sum[j++] = sum;
            }
        }
        sum = 0;
        for (int i = SIZE - 1, j = i - 1; i >= 0; --i) {
            sum += nums[i];
            if (j >= 0) {
                right_sum[j--] = sum;
            }
        }
        
        for (int i = 0; i < SIZE; ++i) {
            nums[i] = abs(left_sum[i] - right_sum[i]);
        }

        return nums;
    }
};

// https://leetcode.com/problems/left-and-right-sum-differences/description/
