class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left; 
        int right;
        int mid;
        vector<int> ans(2, -1); // 길이가2인 벡터를 -1로 초기화
        
        // ans[0] 구하기
        left = 0;
        right = nums.size() - 1;
        while (left <= right) { // 2진 탐색 종료 조건
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
                cout << "left : " << left << endl;  
            }
            else if (nums[mid] > target) {
                right = mid - 1;
                cout << "right : " << right << endl;
            }
            else { // nums[mid] == target, target을 찾은 경우
                if (mid == left || nums[mid] != nums[mid - 1]){
                    ans[0] = mid;
                    cout << "mid : " << mid << endl;
                    break;
                }
                else {
                    right = mid - 1; // ans[0] 구하기
                    ans[0] = mid - 1;
                    cout << "ans[0] : " << ans[0] << endl;
                }
            }
        }

        // ans[1] 구하기
        left = 0; 
        right = nums.size() - 1;
        while (left <= right) { // 2진 탐색 종료 조건
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else { // nums[mid] == target, target을 찾은 경우
                if (mid == right || nums[mid] != nums[mid + 1]){
                    ans[1] = mid;
                    break;
                }
                else {
                    left = mid + 1; // ans[1] 구하기
                    ans[1] = mid + 1;
                }
            }
        }
        
        return ans; 
    }
};

// 정렬된 배열 + 찾는다 + O(log n) = 2진 탐색
        

