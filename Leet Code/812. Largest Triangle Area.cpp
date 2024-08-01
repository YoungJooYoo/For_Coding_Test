class Solution 
{
public:
    double largestTriangleArea(const vector<vector<int>>& points) 
    {
        const size_t LENGTH = points.size();
        double maxArea = 0.0;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            const int x1 = points[i][0];
            const int y1 = points[i][1];
            for (size_t j = i + 1; j < LENGTH; ++j)
            {
                const int x2 = points[j][0];
                const int y2 = points[j][1];
                for (size_t k = j + 1; k < LENGTH; ++k)
                {
                    const int x3 = points[k][0];
                    const int y3 = points[k][1];
                    const double area = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
                    maxArea = max(maxArea, area); 
                }
            }
        }

        return maxArea;
    }
};

// https://leetcode.com/problems/largest-triangle-area/

/*
### 812. 가장 큰 삼각형 면적

**난이도: 쉬움**

#### 문제 설명

X-Y 평면상의 점들을 나타내는 배열 `points`가 주어지며, `points[i] = [xi, yi]`입니다. 서로 다른 세 점으로 만들 수 있는 가장 큰 삼각형의 면적을 반환하세요. 실제 답과의 오차가 `10^-5` 이내인 답은 정답으로 인정됩니다.

#### 예제

**예제 1**:

- **입력**: `points = [[0,0],[0,1],[1,0],[0,2],[2,0]]`
- **출력**: `2.00000`
- **설명**: 위 그림에서 다섯 점이 표시되어 있습니다. 빨간 삼각형이 가장 큽니다.

**예제 2**:

- **입력**: `points = [[1,0],[0,0],[0,1]]`
- **출력**: `0.50000`

#### 제약 조건

- `3 <= points.length <= 50`
- `-50 <= xi, yi <= 50`
- 주어진 모든 점들은 고유합니다.

*/
