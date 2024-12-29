class Solution 
{
public:
    int robotSim(const vector<int>& commands, const vector<vector<int>>& obstacles) 
    {
        int maxSquaredEuclideanDistance = 0;
        set<pair<int, int>> obstacleSet;
        int x = 0;
        int y = 0; 
        int currentDirection = NORTH;
        

        for (const auto& obs : obstacles)
        {
            obstacleSet.insert({obs[0], obs[1]});
        }

        for (const int command : commands) 
        {
            if (command == TURN_LEFT) 
            {
                // 왼쪽 회전
                currentDirection = (currentDirection + 3) % 4;
            } 
            else if (command == TURN_RIGHT) 
            {
                // 오른쪽 회전
                currentDirection = (currentDirection + 1) % 4;
            } 
            else 
            {
                // 앞으로 이동
                for (int step = 0; step < command; ++step) 
                {
                    const int nextX = x + mDirections[currentDirection].first;
                    const int nextY = y + mDirections[currentDirection].second;

                    // 장애물 확인
                    if (obstacleSet.count({nextX, nextY})) 
                    {
                        break; // 장애물이 있으면 이동 중단
                    }

                    // 위치 업데이트
                    x = nextX;
                    y = nextY;

                    // 최대 유클리드 거리 제곱값 갱신
                    maxSquaredEuclideanDistance = max(maxSquaredEuclideanDistance, x * x + y * y);
                }
            }
        }

        return maxSquaredEuclideanDistance;
    }

private:
    const vector<pair<int, int>> mDirections = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 북, 동, 남, 서

    enum 
    {
        TURN_LEFT = -2,
        TURN_RIGHT = -1,
        NORTH = 0,
        EAST = 1,
        SOUTH = 2,
        WEST = 3,
    };
};

// https://leetcode.com/problems/walking-robot-simulation/description/

/*
**874. 로봇 경로 시뮬레이션**  
**난이도**: Medium  

---

### 문제 설명

무한한 XY 평면 위에 있는 로봇이 (0, 0) 지점에서 북쪽을 향해 시작합니다. 로봇은 정수 배열 `commands`를 받아야 할 이동 명령의 시퀀스를 나타냅니다. 로봇이 받을 수 있는 명령은 다음 세 가지입니다:  

- **-2**: 90도 왼쪽으로 회전합니다.  
- **-1**: 90도 오른쪽으로 회전합니다.  
- **1 <= k <= 9**: 앞으로 \(k\) 칸만큼 이동합니다. 한 번에 한 칸씩 이동합니다.  

일부 그리드에는 장애물이 존재합니다. \(i\)번째 장애물은 `obstacles[i] = (x_i, y_i)`에 위치합니다. 로봇이 장애물에 부딪히면, 현재 위치(장애물과 인접한 블록)에 멈춘 후 다음 명령으로 넘어갑니다.  

로봇이 경로 중에서 원점으로부터 가장 멀리 도달한 지점의 **유클리드 거리의 제곱값**을 반환하세요. (즉, 거리가 5일 경우, \(25\)를 반환합니다).  

---

### 참고 사항
1. \( (0, 0) \)에 장애물이 있을 수 있습니다. 이 경우, 로봇은 원점을 벗어날 때까지 장애물을 무시합니다. 그러나 원점으로 다시 돌아갈 수 없습니다.
2. **북쪽**은 +Y 방향을 의미합니다.  
3. **동쪽**은 +X 방향을 의미합니다.  
4. **남쪽**은 -Y 방향을 의미합니다.  
5. **서쪽**은 -X 방향을 의미합니다.  

---

### 예제

**예제 1**:  
- **입력**:  
  ```text
  commands = [4, -1, 3]
  obstacles = []
  ```
- **출력**:  
  ```text
  25
  ```
- **설명**:  
  로봇은 다음 경로를 이동합니다:  
  1. (0, 0)에서 북쪽으로 4칸 이동 → (0, 4)  
  2. 오른쪽으로 회전  
  3. 동쪽으로 3칸 이동 → (3, 4)  
  로봇이 원점에서 가장 멀리 이동한 지점은 (3, 4)이며, 제곱된 거리는 \(3^2 + 4^2 = 25\)입니다.  

---

**예제 2**:  
- **입력**:  
  ```text
  commands = [4, -1, 4, -2, 4]
  obstacles = [[2, 4]]
  ```
- **출력**:  
  ```text
  65
  ```
- **설명**:  
  로봇은 다음 경로를 이동합니다:  
  1. (0, 0)에서 북쪽으로 4칸 이동 → (0, 4)  
  2. 오른쪽으로 회전  
  3. 동쪽으로 1칸 이동, (2, 4)의 장애물에 막힘 → (1, 4)  
  4. 왼쪽으로 회전  
  5. 북쪽으로 4칸 이동 → (1, 8)  
  로봇이 원점에서 가장 멀리 이동한 지점은 (1, 8)이며, 제곱된 거리는 \(1^2 + 8^2 = 65\)입니다.  

---

**예제 3**:  
- **입력**:  
  ```text
  commands = [6, -1, -1, 6]
  obstacles = [[0, 0]]
  ```
- **출력**:  
  ```text
  36
  ```
- **설명**:  
  로봇은 다음 경로를 이동합니다:  
  1. (0, 0)에서 북쪽으로 6칸 이동 → (0, 6)  
  2. 오른쪽으로 회전  
  3. 오른쪽으로 회전  
  4. 남쪽으로 5칸 이동, (0, 0)의 장애물에 막힘 → (0, 1)  
  로봇이 원점에서 가장 멀리 이동한 지점은 (0, 6)이며, 제곱된 거리는 \(6^2 = 36\)입니다.  

---

### 제약 조건
1. \(1 \leq \text{commands.length} \leq 10^4\)
2. \(commands[i]\)는 \(-2, -1\) 또는 \([1, 9]\) 범위의 정수입니다.
3. \(0 \leq \text{obstacles.length} \leq 10^4\)
4. \(-3 \times 10^4 \leq x_i, y_i \leq 3 \times 10^4\)
5. 결과는 \(2^{31}\)보다 작음이 보장됩니다.  
*/
