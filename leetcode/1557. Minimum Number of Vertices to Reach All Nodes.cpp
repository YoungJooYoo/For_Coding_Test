class Solution
{
public:
    vector<int> findSmallestSetOfVertices(const int n, const vector<vector<int>>& edges) const
    {
        assert(n >= MIN_N && n <= MAX_N);
        assert(edges.size() >= MIN_M && edges.size() <= MAX_M);

        vector<int> indegree(n, 0);
        vector<int> answer;

        for (const vector<int>& edge : edges)
        {
            const int from = edge[0];
            const int to = edge[1];
            ++indegree[to];
            assert(edge.size() == 2);
            assert(from >= 0 && from < n);
            assert(to >= 0 && to < n);
        }

        for (int v = 0; v < n; ++v)
        {
            if (indegree[v] == 0)
            {
                answer.push_back(v);
            }
        }

        assert(answer.size() <= n);
        return answer;
    }

private:
    enum
    {
        MIN_N = 2,
        MAX_N = 100000,
        MIN_M = 1,
        MAX_M = 100000 // 문제의 상한(min(1e5, n*(n-1)/2)) 중 1e5만 방어적으로 확인
    };
};

// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

/*
1557. 모든 노드에 도달하기 위한 최소 정점 집합

(Minimum Number of Vertices to Reach All Nodes)

유향 비순환 그래프(DAG)가 주어집니다.

정점은 0부터 n-1까지 번호가 매겨져 있습니다.

배열 edges가 주어지며, edges[i] = [fromᵢ, toᵢ]는 정점 fromᵢ에서 정점 toᵢ로 향하는 유향 간선을 의미합니다.

이때, 그래프 내 모든 노드에 도달할 수 있는 최소한의 시작 정점 집합을 구하세요.

유일한 해답이 존재하는 것이 보장됩니다.

정점 집합의 반환 순서는 자유롭습니다.

예시 1

입력:

n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]


출력:

[0,3]


설명:

정점 0에서 시작하면 [0,1,2,5]에 도달할 수 있습니다.

정점 3에서 시작하면 [3,4,2,5]에 도달할 수 있습니다.

따라서 전체 그래프의 모든 노드에 도달하려면 최소 집합은 [0,3]입니다.

예시 2

입력:

n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]


출력:

[0,2,3]


설명:

정점 0, 2, 3은 다른 정점으로부터 들어오는 간선이 없으므로, 반드시 시작 정점에 포함해야 합니다.

이 정점들에서 출발하면 1과 4에도 도달 가능합니다.

제약 조건

2 <= n <= 10^5

1 <= edges.length <= min(10^5, n * (n - 1) / 2)

edges[i].length == 2

0 <= fromᵢ, toᵢ < n

모든 간선 쌍 (fromᵢ, toᵢ)는 서로 다릅니다.
*/
