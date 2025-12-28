class Solution
{
public:
    string findSpecialNodes(const int n, const vector<vector<int>>& edges) const
    {
        assert(MIN_N <= n && n <= MAX_N);
        assert(static_cast<int>(edges.size()) == n - 1);

        vector<vector<int>> adjacency(n);
        buildGraph(edges, adjacency);

        const int nodeA = findFarthestNode(START_NODE, adjacency).first;
        const auto [nodeB, diameter] = findFarthestNode(nodeA, adjacency);
        string result(n, '0');
        vector<int> distFromA(n, UNVISITED);
        vector<int> distFromB(n, UNVISITED);

        bfs(nodeA, adjacency, distFromA);
        bfs(nodeB, adjacency, distFromB);
        
        for (int i = 0; i < n; ++i)
        {
            if (distFromA[i] == diameter || distFromB[i] == diameter)
            {
                result[i] = '1';
            }
        }

        return result;
    }

private:
    enum
    {
        MIN_N = 2,
        MAX_N = 100000,
        START_NODE = 0,
        UNVISITED = -1
    };

    void buildGraph(const vector<vector<int>>& edges, vector<vector<int>>& adjacency) const
    {
        for (const auto& edge : edges)
        {
            assert(edge.size() == 2);
            const int u = edge[0];
            const int v = edge[1];
            adjacency[u].push_back(v);
            adjacency[v].push_back(u);
        }
    }

    void bfs(const int start, const vector<vector<int>>& adjacency, vector<int>& distances) const
    {
        queue<int> q;
        q.push(start);
        distances[start] = 0;

        while (!q.empty())
        {
            const int current = q.front();
            q.pop();

            for (const int next : adjacency[current])
            {
                if (distances[next] != UNVISITED)
                {
                    continue;
                }

                distances[next] = distances[current] + 1;
                q.push(next);
            }
        }
    }

    pair<int, int> findFarthestNode(const int start, const vector<vector<int>>& adjacency) const
    {
        const int n = static_cast<int>(adjacency.size());
        vector<int> distances(n, UNVISITED);

        bfs(start, adjacency, distances);

        int farthestNode = start;
        int maxDistance = 0;

        for (int i = 0; i < n; ++i)
        {
            if (distances[i] > maxDistance)
            {
                maxDistance = distances[i];
                farthestNode = i;
            }
        }

        return {farthestNode, maxDistance};
    }
};

// https://leetcode.com/problems/find-diameter-endpoints-of-a-tree/description/

/*

---

### **3787. 트리의 지름 끝점 찾기 (Find Diameter Endpoints of a Tree)**

0부터 `n - 1`까지 번호가 매겨진 `n`개의 노드로 구성된 **무방향(undirected) 트리**가 주어집니다. 트리는 길이 `n - 1`인 2D 정수 배열 `edges`로 표현되며, `edges[i] = [ai, bi]`는 트리의 노드 `ai`와 `bi` 사이에 간선이 있음을 나타냅니다.

트리의 어떤 **지름 경로(diameter path)**의 끝점이 되는 노드를 **특별한(special)** 노드라고 합니다.

길이 `n`인 이진 문자열 `s`를 반환하십시오. 여기서 노드 `i`가 특별한 노드라면 `s[i] = '1'`이고, 그렇지 않다면 `s[i] = '0'`이어야 합니다.

*   **트리의 지름 경로**는 임의의 두 노드 사이의 **가장 긴 단순 경로(simple path)**를 의미합니다. 트리에는 여러 개의 지름 경로가 존재할 수 있습니다.
*   **경로의 끝점**은 해당 경로의 첫 번째 노드 또는 마지막 노드를 의미합니다.

---

**예제 1:**

*   **입력:** `n = 3`, `edges = [[0,1],[1,2]]`
*   **출력:** `"101"`
*   **설명:**
    *   이 트리의 지름은 2개의 간선으로 구성됩니다.
    *   유일한 지름 경로는 노드 0에서 노드 2로 가는 경로입니다.
    *   이 경로의 끝점은 노드 0과 2이므로, 이들은 특별한 노드입니다.

**예제 2:**

*   **입력:** `n = 7`, `edges = [[0,1],[1,2],[2,3],[3,4],[3,5],[1,6]]`
*   **출력:** `"1000111"`
*   **설명:**
    *   이 트리의 지름은 4개의 간선으로 구성됩니다. 다음과 같이 4개의 지름 경로가 있습니다:
        *   노드 0에서 노드 4로 가는 경로
        *   노드 0에서 노드 5로 가는 경로
        *   노드 6에서 노드 4로 가는 경로
        *   노드 6에서 노드 5로 가는 경로
    *   최소 하나의 지름 경로에서 끝점이 되는 노드 0, 4, 5, 6이 특별한 노드입니다.

**예제 3:**

*   **입력:** `n = 2`, `edges = [[0,1]]`
*   **출력:** `"11"`
*   **설명:**
    *   이 트리의 지름은 1개의 간선으로 구성됩니다.
    *   유일한 지름 경로는 노드 0에서 노드 1로 가는 경로입니다.
    *   이 경로의 끝점은 노드 0과 1이므로, 이들은 특별한 노드입니다.

---

**제약 조건:**

*   $2 \le n \le 10^5$
*   `edges.length == n - 1`
*   `edges[i] = [ai, bi]`
*   $0 \le ai, bi < n$
*   입력은 `edges`가 유효한 트리를 나타내도록 생성됩니다.
*/
