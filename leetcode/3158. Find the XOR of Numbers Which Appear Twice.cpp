class Solution {
public:
    int duplicateNumbersXOR(const vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        
        for (const auto& num : nums)
        {
            ++freq[num];
        }

        if (freq.size() == nums.size())
        {
            return 0;
        }

        int result = 0;

        for (const auto& elem : freq)
        {
            if (elem.second > 1)
            {
                result ^= elem.first;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/
