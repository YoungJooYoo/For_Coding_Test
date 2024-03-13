class Solution {
public:
    bool isMajorityElement(const vector<int>& nums, const int target) 
    {
        const size_t MAJORITY_COUNT = nums.size() / 2;
        size_t count = 0;

        for (const auto num : nums) {
            if (num == target) {
                ++count;
            }
        }

        return count > MAJORITY_COUNT ? true : false;
    }
};

// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/description/
