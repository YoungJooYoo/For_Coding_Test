class Solution
{
public:
    int countServers(vector<vector<int>>& grid)
    {
        const int ROW = grid.size();
        const int COL = grid[0].size();

        assert(ARRAY_MIN_LENGTH <= ROW && ROW <= ARRAY_MAX_LENGTH);
        assert(ARRAY_MIN_LENGTH <= COL && COL <= ARRAY_MAX_LENGTH);

        mRowServerCount.assign(ROW, 0); // 1. 각 행과 열의 서버 개수를 계산
        mColServerCount.assign(COL, 0);

        for (int i = 0; i < ROW; ++i)
        {
            for (int j = 0; j < COL; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++mRowServerCount[i];
                    ++mColServerCount[j];
                }
            }
        }

        for (int i = 0; i < ROW; ++i) // 2. 통신 가능한 서버 개수 계산
        {
            for (int j = 0; j < COL; ++j)
            {
                countServersHelper(grid, i, j);
            }
        }

        return mCountCommuncationServer;
    }

private:
    void countServersHelper(vector<vector<int>>& grid, const int row, const int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        {
            return;
        }
        else if (grid[row][col] == 0 || grid[row][col] == VISITED)
        {
            return;
        }
        else if (mRowServerCount[row] <= 1 && mColServerCount[col] <= 1) // 현재 셀의 행과 열에 다른 서버가 없는 경우 탐색 중단
        {
            return;
        }

        assert(grid[row][col] == 1);

        // 현재 셀 방문 처리 및 카운트 증가
        if (grid[row][col] == 1)
        {
            grid[row][col] = VISITED;
            ++mCountCommuncationServer;
        }

        countServersHelper(grid, row, col + 1); // 오른쪽
        countServersHelper(grid, row, col - 1); // 왼쪽
        countServersHelper(grid, row + 1, col); // 아래
        countServersHelper(grid, row - 1, col); // 위
    }

private:
    int mCountCommuncationServer = 0;
    vector<int> mRowServerCount;
    vector<int> mColServerCount;

    enum
    {
        VISITED = -1,
        ARRAY_MIN_LENGTH = 1,
        ARRAY_MAX_LENGTH = 250,
    };
};

// https://leetcode.com/problems/count-servers-that-communicate/?envType=daily-question&envId=2025-01-23

/*
### **67. 서로 통신 가능한 서버 개수 세기**

---

#### **문제 설명**  
서버 센터의 지도가 `m x n` 크기의 정수 행렬 `grid`로 주어집니다.  
- `1`은 해당 위치에 서버가 있음을 나타냅니다.  
- `0`은 해당 위치에 서버가 없음을 나타냅니다.

서버는 **같은 행(row)** 또는 **같은 열(column)** 에 위치한 다른 서버와 **통신**할 수 있습니다.

**통신할 수 있는 다른 서버가 있는 서버의 개수를 반환하세요.**

---

#### **예제**

##### **예제 1**  
**입력**:  
```plaintext
grid = [[1,0],
        [0,1]]
```

**출력**:  
```plaintext
0
```

**설명**:  
어떤 서버도 다른 서버와 통신할 수 없습니다.

---

##### **예제 2**  
**입력**:  
```plaintext
grid = [[1,0],
        [1,1]]
```

**출력**:  
```plaintext
3
```

**설명**:  
- 첫 번째 열의 두 서버는 서로 통신할 수 있습니다.  
- 마지막 서버는 첫 번째 열의 서버와 통신할 수 있습니다.  
- 결과적으로, 모든 3개의 서버는 다른 서버와 통신할 수 있습니다.

---

##### **예제 3**  
**입력**:  
```plaintext
grid = [[1,1,0,0],
        [0,0,1,0],
        [0,0,1,0],
        [0,0,0,1]]
```

**출력**:  
```plaintext
4
```

**설명**:  
- 첫 번째 행의 두 서버는 서로 통신할 수 있습니다.  
- 세 번째 열의 두 서버는 서로 통신할 수 있습니다.  
- 마지막 행의 서버는 다른 서버와 통신할 수 없습니다.  
- 결과적으로 통신할 수 있는 서버는 총 4개입니다.

---

#### **제약 조건**
1. `m == grid.length` (행 개수)
2. `n == grid[i].length` (열 개수)
3. `1 <= m <= 250`
4. `1 <= n <= 250`
5. `grid[i][j] == 0 또는 1`

---

#### **문제 풀이 아이디어**
1. 각 행(row)과 열(column)에 있는 서버의 개수를 계산합니다.
2. **통신 가능한 서버**는 해당 행 또는 열에 2개 이상의 서버가 있는 경우입니다.
3. `grid`를 순회하며 통신 가능한 서버의 개수를 합산합니다.
*/
