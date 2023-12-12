class Solution {
public:
    std::vector<int> findIntersectionValues(const vector<int>& nums1, const vector<int>& nums2) 
    {
        const set<int> set1(nums1.begin(), nums1.end());
        const set<int> set2(nums2.begin(), nums2.end());
        int count1 = 0;
        int count2 = 0;

        for (const int& num : nums1) {
            if (set2.count(num)) {
                ++count1;
            }
        }
        for (const int& num : nums2) {
            if (set1.count(num)) {
                ++count2;
            }
        }

        return {count1, count2};
    }
};

// https://leetcode.com/problems/find-common-elements-between-two-arrays/description/
