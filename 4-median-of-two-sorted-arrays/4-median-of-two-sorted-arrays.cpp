class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const size_t nums1_length = nums1.size();
        const size_t nums2_length = nums2.size();
        size_t nums_length;
        size_t mid;
        vector<double> nums;
        double ans = 0;
        
        // 주어진 두 배열을 합치기 nums1 부터 집어넣기
        for (size_t i = 0; i < nums1_length; i++) {
            nums.push_back(nums1[i]);
        }
        // 주어진 두 배열을 합치기 nums2 이어서 집어넣기
        for (size_t i = 0; i < nums2_length; i++) {
            nums.push_back(nums2[i]);
        }
        
        // 합쳐진 배열을 정렬하기
        sort(nums.begin(), nums.end());
        nums_length = nums.size(); // 배열의 길이를 통해 중간값 인덱스를 구할 것
        
        // 최저 길이가 1인 경우의 처리
        if (nums_length == 1) {
            return nums[0];
        }
        
        // 배열의 길이가 홀수인 경우, 짝수인 경우 나누어서 문제에 조건에 따라 구하기
        if(nums_length % 2 == 0) { // 합쳐진 배열의 길이가 짝수인 경우, 중간인덱스가 2개이므로
            mid = (nums_length - 1) / 2; // mid값이 2개존재, mid의 첫번쨰 구하기, 홀수 배열처럼 정가운데 mid가 하나 있는게 아니므로
            ans = (nums[mid] + nums[mid + 1]) / 2; // mid의 두번째 = mid + 1
            return ans;
        } // mid에서 nums_length - 1의 의미는, 일부러 길이를 홀수로 만들어 mid를 구하기 위해
        else { // 합쳐진 배열의 길이가 홀수인 경우
            mid = nums_length / 2; // 홀수인 경우 mid가 하나이다.
            ans = nums[mid]; // 합쳐진 두 배열에서 중간 값 추출하기
            return ans;
        }
        
        return ans;
    }
};