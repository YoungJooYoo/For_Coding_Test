class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) 
    {
        int size = nums1.size();
        int sum = 0;
        
        sort(nums1.begin(), nums1.end()); 
        sort(nums2.begin(), nums2.end());
        
        for (int i = 0, j = size - 1; i < size; i++) {
            sum += nums1[i] * nums2[j];
            j--;
        }
        
        return sum;
    }
};