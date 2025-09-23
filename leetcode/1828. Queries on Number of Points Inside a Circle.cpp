class Solution
{
public:
    vector<int> countPoints(const vector<vector<int>>& points, const vector<vector<int>>& queries) const
    {
        const size_t pn = points.size();
        const size_t qn = queries.size();
        vector<int> answer;

        assert(pn >= static_cast<size_t>(MIN_POINTS_LENGTH) && pn <= static_cast<size_t>(MAX_POINTS_LENGTH));
        assert(qn >= static_cast<size_t>(MIN_QUERIES_LENGTH) && qn <= static_cast<size_t>(MAX_QUERIES_LENGTH));

        for (size_t j = 0; j < qn; ++j)
        {
            assert(queries[j].size() == static_cast<size_t>(QUERY_ELEM_LENGTH)); // 쿼리 크기/범위 검증을 먼저 수행
            const int cx = queries[j][0];
            const int cy = queries[j][1];
            const int r  = queries[j][2];
            const int r2 = r * r;
            int insideCount = 0;

            assert(cx >= MIN_COORD && cx <= MAX_COORD);
            assert(cy >= MIN_COORD && cy <= MAX_COORD);
            assert(r  >= MIN_RADIUS && r  <= MAX_RADIUS);

            for (size_t i = 0; i < pn; ++i)
            {
                assert(points[i].size() == static_cast<size_t>(POINT_ELEM_LENGTH));
                const int px = points[i][0];
                const int py = points[i][1];
                const int dx = px - cx;
                const int dy = py - cy;
                const int d2 = (dx * dx) + (dy * dy);
                assert(px >= MIN_COORD && px <= MAX_COORD);
                assert(py >= MIN_COORD && py <= MAX_COORD);
                if (d2 <= r2)
                {
                    ++insideCount;
                }
            }

            answer.push_back(insideCount);
        }

        return answer;
    }

private:
    enum
    {
        MIN_POINTS_LENGTH = 1,
        MAX_POINTS_LENGTH = 500,
        POINT_ELEM_LENGTH = 2,
        MIN_COORD = 0,
        MAX_COORD = 500,

        MIN_QUERIES_LENGTH = 1,
        MAX_QUERIES_LENGTH = 500,
        QUERY_ELEM_LENGTH = 3,
        MIN_RADIUS = 1,
        MAX_RADIUS = 500
    };
};

// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/description/

/*
네, 문제 내용을 한국어로 번역해 드릴게요.

**1828. 원 안에 있는 점의 수**

`points` 배열이 주어집니다. `points[i] = [xi, yi]`는 2D 평면 위에 있는 i번째 점의 좌표를 나타냅니다. 여러 점이 동일한 좌표를 가질 수 있습니다.

또한 `queries` 배열이 주어집니다. `queries[j] = [xj, yj, rj]`는 중심이 `(xj, yj)`이고 반지름이 `rj`인 원을 나타냅니다.

각 `queries[j]`에 대해, j번째 원 안에 있는 점의 개수를 계산하세요. 원의 경계에 있는 점도 원 안에 있는 것으로 간주합니다.

`answer` 배열을 반환하세요. 여기서 `answer[j]`는 j번째 쿼리에 대한 답입니다.

**예시 1:**
![예시 1 이미지](https://assets.leetcode.com/uploads/2021/03/14/points_within_a_circle_1.png)
**입력:** `points = [[1,3],[3,3],[5,3],[2,2]]`, `queries = [[2,3,1],[4,3,1],[1,1,2]]`
**출력:** `[3,2,2]`
**설명:** 위 그림에 점과 원이 표시되어 있습니다.
`queries[0]`은 녹색 원, `queries[1]`은 빨간색 원, `queries[2]`는 파란색 원입니다.

**예시 2:**
![예시 2 이미지](https://assets.leetcode.com/uploads/2021/03/14/points_within_a_circle_2.png)
**입력:** `points = [[1,1],[2,2],[3,3],[4,4],[5,5]]`, `queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]`
**출력:** `[2,3,2,4]`
**설명:** 위 그림에 점과 원이 표시되어 있습니다.
`queries[0]`은 녹색, `queries[1]`은 빨간색, `queries[2]`는 파란색, `queries[3]`은 보라색 원입니다.

**제약 조건:**

*   `1 <= points.length <= 500`
*   `points[i].length == 2`
*   `0 <= xi, yi <= 500`
*   `1 <= queries.length <= 500`
*   `queries[j].length == 3`
*   `0 <= xj, yj <= 500`
*   `1 <= rj <= 500`
*   모든 좌표는 정수입니다.

**추가 질문:** O(n)보다 더 나은 시간 복잡도로 각 쿼리에 대한 답을 찾을 수 있을까요?
*/
