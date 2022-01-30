class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int mid;
        int end = nums.size() - 1; // nums last index
        
        while (start <= end) {
            mid = start + (end - start) / 2; // or //mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[start]) {
                //left half is sorted
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else {
                //right half is sorted
                if (target  > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        
        return -1;
    }
};

/*
풀이법 :
mid 인덱스 기준으로 좌측 오른차순 정렬 우측 오른차순 정렬로 나뉘었다.

target을 중간 인덱스 값과, 마지막 인덱스 과 비교해서,
어디서 탐색 시작할지 경정
target이 오른쪽 작은 숫자 배열의 최대 값보다 크면 왼쪽 배열탐색
이런식으로 나아간다.

*/