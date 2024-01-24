class Solution {
public:
    bool is_prime(const int n)
    {
        // Corner case
        if (n <= 1) {
            return false;
        }
    
        // Check from 2 to n-1
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
    
        return true;
    }

    int diagonalPrime(const vector<vector<int>>& nums) 
    {
        const size_t LEN = nums.size();
        int max_prime = INT_MIN;

        for (size_t i = 0; i < LEN; ++i) {
            if (is_prime(nums[i][i]) == true) {
                max_prime = max(max_prime, nums[i][i]); // 왼쪽 대각
            } 
            if (is_prime(nums[i][LEN - 1 - i]) == true) {
                max_prime = max(max_prime, nums[i][LEN - i - 1]); // 오른쪽 대각
            } 
        }

        return max_prime != INT_MIN ? max_prime : 0;
    }
};


// https://leetcode.com/problems/prime-in-diagonal/description/

/*

### 한국어 번역

2614. 대각선에서의 소수
난이도: 쉬움
주제: [정보 없음]
회사: [정보 없음]
힌트: 0부터 시작하는 이차원 정수 배열 `nums`가 주어집니다.

`nums`의 대각선 중 하나 이상에 위치한 가장 큰 소수를 반환하세요. 대각선에 소수가 없는 경우 0을 반환합니다.

참고:
- 1보다 크고 1과 자기 자신 이외의 양의 정수 약수가 없는 정수를 소수라고 합니다.
- 정수 `val`이 `nums`의 대각선 중 하나에 위치한다는 것은, `nums[i][i] = val`이거나 `nums[i][nums.length - i - 1] = val`인 정수 `i`가 존재한다는 것을 의미합니다.

위 다이어그램에서 한 대각선은 [1,5,9]이고, 다른 대각선은 [3,5,7]입니다.

#### 예시 1:

입력: nums = [[1,2,3],[5,6,7],[9,10,11]]
출력: 11
설명: 1, 3, 6, 9, 11은 대각선 중 하나 이상에 위치한 유일한 숫자들입니다. 11이 가장 큰 소수이므로, 11을 반환합니다.

#### 예시 2:

입력: nums = [[1,2,3],[5,17,7],[9,11,10]]
출력: 17
설명: 1, 3, 9, 10, 17은 모두 대각선 중 하나 이상에 위치합니다. 17이 가장 큰 소수이므로, 17을 반환합니다.

#### 제약 조건:

- 1 <= nums.length <= 300
- nums.length == nums[i].length
- 1 <= nums[i][j] <= 4*10^6

### 요약

이 문제에서는 주어진 이차원 배열 `nums`의 대각선 중 하나 이상에 위치하는 가장 큰 소수를 찾아 반환하는 것입니다. 대각선에 소수가 없으면 0을 반환합니다.

### 문제 풀이 방향

1. **대각선 요소 추출**: 먼저, 배열의 두 대각선에 있는 모든 요소를 추출합니다. 이는 배열의 각 행에 대해 `nums[i][i]`와 `nums[i][nums.length - i - 1]` 요소를 추출하는 것을 의미합니다.

2. **소수 판별**: 추출된 요소 중에서 소수인지 판별합니다. 이를 위해, 각 요소가 1과 자기 자신만을 약수로 가지는지 확인합니다. 이 과정에서는 소수 판별 알고리즘(예: 에라토스테네스의 체)을 사용할 수 있습니다.

3. **최대 소수 찾기**: 대각선 요소 중에서 소수인 것들을 찾은 후, 이 중에서 가장 큰 값을 찾아 반환합니다. 만약 소수가 없다면 0을 반환합니다.

4. **최적화 고려**: 주어진 제약 조건을 고려할 때, 배열의 크기가 최대 300x300이고 각 요소의 값이 최대 4*10^6이므로, 효율적인 소수 판별 방법을 사용하는 것이 중요합니다.

*/
