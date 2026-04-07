class Solution
{
public:
    bool canPartitionGrid(const vector<vector<int>>& grid) const
    {
        assert(MIN_SIZE <= static_cast<int>(grid.size()) && static_cast<int>(grid.size()) <= MAX_SIZE);
        assert(MIN_SIZE <= static_cast<int>(grid[0].size()) && static_cast<int>(grid[0].size()) <= MAX_SIZE);

        const long long totalSum = getAllElementsSum(grid);
        if (totalSum % 2 != 0)
        {
            return false;
        }

        const long long halfSum  = totalSum / 2;
        const size_t rowSize     = grid.size();
        const size_t colSize     = grid[0].size();


        long long topSum = 0;
        for (size_t topIndex = 0; topIndex < rowSize - 1; ++topIndex)
        {
            topSum += accumulate(grid[topIndex].begin(), grid[topIndex].end(), 0LL);
            if (topSum == halfSum)
            {
                return true;
            }
        }

        // 세로 절단: 왼쪽에서 오른쪽으로 열별 누적합이 halfSum과 같은 구간 탐색
        long long leftSum = 0;
        for (size_t colIndex = 0; colIndex < colSize - 1; ++colIndex)
        {
            for (size_t rowIndex = 0; rowIndex < rowSize; ++rowIndex)
            {
                assert(MIN_VALUE <= grid[rowIndex][colIndex] && grid[rowIndex][colIndex] <= MAX_VALUE);
                leftSum += grid[rowIndex][colIndex];
            }
            if (leftSum == halfSum)
            {
                return true;
            }
        }

        return false;
    }

private:
    long long getAllElementsSum(const vector<vector<int>>& grid) const
    {
        long long totalSum = 0;
        for (const auto& row : grid)
        {
            assert(MIN_SIZE <= static_cast<int>(row.size()) && static_cast<int>(row.size()) <= MAX_SIZE);
            totalSum += accumulate(row.begin(), row.end(), 0LL);
        }

        return totalSum;
    }

private:
    enum
    {
        MIN_SIZE  = 1,
        MAX_SIZE  = 100000,
        MIN_VALUE = 1,
        MAX_VALUE = 100000,
    };
};

/*
## 문제 번역

**3546. 동일한 합으로 격자 분할 I**

양의 정수로 이루어진 `m x n` 행렬 `grid`가 주어집니다. 아래 조건을 만족하도록 격자에 **가로 또는 세로로 단 한 번의 직선 절단**이 가능한지 판단하세요.

- 절단으로 만들어진 **두 구역 모두 비어있지 않아야** 합니다.
- **두 구역의 원소 합이 서로 같아야** 합니다.

이러한 분할이 가능하면 `true`, 불가능하면 `false`를 반환하세요.

---

**예시 1**
- 입력: `grid = [[1,4],[2,3]]`
- 출력: `true`
- 설명:
  - 0행과 1행 사이를 가로로 자르면 → 위쪽 합 `1+4=5`, 아래쪽 합 `2+3=5` → 동일 ✅

**예시 2**
- 입력: `grid = [[1,3],[2,4]]`
- 출력: `false`
- 설명:
  - 가로/세로 어떻게 잘라도 두 구역의 합이 같아지지 않음 → `false`

---

**제약 조건**
- `1 <= m == grid.length <= 10^5`
- `1 <= n == grid[i].length <= 10^5`
- `2 <= m * n <= 10^5`
- `1 <= grid[i][j] <= 10^5`

---

## 요약

격자를 **가로 또는 세로로 한 번** 잘랐을 때 **양쪽 합이 같아지는 경우**가 존재하는지 판별.

---

## 풀이 방향

**핵심 관찰**: 전체 합이 **홀수**이면 절대 절반으로 나눌 수 없음 → 즉시 `false`

**가로 절단 확인:**
```
전체 합의 절반 == 위쪽 누적 합?
행을 위에서 아래로 누적하다가 totalSum / 2 와 같아지는 순간 존재하면 true
```

**세로 절단 확인:**
```
전체 합의 절반 == 왼쪽 누적 합?
열을 왼쪽에서 오른쪽으로 누적하다가 totalSum / 2 와 같아지는 순간 존재하면 true
```

1. 전체 합 `totalSum` 계산
2. `totalSum % 2 != 0` → `false` 반환
3. 행별 누적합이 `totalSum / 2` 가 되는 지점 탐색
4. 열별 누적합이 `totalSum / 2` 가 되는 지점 탐색
5. 둘 중 하나라도 존재하면 `true`

https://leetcode.com/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25
*/
