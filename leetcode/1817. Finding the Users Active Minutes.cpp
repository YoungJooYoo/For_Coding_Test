class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        unordered_map<int, unordered_set<int>> freq;
        vector<int> result(k, 0);

        for (const auto& log : logs)
        {
            const int ID = log[0];
            const int TIME = log[1];
            freq[ID].insert(TIME);
        }

        for (const auto& [ID, TIME] : freq)
        {
            const int UAM = TIME.size() - 1;
            ++result[UAM];
        }

        return result;
    }
};

/*

// https://leetcode.com/problems/finding-the-users-active-minutes/

---

## 1817. 사용자 활성 분 찾기 (Finding the Users Active Minutes)

### 문제 설명

LeetCode에서 사용자의 활동 기록(`logs`)과 정수 `k`가 주어집니다.

* `logs`는 2차원 정수 배열로 표현되며, `logs[i] = [IDi, timei]`는 **사용자 ID = `IDi`가 `timei` 분에 어떤 행동을 했다**는 뜻입니다.
* 여러 사용자가 동시에 행동할 수도 있으며, **한 사용자가 같은 분에 여러 번 행동할 수도 있습니다.**

**사용자 활성 분(UAM, User Active Minutes)** 은 어떤 사용자가 행동한 **고유한 분의 개수**를 의미합니다.
즉, 같은 분에 여러 번 행동해도 그 분은 **한 번만 카운트**됩니다.

당신은 길이가 `k`인 1-인덱스 배열 `answer`를 구해야 합니다.

* `answer[j]` = **UAM이 j인 사용자 수** (단, `1 <= j <= k`)

---

### 예제 1

```
입력: logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
출력: [0,2,0,0,0]
```

**설명:**

* ID=0 사용자: 행동 시각 = {5, 2, 5} → 고유 분 {2, 5} → UAM = 2
* ID=1 사용자: 행동 시각 = {2, 3} → UAM = 2

따라서 두 사용자 모두 UAM=2 → `answer[2] = 2`, 나머지는 0.

---

### 예제 2

```
입력: logs = [[1,1],[2,2],[2,3]], k = 4
출력: [1,1,0,0]
```

**설명:**

* ID=1 사용자: 행동 시각 = {1} → UAM = 1
* ID=2 사용자: 행동 시각 = {2, 3} → UAM = 2

따라서 UAM=1인 사용자 1명, UAM=2인 사용자 1명 → 결과 `[1,1,0,0]`.

---

### 제약 조건

* `1 <= logs.length <= 10^4`
* `0 <= IDi <= 10^9`
* `1 <= timei <= 10^5`
* `k`는 `[최대 사용자 UAM, 10^5]` 범위 안의 값

---

### 힌트

1. 각 사용자별로 **다른 분에서 행동한 횟수**를 먼저 계산하세요.
2. 사용자의 UAM이 j라면, `answer[j]` 값을 증가시키면 됩니다.

---

👉 이 문제는 해시맵(`unordered_map`)을 이용해서 **사용자 → 고유 분 집합**을 기록하고, 그 크기를 세어 `answer` 배열에 반영하는 방식으로 풀 수 있습니다.

원하시면 제가 이 문제에 대해 **POCU 스타일 C++ 코드** 예시도 만들어드릴까요?


*/
