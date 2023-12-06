class Solution {
public:
  int longestAlternatingSubarray(const vector<int>& nums, const int threshold) {
      int ans = 0;  // 가장 긴 부분 배열의 길이를 저장
      int i = 0;    // 현재 인덱스
      int last = INT_MAX;  // 짝수 시작 부분 배열의 시작 인덱스

      // nums 배열을 순회
      while (i < nums.size()) {
          // 현재 요소가 임계값을 초과하거나 이전 요소와 홀/짝이 같은 경우
          if (nums[i] > threshold || (i > 0 && (nums[i] % 2) == (nums[i - 1] % 2))) {
              ans = max(ans, i - last); // 부분 배열 길이를 계산하여 ans 업데이트
              last = INT_MAX;  // last 초기화
          }
          // 현재 요소가 임계값 이하이고 짝수인 경우, last 업데이트
          if (last == INT_MAX && nums[i] <= threshold && nums[i] % 2 == 0) {
              last = i;
          };
          ++i;  // 인덱스 증가
      }
      ans = max(ans, i - last);  // 마지막 부분 배열 길이 계산

      return ans;  // 결과 반환
  }
};

/*
`i - last`는 현재 인덱스 `i`와 마지막으로 짝수로 시작한 부분 배열의 시작 인덱스 `last` 사이의 거리를 계산합니다. 이 값은 현재 고려 중인 부분 배열의 길이를 나타냅니다. 
예를 들어, `i`가 5이고 `last`가 2라면, `i - last`는 3이 되며, 이는 현재 부분 배열이 3개의 요소로 이루어져 있음을 의미합니다.
*/

// https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/
