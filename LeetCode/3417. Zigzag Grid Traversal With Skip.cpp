class Solution 
{
public:
    vector<int> zigzagTraversal(const vector<vector<int>>& grid) 
    {
        const size_t ROW_LENGTH = grid.size();
        const size_t COL_LENGTH = grid[0].size();
        int tracking = 0;
        vector<int> result;

        assert(ROW_LENGTH >= MIN_ROWS && ROW_LENGTH <= MAX_ROWS); // 행의 개수 검증
        assert(COL_LENGTH >= MIN_COLUMNS && COL_LENGTH <= MAX_COLUMNS); // 열의 개수 검증

        for (size_t i = 0; i < ROW_LENGTH; ++i)
        {
            if (i % 2 == 0)
            {
                for (size_t j = 0; j < COL_LENGTH; ++j)
                {
                    assert(grid[i][j] >= MIN_VALUE && grid[i][j] <= MAX_VALUE); // 값의 범위 검증
                    if (tracking++ % 2 == 0) result.push_back(grid[i][j]);
                }
            }
            else
            {
                for (int j = COL_LENGTH - 1; j >= 0; --j)
                {
                    assert(grid[i][j] >= MIN_VALUE && grid[i][j] <= MAX_VALUE); // 값의 범위 검증
                    if (tracking++ % 2 == 0) result.push_back(grid[i][j]);
                }
            }
        }
        
        assert(result.size() > 0);
        return result;
    }

private:
    enum 
    {
        MIN_ROWS = 2,
        MAX_ROWS = 50,

        MIN_COLUMNS = 2,
        MAX_COLUMNS = 50,

        MIN_VALUE = 1,
        MAX_VALUE = 2500,
    };
};

// https://leetcode.com/problems/zigzag-grid-traversal-with-skip/description/

/*

### **3417. 지그재그 그리드 탐색 (건너뛰기 포함)**

---

### **문제 설명**

주어진 \( m \times n \) 크기의 2D 배열 \( \text{grid} \)에서 **양의 정수**로 구성된 그리드를 탐색합니다.  
탐색 규칙은 다음과 같습니다:

1. **지그재그 패턴 탐색**:
   - (0, 0)에서 시작합니다.
   - 각 행에서는 오른쪽으로 이동하여 끝까지 갑니다.
   - 다음 행에서는 왼쪽으로 이동하며, 시작점까지 돌아옵니다.
   - 이후 행을 교차하며 계속 탐색합니다.

2. **교차 패턴에서 건너뛰기**:
   - 탐색 중 **매번 두 번째 칸(한 칸 건너뛰기)**를 건너뜁니다.

---

### **목표**
탐색 중 방문한 셀들의 값을 순서대로 담은 배열 \( \text{result} \)를 반환하세요.

---

### **입출력 예시**

#### **예제 1**
- **입력**:
  \[
  \text{grid} = [[1,2],[3,4]]
  \]
- **출력**:
  ```text
  [1, 4]
  ```
- **설명**:
  - 첫 번째 행: 오른쪽으로 이동 → 1 방문 → 2는 건너뜀.
  - 두 번째 행: 왼쪽으로 이동 → 4 방문 → 3은 건너뜀.

---

#### **예제 2**
- **입력**:
  \[
  \text{grid} = [[2,1],[2,1],[2,1]]
  \]
- **출력**:
  ```text
  [2, 1, 2]
  ```
- **설명**:
  - 첫 번째 행: 오른쪽으로 이동 → 2 방문 → 1은 건너뜀.
  - 두 번째 행: 왼쪽으로 이동 → 1 방문 → 2는 건너뜀.
  - 세 번째 행: 오른쪽으로 이동 → 2 방문 → 1은 건너뜀.

---

#### **예제 3**
- **입력**:
  \[
  \text{grid} = [[1,2,3],[4,5,6],[7,8,9]]
  \]
- **출력**:
  ```text
  [1, 3, 5, 7, 9]
  ```
- **설명**:
  - 첫 번째 행: 오른쪽으로 이동 → 1 방문 → 2 건너뜀 → 3 방문.
  - 두 번째 행: 왼쪽으로 이동 → 5 방문 → 4 건너뜀 → 6 건너뜀.
  - 세 번째 행: 오른쪽으로 이동 → 7 방문 → 8 건너뜀 → 9 방문.

---

### **제약 조건**

1. \( 2 \leq n = \text{grid.length} \leq 50 \)
2. \( 2 \leq m = \text{grid[i].length} \leq 50 \)
3. \( 1 \leq \text{grid[i][j]} \leq 2500 \)

---

### **힌트**
- 각 행을 탐색할 때, 짝수 번째와 홀수 번째 행의 방향(오른쪽 또는 왼쪽)을 고려하여 구현하세요.
- 한 칸씩 건너뛰며 셀 값을 수집해야 합니다.
*/
