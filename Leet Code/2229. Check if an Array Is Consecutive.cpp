class Solution {
public:
    bool isConsecutive(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] == 1) continue;
            else return false;
        }

        return true;    
    }
};

// https://leetcode.com/problems/check-if-an-array-is-consecutive/description/
