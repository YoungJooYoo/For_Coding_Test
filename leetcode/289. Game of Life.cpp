class Solution
{
public:
    void gameOfLife(vector<vector<int>>& board) const
    {
        const size_t ROW_COUNT = board.size();
        const size_t COL_COUNT = board[0].size();
        vector<vector<int>> nextBoard(ROW_COUNT, vector<int>(COL_COUNT, DEAD));

        assert(MIN_BOARD_SIZE <= ROW_COUNT && ROW_COUNT <= MAX_BOARD_SIZE);
        assert(MIN_BOARD_SIZE <= COL_COUNT && COL_COUNT <= MAX_BOARD_SIZE);

        for (size_t row = 0; row < ROW_COUNT; ++row)
        {
            for (size_t col = 0; col < COL_COUNT; ++col)
            {
                assert(board[row][col] == DEAD || board[row][col] == LIVE);
                updateCellStatus(board, nextBoard, row, col, ROW_COUNT, COL_COUNT);
            }
        }

        board = nextBoard;
    }

private:
    void updateCellStatus(
        const vector<vector<int>>& board,
        vector<vector<int>>& nextBoard,
        const size_t row,
        const size_t col,
        const size_t ROW_COUNT,
        const size_t COL_COUNT) const
    {
        assert(row < ROW_COUNT && col < COL_COUNT);

        size_t liveNeighborCount = 0;

        // 8방향 체크
        if (row > 0 && board[row - 1][col] == LIVE)
        {
            ++liveNeighborCount;
        }
        if (row + 1 < ROW_COUNT && board[row + 1][col] == LIVE)
        {
            ++liveNeighborCount;
        }
        if (col > 0 && board[row][col - 1] == LIVE)
        {
            ++liveNeighborCount;
        }
        if (col + 1 < COL_COUNT && board[row][col + 1] == LIVE)
        {
            ++liveNeighborCount;
        }
        if (row > 0 && col > 0 && board[row - 1][col - 1] == LIVE)
        {
            ++liveNeighborCount;
        }
        if (row > 0 && col + 1 < COL_COUNT && board[row - 1][col + 1] == LIVE)
        {
            ++liveNeighborCount;
        }
        if (row + 1 < ROW_COUNT && col > 0 && board[row + 1][col - 1] == LIVE)
        {
            ++liveNeighborCount;
        }
        if (row + 1 < ROW_COUNT && col + 1 < COL_COUNT && board[row + 1][col + 1] == LIVE)
        {
            ++liveNeighborCount;
        }

        // 생명 게임 규칙 적용
        if (board[row][col] == LIVE)
        {
            if (liveNeighborCount < 2 || liveNeighborCount > 3)
            {
                nextBoard[row][col] = DEAD;
            }
            else
            {
                nextBoard[row][col] = LIVE;
            }
        }
        else
        {
            if (liveNeighborCount == 3)
            {
                nextBoard[row][col] = LIVE;
            }
            else
            {
                nextBoard[row][col] = DEAD;
            }
        }
    }

    enum
    {
        MIN_BOARD_SIZE = 1,
        MAX_BOARD_SIZE = 25,
        DEAD = 0,
        LIVE = 1
    };
};

// https://leetcode.com/problems/game-of-life/description/

/*

## 289. 생명의 게임 (Game of Life)

**난이도: 중**

---

### 문제 설명

위키피디아에 따르면, "Game of Life(생명의 게임)"은 1970년 영국의 수학자 John Horton Conway가 고안한 **셀룰러 오토마타**입니다.

이 보드는 m × n 크기의 격자로 이루어져 있으며,
각 셀은 **살아 있음(1)** 또는 **죽어 있음(0)** 중 하나의 초기 상태를 가집니다.

각 셀은 **상하좌우, 대각선을 포함한 8방향 이웃**과 상호작용하며,
아래 네 가지 규칙(위키피디아에서 인용됨)을 따릅니다:

1. **살아 있는 셀이 이웃한 살아 있는 셀이 2개 미만**이면(= 0개나 1개)
   **과소(population 부족)로 죽습니다.**
2. **살아 있는 셀이 이웃한 살아 있는 셀이 2개 또는 3개**면
   **다음 세대로 살아남습니다.**
3. **살아 있는 셀이 이웃한 살아 있는 셀이 3개 초과**면
   **과잉(population 과다)으로 죽습니다.**
4. **죽어 있는 셀이 이웃한 살아 있는 셀이 정확히 3개**면
   **다음 세대에 살아납니다(생성, 번식).**

다음 세대의 상태는,
**현재의 m x n 격자에서 모든 셀에 대해 위 네 가지 규칙을 동시에 적용해서** 결정합니다.
이 과정에서, **죽음과 탄생은 동시에 발생**합니다.

---

### 입력 및 출력

* 현재 보드 상태(board)가 주어집니다.
* **보드의 다음 세대를 직접 갱신**하세요.
  (함수에서 값을 반환할 필요는 없습니다.)

---

### 예시

#### 예시 1

입력:
`board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]`

출력:
`[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]`

---

#### 예시 2

입력:
`board = [[1,1],[1,0]]`

출력:
`[[1,1],[1,1]]`

---

### 제약사항

* m == board.length
* n == board\[i].length
* 1 <= m, n <= 25
* board\[i]\[j]는 0 또는 1

---

### 추가 질문

* **in-place(제자리)로 풀이할 수 있나요?**
  (모든 셀을 한 번에 갱신해야 하므로, 어떤 셀을 먼저 바꾼 뒤 그 값을 다른 셀 갱신에 바로 사용할 수 없습니다.)
* 이 문제에서는 보드를 2차원 배열로 표현했지만,
  **원래 생명의 게임은 무한한 격자에서 작동**합니다.
  만약 살아 있는 셀이 격자의 경계에 닿으면 어떻게 처리해야 할까요?

---

궁금한 점, 구현 코드, 해설 등 필요하시면 언제든 말씀해 주세요!

*/
