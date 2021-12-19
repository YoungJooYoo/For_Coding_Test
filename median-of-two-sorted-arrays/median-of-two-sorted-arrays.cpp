class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const size_t nums1_length = nums1.size();
        const size_t nums2_length = nums2.size();
        size_t nums_length;
        size_t mid;
        vector<double> nums;
        double ans = 0;
        
        // 주어진 두 배열을 합치기 그냥 합치고 sort
        for (size_t i = 0; i < nums1_length; i++) {
            nums.push_back(nums1[i]);
        }
        for (size_t i = 0; i < nums2_length; i++) {
            nums.push_back(nums2[i]);
        }
        
        sort(nums.begin(), nums.end());
        nums_length = nums.size();
        
        if (nums_length == 1) {
            return nums[0];
        }
        
        if(nums_length % 2 == 0) { // 합쳐진 배열의 길이가 짝수인 경우
            mid = (0 + nums_length - 1) / 2;
            ans = (nums[mid] + nums[mid + 1]) / 2;
        }
        else { // 합쳐진 배열의 길이가 홀수인 경우
            mid = (0 + nums_length) / 2;
            ans = nums[mid]; // 합쳐진 두 배열에서 중간 값 추출하기
            return ans;
        }
        
        return ans;
    }
};