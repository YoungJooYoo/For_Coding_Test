class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) const
    {
        vector<int> rows;
        vector<int> cols;
        const int LENGTH = rooks.size();
        int result = 0;
        
        assert(MIN_LENGTH <= LENGTH && LENGTH <= MAX_LENGTH);

        for (const auto& rook : rooks)
        {
            const int row = rook[0];
            const int col = rook[1];
            rows.push_back(row);
            cols.push_back(col);
            assert(0 <= row && row < LENGTH);
            assert(0 <= col && col < LENGTH);
        }

        assert(rows.size() == cols.size());
        ranges::sort(rows);
        ranges::sort(cols);

        int sumRow = 0;
        int sumCol = 0;
        for(int i = 0; i < LENGTH; ++i)
        {
            sumRow += abs(rows[i] - i);
            sumCol += abs(cols[i] - i);
        }

        return sumRow + sumCol;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 500
    };
};

// https://leetcode.com/problems/minimum-moves-to-get-a-peaceful-board/
/*


### 3189. 평화로운 보드를 만들기 위한 최소 이동 횟수

**힌트**
길이 `n`의 2차원 배열 `rooks`가 주어집니다. `rooks[i] = [xi, yi]`는 n x n 체스판 위 i번째 룩의 위치를 나타냅니다. 당신의 목표는 보드가 평화로워지도록 룩들을 한 번에 한 칸씩 수직 또는 수평으로 (인접한 칸으로) 이동시키는 것입니다.

보드는 **각 행과 각 열에 정확히 하나의 룩이 있을 때 평화롭습니다.**

평화로운 보드를 만들기 위해 필요한 최소 이동 횟수를 반환하세요.

어떤 시점에도 두 룩이 같은 칸에 있을 수 없다는 점에 유의하세요.

**예시 1:**

**입력:** `rooks = [[0,0],[1,0],[1,1]]`
**출력:** 3
**설명:**
(이미지 참조: 룩들을 움직여 각 행과 열에 하나씩만 남도록 만드는 과정)

**예시 2:**

**입력:** `rooks = [[0,0],[0,1],[0,2],[0,3]]`
**출력:** 6
**설명:**
(이미지 참조: 룩들을 움직여 각 행과 열에 하나씩만 남도록 만드는 과정)

**제약 조건:**

*   `1 <= n == rooks.length <= 500`
*   `0 <= xi, yi <= n - 1`
*   입력은 두 룩이 같은 칸에 있지 않도록 생성됩니다.
*/
