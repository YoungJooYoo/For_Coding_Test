class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) const
    {
        const size_t ROW_LENGTH = boxGrid.size();
        const size_t COL_LENGTH = boxGrid[0].size();

        assert(MIN_LENGTH <= ROW_LENGTH && ROW_LENGTH <= MAX_LENGTH);
        assert(MIN_LENGTH <= COL_LENGTH && COL_LENGTH <= MAX_LENGTH);

        for (size_t i = 0; i < ROW_LENGTH; ++i) // move stone: 각 행에서 오른쪽으로 '떨어뜨리기'
        {
            size_t write = (COL_LENGTH == 0) ? 0 : COL_LENGTH - 1; // 행마다 한 번 초기화
            for (int j = static_cast<int>(COL_LENGTH) - 1; j >= 0; --j)
            {
                const char cell = boxGrid[i][j];
                assert(cell == STONE || cell == OBSTACLE || cell == EMPTY);
                if (cell == OBSTACLE)
                {
                    write = (j == 0) ? 0 : static_cast<size_t>(j - 1); // 장애물 왼쪽으로 구간 리셋
                }
                else if (cell == STONE)
                {
                    if (static_cast<size_t>(j) != write) // 돌을 write 자리로 이동
                    {
                        swap(boxGrid[i][j], boxGrid[i][write]); // swap empty and stone
                    }
                    if (write > 0)
                    {
                        --write;
                    }
                }
            }
        }

        // rotate 90 deg clockwise
        vector<vector<char>> rotatedBoxGrid(COL_LENGTH, vector<char>(ROW_LENGTH, EMPTY));
        for (size_t i = 0; i < ROW_LENGTH; ++i)
        {
            for (size_t j = 0; j < COL_LENGTH; ++j)
            {
                rotatedBoxGrid[j][ROW_LENGTH - 1 - i] = boxGrid[i][j];
            }
        }

        return rotatedBoxGrid;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 500,
        STONE = '#',
        OBSTACLE = '*', // ← 오타 수정 (원한다면 기존 'OBSTABLE' 유지 가능)
        EMPTY = '.'
    };
};


// https://leetcode.com/problems/rotating-the-box/description/

/*



---

## 1861. 상자 회전하기

**난이도: 중간**

---

### 문제 설명

`m x n` 크기의 문자 행렬 `boxGrid`가 주어집니다.
이는 상자를 **측면에서 바라본 모습**을 나타냅니다. 각 칸은 다음 중 하나입니다.

* `#` : 돌(stone)
* `*` : 고정된 장애물(stationary obstacle)
* `.` : 빈 칸(empty)

이 상자를 **시계 방향으로 90도 회전**시키면, 일부 돌이 중력 때문에 아래로 떨어집니다.
돌은 다음 조건에 맞을 때까지 떨어집니다.

* 아래가 장애물(`*`)인 경우
* 아래가 다른 돌(`#`)인 경우
* 상자의 맨 아래 바닥인 경우

장애물의 위치는 중력에 영향을 받지 않습니다.
상자를 회전시킬 때 생기는 **관성(가로 방향 이동)** 은 돌에 영향을 주지 않습니다.

**보장:** 입력으로 주어지는 `boxGrid`에서 모든 돌은 장애물, 다른 돌, 또는 바닥 위에 놓여 있는 상태입니다.

목표: 회전 후의 상자를 나타내는 **n x m 크기의 행렬**을 반환하세요.

---

### 예시

#### 예시 1

```
입력:
boxGrid = [["#",".","#"]]

출력:
[["."],
 ["#"],
 ["#"]]
```

#### 예시 2

```
입력:
boxGrid = [["#",".","*","."],
           ["#","#","*","."]]

출력:
[["#","."],
 ["#","#"],
 ["*","*"],
 [".","."]]
```

#### 예시 3

```
입력:
boxGrid = [["#","#","*",".","*","."],
           ["#","#","#","*",".","."],
           ["#","#","#",".","#","."]]

출력:
[[".","#","#"],
 [".","#","#"],
 ["#","#","*"],
 ["#","*","."],
 ["#",".","*"],
 ["#",".","."]]
```

---

### 제약 조건

* `m == boxGrid.length`
* `n == boxGrid[i].length`
* `1 <= m, n <= 500`
* `boxGrid[i][j]` 는 `'#'`, `'*'`, `'.'` 중 하나



*/
