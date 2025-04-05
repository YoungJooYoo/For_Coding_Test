class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        const int m = rooms.size();
        const int n = rooms[0].size();
        set<pair<int, int>> gates;

        assert(m >= MIN_LENGTH && m <= MAX_LENGTH);
        assert(n >= MIN_LENGTH && n <= MAX_LENGTH);
        
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (rooms[i][j] == GATE) 
                {
                    gates.insert({i, j});
                }
            }
        }
        
        for (const auto& gate : gates) 
        {
            findRouteRecursive(rooms, gate);
        }
    }

private:
    void findRouteRecursive(vector<vector<int>>& rooms, const pair<int,int>& gate) 
    {
        const int m = rooms.size();
        const int n = rooms[0].size();
        const int i = gate.first;
        const int j = gate.second;
        
        stack<vector<int>> S;  // 각 원소는 {행, 열, 현재까지 거리}를 저장합니다.
        set<pair<int, int>> visited;

        S.push({i, j, 0});
        
        while (!S.empty()) 
        {
            const vector<int> cur = S.top();
            S.pop();
            const int i1 = cur[0]; 
            const int j1 = cur[1];
            const int dist = cur[2];
            
            visited.insert({i1, j1}); // 방문 처리
            rooms[i1][j1] = min(rooms[i1][j1], dist); // 현재 저장된 값과 계산된 거리를 비교하여 더 작은 값을 저장합니다.
            
            // 위쪽 (North)
            if (i1 > 0 && (visited.find({i1 - 1, j1}) == visited.end() || rooms[i1 - 1][j1] > dist + 1) &&
                rooms[i1 - 1][j1] != OBSTACLE && rooms[i1 - 1][j1] != GATE) 
            {
                S.push({i1 - 1, j1, dist + 1});
            }
            // 아래쪽 (South)
            if (i1 + 1 < m && (visited.find({i1 + 1, j1}) == visited.end() || rooms[i1 + 1][j1] > dist + 1) &&
                rooms[i1 + 1][j1] != OBSTACLE && rooms[i1 + 1][j1] != GATE) 
            {
                S.push({i1 + 1, j1, dist + 1});
            }
            // 왼쪽 (West)
            if (j1 > 0 && (visited.find({i1, j1 - 1}) == visited.end() || rooms[i1][j1 - 1] > dist + 1) &&
                rooms[i1][j1 - 1] != OBSTACLE && rooms[i1][j1 - 1] != GATE) 
            {
                S.push({i1, j1 - 1, dist + 1});
            }
            // 오른쪽 (East)
            if (j1 + 1 < n && (visited.find({i1, j1 + 1}) == visited.end() || rooms[i1][j1 + 1] > dist + 1) &&
                rooms[i1][j1 + 1] != OBSTACLE && rooms[i1][j1 + 1] != GATE) 
            {
                S.push({i1, j1 + 1, dist + 1});
            }
        }
    }
    
private:
    enum {
        MIN_LENGTH = 1,
        MAX_LENGTH = 250,
        OBSTACLE = -1,
        GATE = 0,
        EMPTY_ROOM = 2147483647
    };
};

// https://leetcode.com/problems/walls-and-gates/

/*
다음은 주어진 문제의 한글 번역입니다.

---

**문제 설명**  
m x n 크기의 격자 rooms가 주어지며, 각 칸은 다음 세 가지 값 중 하나로 초기화되어 있습니다.

- **-1:** 벽 또는 장애물  
- **0:** 문  
- **INF:** 빈 방을 의미하며, INF는 2³¹ - 1 = 2147483647로 표현됩니다. (문까지의 거리는 항상 2147483647보다 작다고 가정할 수 있습니다.)

각 빈 방(empty room)에 대해 가장 가까운 문의 거리로 해당 칸을 채우세요. 만약 문에 도달할 수 없는 경우에는 해당 칸을 INF로 남겨둡니다.

---

**예제 1:**

- **입력:**  
  `rooms = [[2147483647,-1,0,2147483647],  
  [2147483647,2147483647,2147483647,-1],  
  [2147483647,-1,2147483647,-1],  
  [0,-1,2147483647,2147483647]]`

- **출력:**  
  `[[3,-1,0,1],  
  [2,2,1,-1],  
  [1,-1,2,-1],  
  [0,-1,3,4]]`

---

**예제 2:**

- **입력:**  
  `rooms = [[-1]]`

- **출력:**  
  `[[ -1 ]]`

---

**제약 조건:**

- m == rooms.length  
- n == rooms[i].length  
- 1 <= m, n <= 250  
- rooms[i][j]는 -1, 0, 또는 2³¹ - 1 중 하나입니다.
*/
