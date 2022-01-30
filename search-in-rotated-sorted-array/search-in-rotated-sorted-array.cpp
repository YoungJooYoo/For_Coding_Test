class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int mid;
        int end = nums.size() - 1; // nums last index
        
        while (start <= end) {
            mid = start + (end - start) / 2; // or mid = (start + end) / 2;
            if (nums[mid] == target) { 
                return mid;
            }
            if (nums[mid] >= nums[start]) {
                //left half is sorted
                if (target >= nums[start] && target < nums[mid]) { // 좌측 배열안에 범위인지 체크
                    end = mid - 1;
                }
                else { // 좌측배열이 아닌 경우라면
                    start = mid + 1;
                }
            }
            else {
                //right half is sorted
                if (target  > nums[mid] && target <= nums[end]) { // 우측 배열 범위인지 체크
                    start = mid + 1;
                }
                else { // 우측 배열이 아닌 경우라면
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
즉  {4 5 6 7 기준 0 1 2} 기준 문자로 좌우 정렬된 배열 2가지로 나눌 수 있다.
2진 탐색해서 현재 target 값이 저 두 배열 사이에서 어느 위치에 있는지 체크하는 것이 핵심이다.

target을 중간 인덱스 값과, 마지막 인덱스 과 비교해서,
어디서 탐색 시작할지 경정
target이 오른쪽 작은 숫자 배열의 최대 값보다 크면 왼쪽 배열탐색
이런식으로 나아간다.

*/