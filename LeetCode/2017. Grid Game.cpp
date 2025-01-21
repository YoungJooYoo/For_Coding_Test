class Solution 
{
public:
    long long gridGame(const std::vector<std::vector<int>>& grid) 
    {
        const size_t rows = grid.size();
        const size_t cols = grid[0].size();
        vector<long long> topPrefixSum(cols + 1, 0);
        vector<long long> bottomPrefixSum(cols + 1, 0);
        long long result = numeric_limits<long long>::max();

        assert(rows == MAX_ROWS);
        assert(!grid.empty());
        assert(MIN_COLS <= cols && cols <= MAX_COLS);   

        for (size_t col = 0; col < cols; ++col)
        {
            topPrefixSum[col + 1] = topPrefixSum[col] + grid[0][col];
            bottomPrefixSum[col + 1] = bottomPrefixSum[col] + grid[1][col];
        }

        // 첫 번째 로봇의 이동 지점 결정
        for (size_t col = 0; col < cols; ++col)
        {
            const long long topRemaining = topPrefixSum[cols] - topPrefixSum[col + 1]; // 첫 번째 로봇이 (0, col)에서 아래로 이동한다고 가정
            const long long bottomRemaining = bottomPrefixSum[col];
            const long long secondRobotScore = std::max(topRemaining, bottomRemaining); // 두 번째 로봇이 수집할 수 있는 최대 점수 계산
            result = min(result, secondRobotScore); // 첫 번째 로봇이 선택한 경로에 따른 두 번째 로봇의 최대 점수를 최소화
        }

        return result;
    }

private:
    enum 
    {
        MAX_ROWS = 2,           // grid의 행 수
        MIN_COLS = 1,       // grid의 최소 열 수
        MAX_COLS = 500000,  // grid의 최대 열 수
        MIN_VALUE = 1,      // grid 요소의 최소 값
        MAX_VALUE = 100000  // grid 요소의 최대 값
    };
};

// https://leetcode.com/problems/grid-game/description/

/*

### 문제 번역: **2017. Grid Game**

---

**난이도**: 중간

---

### **문제 설명**

2 x \( n \) 크기의 2차원 배열 `grid`가 주어집니다. 여기서 `grid[r][c]`는 행 \( r \), 열 \( c \)에 위치한 셀의 점수를 나타냅니다. 두 로봇이 이 그리드에서 게임을 진행합니다.

- 두 로봇 모두 처음에는 \( (0, 0) \)에서 시작하여 \( (1, n-1) \)에 도달하려고 합니다.
- 각 로봇은 **오른쪽**으로 이동(\( (r, c) \to (r, c+1) \))하거나, **아래로** 이동(\( (r, c) \to (r+1, c) \))할 수 있습니다.

게임이 시작되면:
1. **첫 번째 로봇**이 \( (0, 0) \)에서 \( (1, n-1) \)로 이동하며 경로에 있는 모든 셀의 점수를 수집합니다.
   - 첫 번째 로봇이 지나간 셀은 점수가 \( 0 \)으로 변경됩니다.
2. **두 번째 로봇**이 \( (0, 0) \)에서 \( (1, n-1) \)로 이동하며 남아 있는 점수를 수집합니다.
   - 두 로봇의 경로는 겹칠 수 있습니다.

- **첫 번째 로봇**은 두 번째 로봇이 수집하는 점수를 **최소화**하려고 합니다.
- **두 번째 로봇**은 자신이 수집하는 점수를 **최대화**하려고 합니다.

두 로봇이 모두 최적의 전략을 사용할 때, **두 번째 로봇이 수집하는 점수를 반환**하세요.

---

### **예제**

#### 예제 1:

![예제 1 설명](https://assets.leetcode.com/uploads/2021/09/08/a1.png)

- **입력**:  
  `grid = [[2,5,4],[1,5,1]]`
- **출력**:  
  `4`
- **설명**:
  - 첫 번째 로봇이 선택한 최적 경로는 빨간색으로 표시됩니다.
  - 첫 번째 로봇이 지나간 셀은 점수가 \( 0 \)으로 설정됩니다.
  - 두 번째 로봇은 파란색 경로를 따라 \( 0 + 0 + 4 + 0 = 4 \)점을 수집합니다.

---

#### 예제 2:

![예제 2 설명](https://assets.leetcode.com/uploads/2021/09/08/a2.png)

- **입력**:  
  `grid = [[3,3,1],[8,5,2]]`
- **출력**:  
  `4`
- **설명**:
  - 첫 번째 로봇의 최적 경로는 빨간색, 두 번째 로봇의 경로는 파란색입니다.
  - 두 번째 로봇은 \( 0 + 3 + 1 + 0 = 4 \)점을 수집합니다.

---

#### 예제 3:

![예제 3 설명](https://assets.leetcode.com/uploads/2021/09/08/a3.png)

- **입력**:  
  `grid = [[1,3,1,15],[1,3,3,1]]`
- **출력**:  
  `7`
- **설명**:
  - 첫 번째 로봇은 빨간 경로, 두 번째 로봇은 파란 경로를 선택합니다.
  - 두 번째 로봇은 \( 0 + 1 + 3 + 3 + 0 = 7 \)점을 수집합니다.

---

### **제약 조건**
- \( 2 \leq n \leq 10^5 \)
- \( 1 \leq \text{grid[r][c]} \leq 10^5 \)

--- 

추가로 질문이 있다면 언제든지 말씀해주세요! \U0001f60a

*/
