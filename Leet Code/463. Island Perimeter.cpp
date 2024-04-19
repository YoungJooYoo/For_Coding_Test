class Solution {
public:
    int islandPerimeter(const vector<vector<int>>& grid) const 
    {
        const int m = grid.size(); // row
        const int n = grid[0].size(); // column
        int perimeter = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i + 1 < m && grid[i + 1][j] == 1) { // if down neighbor exists
                        --perimeter;
                    }
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) { // if up neighbor exists
                        --perimeter;
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) { // if left neighbor exists
                        --perimeter;
                    }
                    if (j + 1 < n && grid[i][j + 1] == 1) { // if right neighbor exists
                        --perimeter;
                    }
                }
            }
        }
        
        return perimeter;
    }
};


// https://leetcode.com/problems/island-perimeter/description/

/*

섬의 둘레

주어진 row x col 그리드는 지도를 나타내며, grid[i][j] = 1은 땅을 나타내고 grid[i][j] = 0은 물을 나타냅니다.

그리드 셀은 수평/수직으로 연결되어 있습니다(대각선으로는 연결되지 않음). 그리드는 물로 완전히 둘러싸여 있으며, 정확히 하나의 섬이 있습니다(즉, 하나 이상의 연결된 땅 셀이 있음).

섬에 "호수"가 없으므로, 안에있는 물이 섬 주변의 물과 연결되어 있지 않습니다. 하나의 셀은 한 변이 1인 정사각형입니다. 그리드는 직사각형이며, 너비와 높이가 각각 100을 초과하지 않습니다. 섬의 둘레를 결정하세요.

예시:

입력: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
출력: 16
설명: 둘레는 위의 이미지에서 노란색 줄로 구성됩니다.
입력: grid = [[1]]
출력: 4
입력: grid = [[1,0]]
출력: 4

제약 조건:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j]는 0 또는 1입니다.
그리드에는 정확히 하나의 섬이 있습니다.

*/
