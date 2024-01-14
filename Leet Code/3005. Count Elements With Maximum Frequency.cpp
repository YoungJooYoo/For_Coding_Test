class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        int max_freq = 0;
        int result = 0;

        for (const auto& num : nums) {
            ++freq[num];
            max_freq = max(max_freq, freq[num]);
        }

        for (const auto& elem : freq) {
            if (elem.second == max_freq) result += elem.second;
        }

        return result;
    }
};

// https://leetcode.com/problems/count-elements-with-maximum-frequency/description/
