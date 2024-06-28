class Solution 
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> cells;
        
        // 모든 셀의 좌표를 생성
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                cells.push_back({r, c});
            }
        }
        
        // 거리 순으로 정렬
        sort(cells.begin(), cells.end(), [rCenter, cCenter](const vector<int>& a, const vector<int>& b) {
            int distA = abs(a[0] - rCenter) + abs(a[1] - cCenter);
            int distB = abs(b[0] - rCenter) + abs(b[1] - cCenter);
            return distA < distB;
        });
        
        return cells;
    }
};

// https://leetcode.com/problems/matrix-cells-in-distance-order/

/*

1030. 거리 순서대로 행렬의 셀 반환
난이도: 쉬움

문제 설명
네 개의 정수 rows, cols, rCenter, cCenter가 주어집니다. rows x cols 크기의 행렬이 있으며, 당신은 (rCenter, cCenter) 좌표에 위치해 있습니다.

(가장 가까운 거리에서 가장 먼 거리 순으로) (rCenter, cCenter)에서부터의 거리로 정렬된 모든 셀의 좌표를 반환하세요. 이 조건을 만족하는 어떠한 순서로든 답을 반환할 수 있습니다.

두 셀 (r1, c1)과 (r2, c2) 사이의 거리는 |r1 - r2| + |c1 - c2| 입니다.

예제
예제 1:

입력: rows = 1, cols = 2, rCenter = 0, cCenter = 0
출력: [[0,0],[0,1]]
설명: (0, 0)에서 다른 셀까지의 거리는 [0, 1] 입니다.
예제 2:

입력: rows = 2, cols = 2, rCenter = 0, cCenter = 1
출력: [[0,1],[0,0],[1,1],[1,0]]
설명: (0, 1)에서 다른 셀까지의 거리는 [0, 1, 1, 2] 입니다.
[[0,1],[1,1],[0,0],[1,0]]도 정답으로 인정됩니다.
예제 3:

입력: rows = 2, cols = 3, rCenter = 1, cCenter = 2
출력: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
설명: (1, 2)에서 다른 셀까지의 거리는 [0, 1, 1, 2, 2, 3] 입니다.
[[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]도 정답으로 인정됩니다.
제약 조건
1 <= rows, cols <= 100
0 <= rCenter < rows
0 <= cCenter < cols

*/
