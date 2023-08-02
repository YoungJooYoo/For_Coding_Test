#include <assert.h>

class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        const size_t NUMS_SIZE = nums.size();
        unordered_map<int, int> freq;

        assert(NUMS_SIZE % 2 == 0);

        for (const auto& num : nums) {
            freq[num]++;
        }

        for (const auto& elem : freq) {
            if (elem.second % 2  != 0) {
                return false;
            }
        }
        
        return true;
    }
};

// https://leetcode.com/problems/divide-array-into-equal-pairs/description/
