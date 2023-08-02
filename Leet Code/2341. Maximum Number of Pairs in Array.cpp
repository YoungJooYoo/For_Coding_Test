class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        int length = 0;
        int pair_count = 0;

        for (const auto& num : nums) {
            ++freq[num];
        }
        
        for (const auto& elem : freq) {
            pair_count += elem.second / 2; // pair count,
            length += elem.second % 2; // length
        }

        return {pair_count, length};
    }
};

// https://leetcode.com/problems/maximum-number-of-pairs-in-array/description/
