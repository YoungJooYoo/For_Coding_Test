class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        unordered_map<int, bool> mp;
        int count = 0;

        for (const auto& num : nums) {
            mp[num] = true;
        }

        for (const auto& i : nums) {
            if (mp[i + diff] == true && mp[i + (2 * diff)] == true) ++count; // 존재하지 않으면 값이 0이다.
        }

        return count;
    }
};

// https://leetcode.com/problems/number-of-arithmetic-triplets/description/
