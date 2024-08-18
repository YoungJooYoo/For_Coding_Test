class Solution 
{
public:
    bool containsPattern(const vector<int>& arr, const int m, const int k) 
    {
        const int n = arr.size();

        for (int i = 0; i <= n - m * k; ++i) 
        {
            bool match = true;
            for (int j = 0; j < m * k; ++j) 
            {
                if (arr[i + j] != arr[i + j % m]) 
                {
                    match = false;
                    break;
                }
            }
            if (match == true) return true;
        }

        return false;
    }
};

// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/description/

/*
다음은 LeetCode 문제 1566번의 한국어 번역입니다:

---

### 1566. 길이 M이 K번 이상 반복된 패턴 감지하기

**난이도: 쉬움**

#### 문제 설명

양의 정수로 이루어진 배열 `arr`이 주어질 때, 길이가 `m`인 패턴이 `k`번 이상 반복되는지 찾으세요.

패턴은 하나 이상의 값으로 구성된, 연속적으로 반복되는 중첩되지 않는 하위 배열(연속된 부분 수열)입니다. 패턴은 그 길이와 반복 횟수로 정의됩니다.

길이가 `m`인 패턴이 `k`번 이상 반복된다면 `true`를 반환하고, 그렇지 않다면 `false`를 반환하세요.

#### 예제

**예제 1**:
- 입력: `arr = [1,2,4,4,4,4]`, `m = 1`, `k = 3`
- 출력: `true`
- 설명: 길이 1인 패턴 (4)은 4번 연속해서 반복됩니다. 패턴이 `k`번 이상 반복될 수 있지만 그보다 적게 반복될 수는 없습니다.

**예제 2**:
- 입력: `arr = [1,2,1,2,1,1,1,3]`, `m = 2`, `k = 2`
- 출력: `true`
- 설명: 길이 2인 패턴 (1,2)이 2번 연속해서 반복됩니다. 또 다른 유효한 패턴 (2,1)도 2번 반복됩니다.

**예제 3**:
- 입력: `arr = [1,2,1,2,1,3]`, `m = 2`, `k = 3`
- 출력: `false`
- 설명: 길이 2인 패턴 (1,2)은 2번만 반복됩니다. 길이 2인 패턴이 3번 이상 반복되는 경우는 없습니다.

#### 제약 조건

- `2 <= arr.length <= 100`
- `1 <= arr[i] <= 100`
- `1 <= m <= 100`
- `2 <= k <= 100`

---

*/
