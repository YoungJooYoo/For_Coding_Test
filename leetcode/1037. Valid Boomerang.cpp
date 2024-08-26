class Solution {
public:
    bool isBoomerang(const vector<vector<int>>& points) 
    {
        const int x1 = points[0][0];
        const int y1 = points[0][1];

        const int x2 = points[1][0];
        const int y2 = points[1][1];

        const int x3 = points[2][0];
        const int y3 = points[2][1];

        return (x3 - x2) * (y2 -  y1) != (x2 - x1) * (y3 - y2) ? true : false;
    }
};

// https://leetcode.com/problems/valid-boomerang/description/

/*

### 문제 번역:

1037. 유효한 부메랑

**난이도: 쉬움**

다음과 같은 조건이 주어집니다:

- 배열 `points`가 주어지며, `points[i] = [xi, yi]`는 X-Y 평면의 한 점을 나타냅니다. 이 세 점이 부메랑인 경우 `true`를 반환하세요.

부메랑이란 세 점이 모두 서로 다르며 동일한 직선 상에 있지 않은 점들을 의미합니다.

### 예제:

**예제 1:**

- 입력: `points = [[1,1],[2,3],[3,2]]`
- 출력: `true`

**예제 2:**

- 입력: `points = [[1,1],[2,2],[3,3]]`
- 출력: `false`

### 제약 조건:

- `points.length == 3`
- `points[i].length == 2`
- `0 <= xi, yi <= 100`

*/
