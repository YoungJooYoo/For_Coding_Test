class Solution 
{
public:
    int projectionArea(const vector<vector<int>>& grid) 
    {
        const int n = grid.size();
        int xyProjection = 0;
        int yzProjection = 0;
        int zxProjection = 0;
        
        for (size_t i = 0; i < n; ++i) 
        {
            int maxInRow = 0;
            int maxInCol = 0;
            for (size_t j = 0; j < n; ++j) 
            {
                if (grid[i][j] > 0) 
                {
                    ++xyProjection;
                }
                maxInRow = max(maxInRow, grid[i][j]);
                maxInCol = max(maxInCol, grid[j][i]);
            }
            zxProjection += maxInRow;
            yzProjection += maxInCol;
        }

        return xyProjection + yzProjection + zxProjection;
    }
};

// https://leetcode.com/problems/projection-area-of-3d-shapes/description/

/*

문제 설명
Projection Area of 3D Shapes
3D 큐브가 놓인 n x n 그리드가 주어집니다. 각 값 v = grid[i][j]는 (i, j) 셀에 놓인 큐브 타워의 높이를 나타냅니다.

이 큐브의 xy, yz, zx 평면으로의 투영을 봅니다.

투영은 3차원 도형을 2차원 평면으로 매핑하는 그림자와 같습니다. 우리는 큐브를 위, 앞, 옆에서 볼 때의 "그림자"를 보고 있습니다.

모든 세 가지 투영의 총 면적을 반환하세요.

예제
예제 1:

입력: grid = [[1,2],[3,4]]
출력: 17
설명: 각 축에 정렬된 평면으로 만든 모양의 세 가지 투영("그림자")이 다음과 같습니다.
예제 2:

입력: grid = [[2]]
출력: 5
예제 3:

입력: grid = [[1,0],[0,2]]
출력: 8
제약 조건
n == grid.length == grid[i].length
1 <= n <= 50
0 <= grid[i][j] <= 50
문제 풀이 힌트
xy 평면 투영:

grid[i][j]가 0이 아닌 모든 셀의 개수를 계산합니다.
yz 평면 투영:

각 열에서 가장 큰 값을 찾습니다.
zx 평면 투영:

각 행에서 가장 큰 값을 찾습니다.
*/
