class Solution
{
public:
    int minimumEffort(vector<vector<int>>& tasks) const
    {
        assert(MIN_LENGTH <= static_cast<int>(tasks.size()) && static_cast<int>(tasks.size()) <= MAX_LENGTH);

        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return (a[MINIMUM_IDX] - a[ACTUAL_IDX]) > (b[MINIMUM_IDX] - b[ACTUAL_IDX]);
        });

        long long requiredEnergy = 0;
        long long currentEnergy  = 0;

        for (const auto& task : tasks)
        {
            assert(static_cast<int>(task.size()) == TASK_SIZE);
            const int actualEnergy  = task[ACTUAL_IDX];
            const int minimumEnergy = task[MINIMUM_IDX];
            assert(MIN_ENERGY <= actualEnergy && actualEnergy <= MAX_ENERGY);
            assert(actualEnergy <= minimumEnergy && minimumEnergy <= MAX_ENERGY);

            if (currentEnergy < minimumEnergy) // 현재 에너지가 minimum 보다 부족하면 초기 에너지 보충
            {
                requiredEnergy += (minimumEnergy - currentEnergy);
                currentEnergy  = minimumEnergy;
            }
            currentEnergy -= actualEnergy;
        }

        return static_cast<int>(requiredEnergy);
    }

private:
    enum
    {
        MIN_LENGTH  = 1,
        MAX_LENGTH  = 100000,
        MIN_ENERGY  = 1,
        MAX_ENERGY  = 10000,
        TASK_SIZE   = 2,
        ACTUAL_IDX  = 0,
        MINIMUM_IDX = 1,
    };
};


/*
## 문제 번역

**1665. 모든 태스크를 완료하기 위한 최소 초기 에너지**

`tasks[i] = [actual_i, minimum_i]` 형태의 배열 `tasks`가 주어집니다:

- `actual_i` → `i`번째 태스크를 **완료하는 데 소비되는** 에너지
- `minimum_i` → `i`번째 태스크를 **시작하기 위해 필요한 최소** 에너지

예를 들어, 태스크가 `[10, 12]`이고 현재 에너지가 `11`이면 시작 불가. 에너지가 `13`이면 시작 가능하고, 완료 후 에너지는 `3`.

태스크는 **원하는 순서로** 완료할 수 있습니다.

모든 태스크를 완료하기 위한 **최소 초기 에너지**를 반환하세요.

---

**예시 1**
- 입력: `tasks = [[1,2],[2,4],[4,8]]`
- 출력: `8`
- 설명:
  - 초기 에너지 8로 시작
  - 3번째 태스크: `8 - 4 = 4`
  - 2번째 태스크: `4 - 2 = 2`
  - 1번째 태스크: `2 - 1 = 1`
  - 초기 에너지 7로는 3번째 태스크 시작 불가

**예시 2**
- 입력: `tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]`
- 출력: `32`
- 설명:
  - 1→2→3→4→5번 순서로 완료
  - `32 → 31 → 29 → 19 → 9 → 1`

**예시 3**
- 입력: `tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]`
- 출력: `27`

---

**제약 조건**
- `1 <= tasks.length <= 10^5`
- `1 <= actual_i <= minimum_i <= 10^4`

---

## 요약

태스크 순서를 잘 정해서 **모든 태스크를 완료할 수 있는 최소 초기 에너지**를 구하는 문제.

---

## 풀이 방향 (그리디)

**핵심 관찰**: `minimum - actual` (여유분) 이 **큰 태스크를 나중에** 처리할수록 유리

```
여유분 = minimum - actual
여유분이 클수록 → 나중에 처리
여유분이 작을수록 → 먼저 처리
```

1. `minimum - actual` 기준으로 **오름차순 정렬**
2. 뒤에서부터 역순으로 필요 에너지 계산
3. 각 태스크마다 `필요 에너지 = max(현재 필요량 + actual, minimum)` 갱신

https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/?envType=daily-question&envId=2026-05-12
*/
