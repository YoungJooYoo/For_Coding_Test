class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        const size_t nums1_length = nums1.size();
        const size_t nums2_length = nums2.size();
        size_t check[1001] = {0, }; // 0 ~ 1000
        vector<int> result;
            
        for (size_t i = 0; i < nums1_length; i++) {
            for (size_t j = 0; j < nums2_length; j++) {
                if (nums1[i]== nums2[j] && check[nums1[i]] == 0) {
                    check[nums1[i]] = 1;
                    result.push_back(nums1[i]);
                }
            }
        }
        
        return result;
    }
};