class Solution
{
public:
    int totalReplacements(vector<int>& ranks) const
    {
        const size_t LENGTH = ranks.size();
        int replaceCount = 0;
   
        assert(MIN_LENGTH <= LENGTH && LENGTH <= MAX_LENGTH);

        for (size_t i = 1; i < LENGTH; ++i)
        {
            assert(MIN_RANK <= ranks[i] && ranks[i] <= MAX_RANK);
            if (ranks[0] > ranks[i])
            {
                swap(ranks[0], ranks[i]);
                ++replaceCount;
            }
        }

        return replaceCount;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,   // 문제 조건: 1 <= ranks.length <= 1e5
        MIN_RANK   = 1,
        MAX_RANK   = 100000    // 문제 조건: 1 <= ranks[i] <= 1e5
    };
};

// https://leetcode.com/problems/number-of-student-replacements/

/*

## 3616. 학생 교체 횟수

**난이도:** Medium
**주제:** 배열, 시뮬레이션

정수 배열 `ranks`가 주어집니다.
`ranks[i]`는 도착 순서대로 i번째 학생의 **등수**를 나타내며, **숫자가 작을수록 더 좋은 등수**입니다.

* 처음에는 **첫 번째 학생**이 기본적으로 선택됩니다.
* **교체(replacement)** 는 더 좋은 등수를 가진 학생이 도착해 현재 선택된 학생을 대체할 때 발생합니다.

**목표:** 총 교체 횟수를 반환하세요.

---

### 예제 1

```
입력: ranks = [4, 1, 2]
출력: 1
```

**설명:**

1. 첫 번째 학생 `4`가 초기 선택됩니다.
2. 두 번째 학생 `1`은 현재 학생(4)보다 더 좋은 등수이므로 교체가 발생합니다.
3. 세 번째 학생 `2`는 현재 학생(1)보다 등수가 나쁘므로 교체가 없습니다.

따라서 교체 횟수 = **1**.

---

### 예제 2

```
입력: ranks = [2, 2, 3]
출력: 0
```

**설명:**

1. 첫 번째 학생 `2`가 초기 선택됩니다.
2. 두 번째 학생 `2`와 세 번째 학생 `3` 모두 현재 학생(2)보다 등수가 더 좋지 않으므로 교체가 없습니다.

따라서 교체 횟수 = **0**.

---

### 제약 조건

* `1 <= ranks.length <= 10^5`
* `1 <= ranks[i] <= 10^5`

---

💡 **힌트**

1. 배열을 왼쪽에서 오른쪽으로 순회하며, 현재까지의 **최고(최소) 등수**를 기록합니다.
2. 새로운 학생의 등수가 현재 최고 등수보다 **작으면** 교체 횟수를 늘리고 최고 등수를 갱신합니다.

---


*/
