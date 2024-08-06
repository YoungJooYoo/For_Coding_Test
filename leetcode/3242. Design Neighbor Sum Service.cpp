class neighborSum 
{
public:
    neighborSum(const vector<vector<int>>& grid) 
        : mROW(grid.size())
        , mCOLUMN(grid[0].size())
        , mGrid(grid)
    {
    }
    
    int adjacentSum(const int value) 
    {
        int sum = 0;
        int i;
        int j;
        findPosition(mGrid, value, i, j);

        // 상 하 좌 우
        if (i - 1 >= 0) sum += mGrid[i - 1][j];
        if (i + 1 < mROW) sum += mGrid[i + 1][j];
        if (j - 1 >= 0) sum += mGrid[i][j - 1];
        if (j + 1 < mCOLUMN) sum += mGrid[i][j + 1];
        
        return sum;
    }
    
    int diagonalSum(const int value) 
    {
        int sum = 0;
        int i;
        int j;
        findPosition(mGrid, value, i, j);

        // 좌상 우상 좌하 우하
        if (i - 1 >= 0 && j - 1 >= 0) sum += mGrid[i - 1][j - 1];
        if (i - 1 >= 0 && j + 1 < mCOLUMN) sum += mGrid[i - 1][j + 1];
        if (i + 1 < mROW && j - 1 >= 0) sum += mGrid[i + 1][j - 1];
        if (i + 1 < mROW && j + 1 < mCOLUMN) sum += mGrid[i + 1][j + 1];
        
        return sum;
    }

    void findPosition(const vector<vector<int>>& mGrid, const int value, int& outI, int& outJ)
    {
        for (size_t i = 0; i < mROW; ++i)
        {
            for (size_t j = 0; j < mCOLUMN; ++j)
            {
                if (mGrid[i][j] == value)
                {
                    outI = i;
                    outJ = j;
                }
            }
        }
    }

private:
    const size_t mROW;
    const size_t mCOLUMN;
    const vector<vector<int>>& mGrid;
};


// https://leetcode.com/problems/design-neighbor-sum-service/description/

/*
 ### 3242. 이웃 합 서비스 디자인

**난이도: 쉬움**

#### 문제 설명

n x n 2D 배열 `grid`가 주어지며, 이 배열은 [0, n² - 1] 범위의 서로 다른 요소들로 구성되어 있습니다.

`neighborSum` 클래스를 구현하세요:

- `neighborSum(int[][] grid)`: 객체를 초기화합니다.
- `int adjacentSum(int value)`: `grid`에서 `value`의 인접한 이웃 요소들의 합을 반환합니다. 인접한 이웃은 위, 왼쪽, 오른쪽, 아래에 위치한 요소들입니다.
- `int diagonalSum(int value)`: `grid`에서 `value`의 대각선 이웃 요소들의 합을 반환합니다. 대각선 이웃은 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래에 위치한 요소들입니다.

#### 예제

**예제 1**:

```
입력:

["neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"]
[[[[0, 1, 2], [3, 4, 5], [6, 7, 8]]], [1], [4], [4], [8]]

출력: [null, 6, 16, 16, 4]

설명:

1의 인접한 이웃은 0, 2, 4입니다.
4의 인접한 이웃은 1, 3, 5, 7입니다.
4의 대각선 이웃은 0, 2, 6, 8입니다.
8의 대각선 이웃은 4입니다.
```

**예제 2**:

```
입력:

["neighborSum", "adjacentSum", "diagonalSum"]
[[[[1, 2, 0, 3], [4, 7, 15, 6], [8, 9, 10, 11], [12, 13, 14, 5]]], [15], [9]]

출력: [null, 23, 45]

설명:

15의 인접한 이웃은 0, 10, 7, 6입니다.
9의 대각선 이웃은 4, 12, 14, 15입니다.
```

#### 제약 조건

- `3 <= n == grid.length == grid[0].length <= 10`
- `0 <= grid[i][j] <= n² - 1`
- 모든 `grid[i][j]`는 고유합니다.
- `adjacentSum`과 `diagonalSum`에 주어지는 `value`는 [0, n² - 1] 범위 내에 있습니다.
- `adjacentSum`과 `diagonalSum`에 최대 2 * n² 호출이 있을 수 있습니다.
 
 */
