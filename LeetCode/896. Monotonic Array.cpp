class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        const size_t SIZE = nums.size();
        bool increase = true;
        bool decrease = true;

        for (size_t i = 0; i < SIZE - 1; ++i) {
            if (nums[i] > nums[i + 1]) increase = false;
            if (nums[i] < nums[i + 1]) decrease = false;
            if((increase | decrease) == false) return false;
        }

        return true;
    }
};

// https://leetcode.com/problems/monotonic-array/description/
