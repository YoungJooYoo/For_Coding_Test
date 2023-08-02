class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> pos;
        vector<int> result;

        for (size_t i = 0; i < nums2.size(); ++i) {
            pos[nums2[i]] = i;    
        }

        for (const auto& num : nums1) {
            result.push_back(pos[num]);
        }
        
        return result;    
    }
};

// https://leetcode.com/problems/find-anagram-mappings/description/
