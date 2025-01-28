class Solution 
{
public:
    int findMaxFish(vector<vector<int>>& grid) 
    {
        const int rows = grid.size();
        const int cols = grid[0].size();
        int maxFishCount = 0; 

        assert(MIN_GRID_SIZE <= rows && rows <= MAX_GRID_SIZE);
        assert(MIN_GRID_SIZE <= cols && cols <= MAX_GRID_SIZE);

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] != EMPTY && grid[i][j] != VISITED)
                {
                    maxFishCount = max(maxFishCount, exploreGridRecursive(grid, i, j));
                }
            }
        }
        
        assert(maxFishCount >= 0);
        return maxFishCount;
    }

private:
    int exploreGridRecursive(vector<vector<int>>& grid, const int row, const int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        {
            return 0;
        }
        else if (grid[row][col] == VISITED || grid[row][col] == EMPTY)
        {
            return 0;
        }

        const int currentFish = grid[row][col];
        grid[row][col] = VISITED; 
        const int totalFish = currentFish
                      + exploreGridRecursive(grid, row, col + 1) // 오른쪽
                      + exploreGridRecursive(grid, row, col - 1) // 왼쪽
                      + exploreGridRecursive(grid, row + 1, col) // 아래쪽
                      + exploreGridRecursive(grid, row - 1, col); // 위쪽

        return totalFish;
    }

    enum
    {
        VISITED = -1,  // 방문한 셀 표시
        EMPTY = 0,     // 물고기가 없는 셀
        MIN_GRID_SIZE = 1,  // 그리드 최소 크기
        MAX_GRID_SIZE = 10, // 그리드 최대 크기
        MIN_FISH_VALUE = 0, // 물고기 수 최소값
        MAX_FISH_VALUE = 10 // 물고기 수 최대값
    };
};

/https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28 


/*
### **문제 번역: 그리드에서 최대 물고기 수 (Maximum Number of Fish in a Grid)**

**난이도**: 중간  
**주제**: 그래프 탐색, 깊이 우선 탐색(DFS), 너비 우선 탐색(BFS)  
**관련 회사**: 다양한 기업  
**힌트**: 그리드 탐색과 최적의 시작점 선택이 핵심입니다.

---

#### **문제 설명**

- **그리드**: 크기가 `m x n`인 2차원 행렬 `grid`가 주어집니다. 각 셀 `(r, c)`는 다음과 같습니다:
  - `grid[r][c] = 0`: 땅 셀 (물고기가 없음).
  - `grid[r][c] > 0`: 물 셀 (해당 셀에 `grid[r][c]` 마리의 물고기가 있음).
  
- **낚시꾼의 행동**:
  - 낚시꾼은 어떤 물 셀 `(r, c)`에서 시작할 수 있습니다.
  - 다음 작업을 원하는 만큼 반복할 수 있습니다:
    1. 현재 셀 `(r, c)`의 모든 물고기를 잡습니다.
    2. 인접한 물 셀로 이동합니다.
  
- **목표**: 낚시꾼이 최적의 시작 셀을 선택했을 때 잡을 수 있는 최대 물고기 수를 반환하세요. 만약 물 셀이 없다면 `0`을 반환합니다.

- **인접 셀**: 셀 `(r, c)`의 인접 셀은 `(r, c + 1)`, `(r, c - 1)`, `(r + 1, c)`, `(r - 1, c)` 중 그리드 내에 존재하는 셀입니다.

---

#### **예제 1**

- **입력**: `grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]`
- **출력**: `7`
- **설명**:
  - 낚시꾼은 셀 `(1, 3)`에서 시작해 3마리의 물고기를 잡고, 셀 `(2, 3)`로 이동해 4마리의 물고기를 잡을 수 있습니다.
  - 총 물고기 수: `3 + 4 = 7`.

---

#### **예제 2**

- **입력**: `grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]`
- **출력**: `1`
- **설명**:
  - 낚시꾼은 셀 `(0, 0)` 또는 `(3, 3)`에서 시작해 1마리의 물고기를 잡을 수 있습니다.

---

#### **제약 조건**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 10`
- `0 <= grid[i][j] <= 10`

---

### **문제 해결 접근법**

1. **그리드 탐색**:
   - 모든 물 셀을 탐색하며, 각 셀에서 시작했을 때 잡을 수 있는 물고기의 최대 수를 계산합니다.
   - 깊이 우선 탐색(DFS) 또는 너비 우선 탐색(BFS)를 사용해 연결된 물 셀을 탐색합니다.

2. **최적의 시작점 선택**:
   - 모든 물 셀을 시작점으로 고려하며, 각 시작점에서 잡을 수 있는 물고기 수를 계산합니다.
   - 그 중 최댓값을 반환합니다.

3. **방문 처리**:
   - 이미 방문한 셀은 다시 방문하지 않도록 방문 여부를 기록합니다.

---

### **시간 복잡도**

- 그리드의 크기가 최대 `10 x 10`이므로, 완전 탐색이 가능합니다.
- 각 셀을 한 번씩만 방문하므로, 시간 복잡도는 **O(m x n)**입니다.

---

### **추가 설명**

- 이 문제는 그래프 탐색을 통해 연결된 컴포넌트(물 셀 그룹)를 찾고, 각 컴포넌트의 합을 계산하는 문제입니다.
- DFS 또는 BFS를 사용해 각 물 셀 그룹의 합을 계산하고, 그 중 최댓값을 찾으면 됩니다.

---

이 문제를 해결하려면 그래프 탐색 알고리즘을 잘 이해하고 구현할 수 있어야 합니다. 😊
*/
