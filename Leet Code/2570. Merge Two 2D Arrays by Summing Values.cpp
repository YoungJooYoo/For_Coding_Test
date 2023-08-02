class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        vector<vector<int>> result;

        map<int, int> mp;

        for (const auto num : nums1) {
            mp[num[0]] += num[1];
        }
        for (const auto num : nums2) {
            mp[num[0]] += num[1];
        }

        for (const auto& elem : mp) {
            vector<int> temp;
            temp.push_back(elem.first);
            temp.push_back(elem.second);
            result.push_back(temp);
        }

        return result;
    }
};

// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/
