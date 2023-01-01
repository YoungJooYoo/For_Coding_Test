class Solution {
public:
    bool findSubarrays(vector<int>& nums) 
    {
        unordered_map<int, int> freq;

        for (size_t i = 0; i < nums.size() - 1; ++i) {
            int sum = nums[i] + nums[i + 1];
            freq[sum]++;
        }

        for (const auto& elem : freq) {
            if (elem.second != 1) {
                return true;
            } 
        }

        return false;
    }
};

// https://leetcode.com/problems/find-subarrays-with-equal-sum/description/
