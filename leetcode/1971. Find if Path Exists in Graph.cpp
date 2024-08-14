class Solution 
{
public:
    bool validPath(const int n, const vector<std::vector<int>>& edges, const int source, const int destination) 
    {
        // 그래프를 인접 리스트로 표현
        vector<std::vector<int>> graph(n);

        for (const auto& edge : edges) 
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // 방문 여부를 저장할 배열
        vector<bool> visited(n, false);
        
        // DFS를 사용해 경로 탐색
        return dfs(graph, visited, source, destination);
    }

private:
    bool dfs(const vector<vector<int>>& graph, vector<bool>& visited, const int current, const int destination) 
    {
        if (current == destination) return true;  // 목적지에 도달한 경우

        visited[current] = true;  // 현재 정점 방문 처리

        for (const int neighbor : graph[current]) 
        {
            if (visited[neighbor] == false) 
            {  // 방문하지 않은 이웃 정점에 대해 탐색
                if (dfs(graph, visited, neighbor, destination) == true) 
                {
                    return true;  // 목적지에 도달하면 true 반환
                }
            }
        }

        return false;  // 모든 이웃을 탐색했지만 목적지에 도달하지 못한 경우
    }
};

// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

/*
### 문제 설명:

주어진 문제는 양방향 그래프에 관한 것입니다. 이 그래프는 `n`개의 정점을 가지며, 각 정점은 0부터 n-1까지의 번호가 매겨져 있습니다. 그래프의 간선들은 `edges`라는 2D 정수 배열로 주어지며, 각 `edges[i] = [ui, vi]`는 정점 `ui`와 정점 `vi` 사이의 양방향 간선을 나타냅니다. 모든 정점 쌍은 최대 하나의 간선으로 연결되며, 자기 자신과 연결된 간선은 존재하지 않습니다.

주어진 그래프에서 정점 `source`에서 정점 `destination`으로 가는 유효한 경로가 존재하는지 확인해야 합니다.

### 입력 형식:

- `n`: 정점의 수 (1 ≤ n ≤ 200,000)
- `edges`: 간선 정보가 담긴 2D 정수 배열 (0 ≤ edges.length ≤ 200,000)
- `source`: 시작 정점 (0 ≤ source ≤ n - 1)
- `destination`: 도착 정점 (0 ≤ destination ≤ n - 1)

### 출력 형식:

- 정점 `source`에서 정점 `destination`으로 가는 경로가 존재하면 `true`를, 그렇지 않으면 `false`를 반환하세요.

### 예제:

**예제 1:**

- 입력: `n = 3`, `edges = [[0,1],[1,2],[2,0]]`, `source = 0`, `destination = 2`
- 출력: `true`
- 설명: 정점 0에서 정점 2로 가는 두 가지 경로가 있습니다:
  - 0 → 1 → 2
  - 0 → 2

**예제 2:**

- 입력: `n = 6`, `edges = [[0,1],[0,2],[3,5],[5,4],[4,3]]`, `source = 0`, `destination = 5`
- 출력: `false`
- 설명: 정점 0에서 정점 5로 가는 경로는 없습니다.

### 제약 조건:

- 정점의 수 `n`은 1 이상 200,000 이하입니다.
- 간선의 수는 0 이상 200,000 이하입니다.
- 각 간선은 두 개의 정점 사이를 연결하며, 자기 자신과 연결된 간선은 존재하지 않습니다.
- 입력에 중복된 간선은 없습니다.

*/
