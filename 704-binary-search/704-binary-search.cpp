class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1; // nums의 마지막 인덱스
        int mid;
        
        while(start <= end) {
            mid = start + ((end- start) / 2);
            if (nums[mid] < target){
                start = mid + 1;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else { // mid == target
                return mid;
            }
        }
        
        return -1;
    }
};