class Solution {
public:
    int minTimeToVisitAllPoints(const vector<vector<int>>& points) 
    {
        int totalTime = 0;

        for (size_t i = 1; i < points.size(); ++i)
        {
            const int x1 = points[i - 1][0];
            const int y1 = points[i - 1][1];
            const int x2 = points[i][0];
            const int y2 = points[i][1];

            totalTime += max(abs(x2 - x1), abs(y2 - y1));
        }

        return totalTime;
    }
};

//  https://leetcode.com/problems/minimum-time-visiting-all-points/

/*


문제 번역
1266. 모든 점을 방문하는 최소 시간

난이도: 쉬움

문제 설명
2D 평면에 정수 좌표로 이루어진 n개의 점이 주어집니다. points[i] = [xi, yi]로 주어지는 이 점들을 주어진 순서대로 방문하는 데 걸리는 최소 시간을 초 단위로 반환하세요.

다음 규칙에 따라 움직일 수 있습니다:

1초 동안 수직으로 한 단위 이동할 수 있습니다.
1초 동안 수평으로 한 단위 이동할 수 있습니다.
1초 동안 대각선으로 sqrt(2) 단위(즉, 1초 동안 수직으로 한 단위, 수평으로 한 단위 이동)로 이동할 수 있습니다.
점들은 배열에 나타난 순서대로 방문해야 합니다. 나중에 나타나는 점을 통과할 수는 있지만, 방문으로 간주되지 않습니다.

예제
예제 1:

입력: points = [[1,1],[3,4],[-1,0]]
출력: 7
설명:
최적 경로 중 하나는 [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]
[1,1]에서 [3,4]로 가는 데 3초 걸림
[3,4]에서 [-1,0]으로 가는 데 4초 걸림
총 시간 = 7초
예제 2:

입력: points = [[3,2],[-2,2]]
출력: 5
제약 조건
points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000

*/
