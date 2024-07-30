class Solution 
{
public:
    int distanceBetweenBusStops(const vector<int>& distances, int start, int destination) 
    {
        int clockwiseDistance = 0;
        int counterClockwiseDistance = 0;

        if (start > destination)  
        {
            swap(start, destination);
        }

        for (size_t i = 0; i < distances.size(); ++i) 
        {
            if (i >= start && i < destination) clockwiseDistance += distances[i];
            else counterClockwiseDistance += distances[i];
        }

        return min(clockwiseDistance, counterClockwiseDistance);
    }
};

// https://leetcode.com/problems/distance-between-bus-stops/

/*

### 1184. 버스 정류장 간 거리

**난이도: 쉬움**

#### 문제 설명

버스에는 0부터 n - 1까지 번호가 매겨진 n개의 정류장이 있으며, 이 정류장들은 원형을 이루고 있습니다. `
distance[i]`는 정류장 i와 (i + 1) % n번 정류장 사이의 거리를 나타냅니다.

버스는 시계 방향과 반시계 방향 모두로 이동할 수 있습니다.

주어진 출발 정류장(start)과 목적지 정류장(destination) 사이의 최단 거리를 반환하세요.


#### 예제

**예제 1**:

- 입력: `distance = [1,2,3,4]`, `start = 0`, `destination = 1`
- 출력: `1`
- 설명: 정류장 0과 1 사이의 거리는 1 또는 9이며, 최소 거리는 1입니다.

**예제 2**:

- 입력: `distance = [1,2,3,4]`, `start = 0`, `destination = 2`
- 출력: `3`
- 설명: 정류장 0과 2 사이의 거리는 3 또는 7이며, 최소 거리는 3입니다.

**예제 3**:

- 입력: `distance = [1,2,3,4]`, `start = 0`, `destination = 3`
- 출력: `4`
- 설명: 정류장 0과 3 사이의 거리는 6 또는 4이며, 최소 거리는 4입니다.


#### 제약 조건

- `1 <= n <= 10^4`
- `distance.length == n`
- `0 <= start, destination < n`
- `0 <= distance[i] <= 10^4`


*/
