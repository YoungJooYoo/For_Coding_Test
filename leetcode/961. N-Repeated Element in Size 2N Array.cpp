class Solution {
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        int result = 0;

        for (const auto& num : nums) {
            freq[num]++;
            if (freq[num] > 1) return num;
        }

        return result; 
    }
};

// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/
