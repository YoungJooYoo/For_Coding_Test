class Solution {
public:
    bool isPossibleToSplit(const vector<int>& nums) 
    {
        unordered_map<int, int> freq;

        for (const auto num : nums) {
            ++freq[num];
        }

        for (const auto elem : freq) {
            if (elem.second > 2) {
                return false;
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/split-the-array/description/
