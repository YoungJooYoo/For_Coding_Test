class Solution {
public:
    int maxSubarrayLength(const vector<int>& nums) 
    {
        const size_t LEN = nums.size(); // 배열의 길이를 한 번만 계산
        int maxLength = 0; // 최대 부분배열 길이
        size_t startIndex = 0; // 시작 인덱스
        size_t nextIndex = 1; // 다음 탐색 인덱스

        while (startIndex < LEN) {
            // 다음 요소 중 현재 요소보다 작은 첫 번째 요소 탐색
            for (size_t i = nextIndex; i < LEN; ++i) {
                if (nums[startIndex] > nums[i]) {
                    const int currentLength = i - startIndex + 1;
                    maxLength = max(maxLength, currentLength);
                    nextIndex = i;
                }
            }

            // 다음 시작 요소 찾기(현재 요소보다 큰 첫 번째 요소)
            bool noNextStart = true;
            for (size_t i = startIndex + 1; i < LEN; ++i) {
                if (nums[startIndex] < nums[i]) {
                    startIndex = i;
                    noNextStart = false;
                    break;
                }
            }

            if (noNextStart ==  true) // 더 이상 탐색할 다음 요소가 없는 경우 반복 종료
                break;

            // 다음 탐색을 위해 nextIndex를 업데이트
            nextIndex = startIndex + 1;
        }

        return maxLength;
    }
};

//  https://leetcode.com/problems/maximum-length-of-semi-decreasing-subarrays/description/

/*

### 한국어 번역

2863. 반감소 부분배열의 최대 길이
난이도: 중간
주제: [정보 없음]
회사: [정보 없음]
힌트: [정보 없음]

정수 배열 `nums`가 주어집니다.

`nums`의 가장 긴 반감소 부분배열의 길이를 반환하고, 해당하는 부분배열이 없으면 0을 반환합니다.

부분배열은 배열 내의 연속적이고 비어 있지 않은 요소의 순서입니다.
비어 있지 않은 배열이 반감소한다는 것은 첫 번째 요소가 마지막 요소보다 엄격하게 크다는 것을 의미합니다.

### 요약

주어진 정수 배열에서 첫 번째 요소가 마지막 요소보다 엄격하게 큰 부분배열, 즉 반감소 부분배열 중 가장 긴 것의 길이를 찾아 반환하는 문제입니다. 만약 그러한 부분배열이 없다면 0을 반환합니다.

### 문제 풀이 방향

1. **브루트 포스(Brute Force) 방식**: 배열의 모든 가능한 부분배열을 순회하며 첫 번째 요소가 마지막 요소보다 큰 경우를 찾고, 그 중 가장 긴 길이를 기록합니다. 이 방식은 배열의 크기가 작을 때 유용할 수 있으나, 배열의 크기가 클 경우 시간 복잡도가 매우 높아집니다.

2. **투 포인터(Two Pointers) 방식**: 시작 지점(`start`)을 고정하고, 끝 지점(`end`)을 배열 끝까지 이동시키면서 조건을 만족하는 가장 긴 부분배열을 찾습니다. 조건을 만족하지 않을 때까지 `end`를 이동시키고, 조건을 만족하는 부분배열의 길이를 계산합니다. 이후, `start`를 한 칸 이동시키고 같은 과정을 반복합니다. 이 방식은 브루트 포스 방식에 비해 효율적입니다.

3. **동적 계획법(Dynamic Programming) 사용**: 배열의 각 위치에서 끝나는 가장 긴 반감소 부분배열의 길이를 저장하고, 이 정보를 바탕으로 전체 배열에서의 최대 길이를 계산할 수 있습니다. 이 방법은 구현이 복잡할 수 있으나, 효율적인 해결 방식입니다.

문제의 조건과 배열의 크기를 고려하여 가장 적합한 방식을 선택하는 것이 중요합니다.

*/
