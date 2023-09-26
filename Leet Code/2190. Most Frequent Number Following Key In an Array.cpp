class Solution {
public:
    int mostFrequent(const vector<int>& nums, const int key) 
    {
        map<pair<int, int> ,int> freq; // pair(key-target) - count
        const size_t LEN = nums.size();
        int max_count = INT_MIN;

        for (size_t i = 0; i < LEN - 1; ++i) {
            if (nums[i] == key) {
                ++freq[make_pair(nums[i], nums[i + 1])]; // count -> {key, target} 
                max_count = max(max_count, freq[make_pair(nums[i], nums[i + 1])]); // store max_count
            }
        }

        // return the max target
        for (const auto& elem : freq) {
            if (elem.second == max_count) {
                return elem.first.second;
            }
        }

        return 0;
    }
};

// https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/
