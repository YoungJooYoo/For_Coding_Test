class Solution {
public:
    int maxOperations(vector<int>& nums) 
    {
        const int VALUE = nums[0] + nums[1];
        int count = 0;

        for (size_t i = 0; i < nums.size() - 1; i += 2) {
            const int curr_val = nums[i] + nums[i + 1];
            if (curr_val == VALUE) ++count;
            else return count;
        }

        return count;
    }
};

// https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-i/description/
