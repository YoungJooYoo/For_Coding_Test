class Solution {
public:
    int maxWidthOfVerticalArea(const std::vector<std::vector<int>>& points) 
    {
        std::set<int> x_coordinates;

        // Collect unique x-coordinates
        for (const auto& coord : points) {
            x_coordinates.insert(coord[0]);
        }

        int max_difference = 0;
        int prev_x = *x_coordinates.begin();

        // Calculate the maximum difference between adjacent x-coordinates
        for (const int current_x : x_coordinates) {
            max_difference = std::max(max_difference, current_x - prev_x);
            prev_x = current_x;
        }

        return max_difference;
    }
};

// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/

/*

### 번역
1637. 두 점을 포함하지 않는 가장 넓은 수직 영역
쉬움
주제
회사
힌트
2D 평면 상에 n개의 점이 주어지는 경우, points[i] = [xi, yi]로 표현됩니다. 어떤 점도 해당 영역에 포함되지 않도록 두 점 사이의 가장 넓은 수직 영역을 반환하세요.

수직 영역은 y축을 따라 무한히 넓은 폭을 가진 영역입니다(즉, 무한한 높이). 가장 넓은 수직 영역은 최대 폭을 가진 것입니다.

수직 영역의 가장자리에 있는 점은 해당 영역에 포함되지 않는다는 점에 유의하세요.

예시 1:

​
입력: points = [[8,7],[9,9],[7,4],[9,7]]
출력: 1
설명: 빨간색과 파란색 영역 모두 최적입니다.

예시 2:

입력: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
출력: 3
 

제한 사항:

- n == points.length
- 2 <= n <= 105
- points[i].length == 2
- 0 <= xi, yi <= 109


### 요약
주어진 2D 평면 상의 점들 중에서 어떤 두 점도 수직 영역에 포함되지 않도록 하는 최대 폭을 찾아 반환하는 문제입니다.


### 문제풀이 방향
1. 주어진 점들을 x 좌표를 기준으로 정렬합니다.
2. 정렬된 각 인접한 두 점 사이의 x 좌표 차이를 계산하여 가장 큰 차이를 찾습니다. (넓이는 차이 + 1이 됩니다. +1은 두 점 사이에 다른 점이 없는 경우를 처리합니다.)
3. 찾은 최대 차이를 반환합니다.

*/
