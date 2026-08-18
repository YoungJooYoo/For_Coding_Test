class Solution
{
public:
    int nearestDrone(const vector<vector<int>>& drones, const vector<int>& target) const
    {
        assert(MIN_LENGTH <= drones.size() && drones.size() <= MAX_LENGTH);
        assert(target.size() == TARGET_SIZE);
        assert(MIN_COORDINATE <= target[X] && target[X] <= MAX_COORDINATE);
        assert(MIN_COORDINATE <= target[Y] && target[Y] <= MAX_COORDINATE);

        int minDistance = numeric_limits<int>::max();
        int minIndex = FAIL;
        int currentIndex = 0;

        for (const auto& drone : drones)
        {
            assert(drone.size() == DRONE_SIZE);
            assert(MIN_COORDINATE <= drone[X] && drone[X] <= MAX_COORDINATE);
            assert(MIN_COORDINATE <= drone[Y] && drone[Y] <= MAX_COORDINATE);
            assert(MIN_RANGE <= drone[RANGE] && drone[RANGE] <= MAX_RANGE);
            const int currentDistance = abs(target[X] - drone[X]) + abs(target[Y] - drone[Y]);
            if (currentDistance <= drone[RANGE] && currentDistance < minDistance)
            {
                minDistance = currentDistance;
                minIndex = currentIndex;
            }
            ++currentIndex;
        }

        return minIndex;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_COORDINATE = -25,
        MAX_COORDINATE = 25,
        MIN_RANGE = 1,
        MAX_RANGE = 100,
        DRONE_SIZE = 3,
        TARGET_SIZE = 2,
        X = 0,
        Y = 1,
        RANGE = 2,
        FAIL = -1
    };
};

/*
https://leetcode.com/problems/nearest-available-drone/description/

## 4024. 가장 가까운 사용 가능한 드론 (Nearest Available Drone)

**난이도: Easy**

2차원 정수 배열 `drones`가 주어지며, `drones[i] = [xi, yi, rangei]`는 `i`번째 드론의 x좌표, y좌표, 그리고 이동 가능 범위를 나타냅니다.

또한 목표 지점의 좌표를 나타내는 정수 배열 `target = [tx, ty]`가 주어집니다.

드론 `drones[i]`의 좌표와 목표 좌표 사이의 **맨해튼 거리**가 `rangei` 이하이면, 그 드론은 목표에 도달할 수 있습니다.

목표에 도달 가능한 드론 중 목표까지의 맨해튼 거리가 **최소**인 드론의 인덱스를 반환하세요. 거리가 같은 경우 **가장 작은 인덱스**를 반환하세요. 어떤 드론도 목표에 도달할 수 없으면 `-1`을 반환하세요.

---

**예제 1:**
```
입력: drones = [[0,0,8],[2,2,9]], target = [3,4]
출력: 1
설명:

- drones[0]과 target 사이의 거리는 |0 - 3| + |0 - 4| = 7이며, 범위 8 이내입니다.
- drones[1]과 target 사이의 거리는 |2 - 3| + |2 - 4| = 3이며, 범위 9 이내입니다.
- drones[1]이 가장 가까운 드론이므로, 정답은 1입니다.
```

**예제 2:**
```
입력: drones = [[2,1,5],[4,4,5],[6,6,8]], target = [5,5]
출력: 1
설명:

- drones[0]과 target 사이의 거리는 |2 - 5| + |1 - 5| = 7이며, 범위 5를 초과합니다.
- drones[1]과 target 사이의 거리는 |4 - 5| + |4 - 5| = 2이며, 범위 5 이내입니다.
- drones[2]과 target 사이의 거리는 |6 - 5| + |6 - 5| = 2이며, 범위 8 이내입니다.
- drones[1]과 drones[2] 모두 가장 가까운 드론입니다. 가장 작은 인덱스를
  반환해야 하므로, 정답은 1입니다.
```

**예제 3:**
```
입력: drones = [[4,4,5]], target = [8,6]
출력: -1
설명:

- drones[0]과 target 사이의 거리는 |4 - 8| + |4 - 6| = 6이며, 범위 5를 초과합니다.
- 어떤 드론도 목표에 도달할 수 없으므로, 정답은 -1입니다.
```

---

**제약 조건:**
- `1 <= drones.length <= 100`
- `drones[i] = [xi, yi, rangei]`
- `target = [tx, ty]`
- `-25 <= xi, yi, tx, ty <= 25`
- `1 <= rangei <= 100`

---

용어 보충:
- **맨해튼 거리(Manhattan distance)**: 두 점 `(x1, y1)`, `(x2, y2)` 사이의 거리를 `|x1 - x2| + |y1 - y2|`로 계산한 것. 격자 도시에서 블록을 따라 이동하는 거리라고 생각하면 됩니다.
*/
