class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        for (const auto& num1 : nums1) {
            bool is_in = binary_search(nums2.begin(), nums2.end(), num1);
            if (is_in == true) return num1;
        }

        return -1;
    }
};

https://leetcode.com/problems/minimum-common-value/description/
