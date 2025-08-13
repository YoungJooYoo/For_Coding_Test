class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, const int x, const int y, const int k) const
    {
        const size_t rows = grid.size();
        const size_t cols = grid[0].size();
        size_t top = static_cast<size_t>(x);
        size_t bottom = static_cast<size_t>(x) + static_cast<size_t>(k) - 1;

        assert(cols >= MIN_N && cols <= MAX_N);
        assert(rows >= MIN_M && rows <= MAX_M);
        assert(x >= 0 && static_cast<size_t>(x) < rows);
        assert(y >= 0 && static_cast<size_t>(y) < cols);
        assert(k >= 1);
        assert(static_cast<size_t>(x) + static_cast<size_t>(k) <= rows);
        assert(static_cast<size_t>(y) + static_cast<size_t>(k) <= cols);

        while (top < bottom)
        {
            for (size_t offset = 0; offset < static_cast<size_t>(k); ++offset)
            {
                const size_t col = static_cast<size_t>(y) + offset;
                swap(grid[top][col],grid[bottom][col]);
                assert(grid[bottom][col] >= MIN_VAL && grid[bottom][col] <= MAX_VAL);
            }
            ++top;
            --bottom;
        }

        return grid;
    }

private:
    enum
    {
        MIN_M = 1,
        MAX_M = 50,
        MIN_N = 1,
        MAX_N = 50,
        MIN_VAL = 1,
        MAX_VAL = 100
    };
};

// https://leetcode.com/problems/flip-square-submatrix-vertically/description/

/*

---

## 3643. 정사각 부분행렬을 세로로 뒤집기

난이도: 쉬움

---

정수 행렬 `grid` (크기 m x n)와 세 개의 정수 `x`, `y`, `k`가 주어집니다.

* `x`, `y`는 **뒤집을 부분행렬의 좌측 상단** 좌표(행 인덱스, 열 인덱스)를 나타냅니다.
* `k`는 부분행렬의 한 변의 길이(정사각형의 크기)를 의미합니다.

당신의 작업은 **해당 부분행렬의 행 순서를 세로 방향으로 뒤집는 것**입니다.

변경이 완료된 **업데이트된 행렬**을 반환하세요.

---

### 예시 1

**입력**

```
grid = [
    [1,  2,  3,  4],
    [5,  6,  7,  8],
    [9, 10, 11, 12],
    [13,14, 15, 16]
]
x = 1, y = 0, k = 3
```

**출력**

```
[
    [1,  2,  3,  4],
    [13,14, 15,  8],
    [9, 10, 11, 12],
    [5,  6,  7, 16]
]
```

**설명**
좌측 상단 (1,0)에서 크기 3x3인 부분행렬을 선택한 뒤, 그 행 순서를 뒤집습니다.

---

### 예시 2

**입력**

```
grid = [
    [3, 4, 2, 3],
    [2, 3, 4, 2]
]
x = 0, y = 2, k = 2
```

**출력**

```
[
    [3, 4, 4, 2],
    [2, 3, 2, 3]
]
```

**설명**
좌측 상단 (0,2)에서 크기 2x2 부분행렬을 선택 후 세로로 뒤집습니다.

---

### 제약사항

* m == `grid.length`
* n == `grid[i].length`
* 1 ≤ m, n ≤ 50
* 1 ≤ grid\[i]\[j] ≤ 100
* 0 ≤ x < m
* 0 ≤ y < n
* 1 ≤ k ≤ min(m - x, n - y)

---

💡 **힌트**
부분행렬의 윗 행과 아랫 행에 각각 포인터를 두고, 가운데로 올 때까지 k개의 열을 서로 교환하세요.

---


10 11 12
20 21 22 
30 31 32

10 -> 30
11 -> 31

30 -> 10

*/
