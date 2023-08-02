class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        const size_t LENGTH = nums.size();
        map<int, int> freq;
        vector<int> result;

        for (const auto& num : nums) {
            for (const auto& elem : num) {
                ++freq[elem];
            }
        }
        
        for (const auto& elem : freq) {
            if (elem.second == LENGTH) result.push_back(elem.first);
        }

        return result;
    }
};

// https://leetcode.com/problems/intersection-of-multiple-arrays/description/
