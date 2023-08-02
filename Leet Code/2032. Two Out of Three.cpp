class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) 
    {
        unordered_map<int, int> freq;
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        unordered_set<int> set3(nums3.begin(), nums3.end());
        vector<int> result;

        for (const auto& num : set1) {
            freq[num]++;
        }
        for (const auto& num : set2) {
            freq[num]++;
        }
        for (const auto& num : set3) {
            freq[num]++;
        }

        for (const auto& elem : freq) {
            if (elem.second >= 2) result.push_back(elem.first);
        }

        return result;
    }
};

// https://leetcode.com/problems/two-out-of-three/description/
