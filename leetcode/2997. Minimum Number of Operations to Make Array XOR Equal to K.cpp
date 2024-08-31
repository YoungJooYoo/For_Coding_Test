class Solution 
{
public:
    int minOperations(const vector<int>& nums, const int k) 
    {
        int totalXOR = 0;

        for (const auto& num : nums)
        {
            totalXOR ^= num;
        }

        const uint32_t DIFF = totalXOR ^ k;

        return popcount(DIFF);
    }
};


// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/
/*

### 문제 설명

당신은 0-인덱스 정수 배열 `nums`와 양의 정수 `k`를 받았습니다.

다음과 같은 연산을 배열에 원하는 만큼 수행할 수 있습니다:

- 배열의 임의의 요소를 선택하고, 이 요소의 이진 표현에서 비트를 뒤집습니다. 비트를 뒤집는다는 것은 0을 1로 또는 1을 0으로 바꾸는 것을 의미합니다.

모든 최종 배열 요소의 비트별 XOR 결과가 `k`와 같아지도록 하는 데 필요한 최소 연산 횟수를 반환하세요.

참고로, 요소의 이진 표현에서 선행하는 0 비트를 뒤집을 수 있습니다. 예를 들어, 숫자 `(101)₂`에서 네 번째 비트를 뒤집어 `(1101)₂`로 만들 수 있습니다.

### 예제

**예제 1**:
- 입력: `nums = [2,1,3,4]`, `k = 1`
- 출력: `2`
- 설명:
  - 다음과 같은 연산을 수행할 수 있습니다:
    - 요소 `3 == (011)₂`를 선택하여 첫 번째 비트를 뒤집어 `(010)₂ == 2`로 바꿉니다. `nums`는 `[2,1,2,4]`가 됩니다.
    - 요소 `2 == (010)₂`를 선택하여 세 번째 비트를 뒤집어 `(110)₂ == 6`로 바꿉니다. `nums`는 `[6,1,2,4]`가 됩니다.
  - 최종 배열 요소들의 XOR 결과는 `(6 XOR 1 XOR 2 XOR 4) == 1 == k`가 됩니다.
  - `k`와 같은 XOR을 얻기 위해서는 최소한 2번의 연산이 필요합니다.

**예제 2**:
- 입력: `nums = [2,0,2,0]`, `k = 0`
- 출력: `0`
- 설명: 배열 요소들의 XOR은 `(2 XOR 0 XOR 2 XOR 0) == 0 == k`이므로, 연산이 필요하지 않습니다.

### 제약 조건
- `1 <= nums.length <= 105`
- `0 <= nums[i] <= 106`
- `0 <= k <= 106`

*/
