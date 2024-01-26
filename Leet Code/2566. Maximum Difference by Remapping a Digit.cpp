class Solution {
public:
    int minMaxDifference(const int num) 
    {
        string max_num = to_string(num);
        string min_num = to_string(num);
        size_t LENGTH = max_num.size();
        
        // 최대값을 위해 첫 번째 9가 아닌 숫자 찾기
        char firstNonNineChar = '9';
        for (size_t i = 0; i < LENGTH; ++i) {
            if (max_num[i] != '9') {
                firstNonNineChar = max_num[i];
                break;
            }
        }

        // 해당 숫자를 모두 9로 변경
        for (size_t i = 0; i < LENGTH; ++i) {
            if (max_num[i] == firstNonNineChar) {
                max_num[i] = '9';
            }
        }

        // 첫 번째 숫자를 모두 0으로 변경
        const char firstChar = min_num[0];
        for (size_t i = 0; i < LENGTH; ++i) {
            if (min_num[i] == firstChar) {
                min_num[i] = '0';
            }
        }

        return stoi(max_num) - stoi(min_num);
    }
};


// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/

/*

### 번역

2566. 숫자 재매핑을 통한 최대 차이
난이도: 쉬움
주제: [정보 없음]
회사: [정보 없음]
힌트: 정수 `num`이 주어집니다. Bob이 10개의 가능한 숫자 중 하나(0에서 9까지)를 다른 숫자로 교묘하게 재매핑할 것임을 알고 있습니다.

`num`에서 정확히 한 자리 숫자를 재매핑함으로써 만들 수 있는 최대값과 최소값의 차이를 반환하세요.

참고 사항:
- Bob이 숫자 `d1`을 다른 숫자 `d2`로 재매핑할 때, `num`에서 `d1`의 모든 발생을 `d2`로 대체합니다.
- Bob은 숫자를 그대로 재매핑할 수도 있으며, 이 경우 `num`은 변경되지 않습니다.
- Bob은 최소값과 최대값을 얻기 위해 각각 다른 숫자를 재매핑할 수 있습니다.
- 재매핑 후의 결과 숫자는 선행 0을 포함할 수 있습니다.

#### 예시 1:

입력: num = 11891
출력: 99009
설명: 
최대값을 얻기 위해 Bob은 숫자 1을 숫자 9로 재매핑하여 99899를 만들 수 있습니다.
최소값을 얻기 위해 Bob은 숫자 1을 숫자 0으로 재매핑하여 890을 만들 수 있습니다.
이 두 숫자의 차이는 99009입니다.

#### 예시 2:

입력: num = 90
출력: 99
설명: 
함수가 반환할 수 있는 최대값은 99입니다(0을 9로 대체한 경우), 최소값은 0입니다(9를 0으로 대체한 경우).
따라서, 99를 반환합니다.

#### 제약 조건:

- 1 <= num <= 10^8

### 요약

이 문제에서는 주어진 정수 `num`에서 정확히 한 자리 숫자를 다른 숫자로 재매핑하여 만들 수 있는 최대값과 최소값의 차이를 찾는 것입니다.

### 문제 풀이 방향

1. **최대값과 최소값 찾기**: `num`에서 각 숫자를 다른 숫자로 바꾸어 최대값과 최소값을 찾습니다. 
   - 최대값을 찾기 위해서는 가장 큰 영향을 주는 낮은 숫자를 9로 변경합니다.
   - 최소값을 찾기 위해서는 가장 큰 영향을 주는 높은 숫자를 0으로 변경합니다.

2. **재매핑 규칙 적용**: 모든 숫자의 발생을 해당 숫자로 재매핑하고 새로운 숫자를 계산합니다.

3. **최대값과 최소값의 차이 계산**: 계산된 최대값과 최소값의 차이를 계산합니다.

4. **특수 케이스 고려**: 선행 0이 발생할 수 있으므로, 재매핑 후의 숫자를 올바르게 처리해야 합니다.
*/
