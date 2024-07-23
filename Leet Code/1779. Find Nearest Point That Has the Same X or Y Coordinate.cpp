class Solution 
{
public:
    int nearestValidPoint(const int x, const int y, const vector<vector<int>>& points) 
    {
        int result = -1;
        int minDistance = numeric_limits<int>::max();

        for (int i = 0; i < points.size(); ++i) 
        {
            const int x1 = points[i][0];
            const int y1 = points[i][1];
            
            // 유효한 점인지 확인합니다.
            if (x1 == x || y1 == y) 
            {
                const int distance = abs(x - x1) + abs(y - y1);
                
                // 가장 작은 거리와 인덱스를 업데이트합니다.
                if (distance < minDistance) 
                {
                    minDistance = distance;
                    result = i;
                }
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/description/

/*

### 1779. 동일한 X 또는 Y 좌표를 가진 가장 가까운 점 찾기

**난이도: 쉬움**

#### 문제 설명

두 정수 `x`와 `y`가 주어지며, 이는 카르테시안 좌표계에서 당신의 현재 위치 `(x, y)`를 나타냅니다. 또한, 각 `points[i] = [ai, bi]`가 `(ai, bi)` 위치에 점이 있음을 나타내는 배열 `points`가 주어집니다. 점이 유효하려면, 해당 점이 당신의 위치와 동일한 x 좌표 또는 y 좌표를 가져야 합니다.

유효한 점 중에서 현재 위치와 가장 가까운 맨해튼 거리를 가진 점의 인덱스(0-인덱스)를 반환하세요. 만약 여러 개의 점이 있다면, 가장 작은 인덱스를 가진 유효한 점을 반환하세요. 유효한 점이 없으면 -1을 반환하세요.

두 점 `(x1, y1)`과 `(x2, y2)` 사이의 맨해튼 거리는 `abs(x1 - x2) + abs(y1 - y2)` 입니다.

#### 예제

**예제 1**:

- 입력: `x = 3, y = 4`, `points = [[1,2],[3,1],[2,4],[2,3],[4,4]]`
- 출력: `2`
- 설명: 모든 점 중에서 `[3,1]`, `[2,4]`, `[4,4]`가 유효합니다. 유효한 점 중에서 `[2,4]`와 `[4,4]`가 현재 위치와 가장 가까운 맨해튼 거리를 가지며, 거리 값은 1입니다. `[2,4]`가 가장 작은 인덱스를 가지므로, 2를 반환합니다.

**예제 2**:

- 입력: `x = 3, y = 4`, `points = [[3,4]]`
- 출력: `0`
- 설명: 정답은 현재 위치와 동일한 위치에 있을 수 있습니다.

**예제 3**:

- 입력: `x = 3, y = 4`, `points = [[2,3]]`
- 출력: `-1`
- 설명: 유효한 점이 없습니다.

#### 제약 조건

- `1 <= points.length <= 10^4`
- `points[i].length == 2`
- `1 <= x, y, ai, bi <= 10^4`
*/
