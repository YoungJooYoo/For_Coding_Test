class Solution {
public:
    int minOperations(const int n) 
    {
        vector<int> nums;
        int sum = 0;
        int count = 0;

        // 수렴해야할 중간값 구하기
        for (int i = 0; i < n; ++i) {
            const int value = (2 * i) + 1;
            nums.push_back(value);
            sum += value;
        }
        sum = sum / n;

        // 중간값으로 수렴하는 로직
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (nums[i] != sum && nums[j] != sum) {
                const int temp = abs(nums[i] - sum);
                count += temp;
            }
            ++i;
            --j;
        }

        return count;
    }
};

// https://leetcode.com/problems/minimum-operations-to-make-array-equal/description/

/*

한국어 번역
문제: 동일한 값 만들기
난이도: 중간
주제: [정보 없음]
회사: [정보 없음]
힌트: arr 배열의 길이 n이 있으며, arr[i] = (2 * i) + 1로 모든 유효한 i 값(즉, 0 <= i < n)에 대해 정의됩니다.

한 번의 연산에서, 0 <= x, y < n 인 두 인덱스 x와 y를 선택하고 arr[x]에서 1을 빼고 arr[y]에 1을 더할 수 있습니다(즉, arr[x] -=1 및 arr[y] += 1을 수행). 목표는 배열의 모든 요소를 동일하게 만드는 것입니다. 배열의 모든 요소를 몇 가지 연산을 통해 동일하게 만들 수 있음이 보장됩니다.

정수 n, 배열의 길이가 주어졌을 때, arr의 모든 요소를 동일하게 만들기 위해 필요한 최소 연산 횟수를 반환하세요.

예시 1:
입력: n = 3
출력: 2
설명: arr = [1, 3, 5]
첫 번째 연산에서 x = 2, y = 0을 선택하면, arr은 [2, 3, 4]가 됩니다.
두 번째 연산에서 x = 2, y = 0을 다시 선택하면, arr은 [3, 3, 3]이 됩니다.

예시 2:
입력: n = 6
출력: 9

제약 조건:
1 <= n <= 10^4
요약
이 문제는 길이가 n인 배열 arr에서 모든 요소가 동일한 값이 되도록 만드는 데 필요한 최소 연산 횟수를 찾는 문제입니다. 배열 arr의 각 요소는 arr[i] = (2 * i) + 1로 정의됩니다.

문제 풀이 방향
수학적 접근: 배열이 홀수 개의 요소를 가지고 있으므로, 중간값을 목표 값으로 설정할 수 있습니다. 배열의 모든 값은 이 중간값으로 수렴해야 합니다.

중간값 계산: n이 주어졌을 때, 중간값을 계산합니다. 예를 들어, n = 3인 경우 중간값은 3입니다.

연산 횟수 계산: 중간값과 배열의 각 요소 사이의 차이를 계산하여, 이 차이들의 합이 필요한 총 연산 횟수가 됩니다.

최적화: 모든 연산은 대칭적으로 발생하므로, 배열의 절반에 대해서만 연산 횟수를 계산하고 그 값을 두 배 해서 반환할 수 있습니다.

*/
