class Solution 
{
public:
    bool satisfiesConditions(const vector<vector<int>>& grid) 
    {
        const size_t row = grid.size();
        const size_t col = grid[0].size();

        for (size_t i = 0; i < row; ++i)
        {
            for (size_t j = 1; j < col; ++j)
            {
                if (grid[i][j - 1] == grid[i][j])
                {
                    return false;
                }
            }
        }

        for (size_t j = 0; j < col; ++j)
        {
            for (size_t i = 1; i < row; ++i)
            {
                if (grid[i - 1][j] != grid[i][j])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};

/*
그리드 조건 충족 여부 확인
쉬움
힌트
크기가 m x n인 2D 행렬 그리드가 주어집니다. 각 셀 grid[i][j]이 다음을 충족하는지 확인해야 합니다.
아래 셀과 같은지, 즉 grid[i][j] == grid[i + 1][j] (해당 셀이 존재하는 경우).
오른쪽 셀과 다른지, 즉 grid[i][j] != grid[i][j + 1] (해당 셀이 존재하는 경우).
모든 셀이 이러한 조건을 충족하면 true를 반환하고, 그렇지 않으면 false를 반환합니다.

예시 1:

입력: grid = [[1,0,2],[1,0,2]]

출력: true

설명:

그리드의 모든 셀이 조건을 충족합니다.

예시 2:

입력: grid = [[1,1,1],[0,0,0]]

출력: false

설명:

첫 번째 행의 모든 셀이 같습니다.

예시 3:

입력: grid = [[1],[2],[3]]

출력: false

설명:

첫 번째 열의 셀들은 서로 다른 값을 가집니다.

제약 조건:

1 <= n, m <= 10
0 <= grid[i][j] <= 9
이 질문을 실제 인터뷰에서 본 적이 있습니까?
1/5
예
아니요
힌트 1
각 열에서 각 셀이 동일한 값을 가지는지 확인합니다.
힌트 2
이전 조건이 충족되면 인접한 열의 첫 번째 셀만 확인하면 됩니다.
*/


// https://leetcode.com/problems/check-if-grid-satisfies-conditions/
