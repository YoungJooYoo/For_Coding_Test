class Solution {
public:
    int findCheapestPrice(const int n, const vector<vector<int>>& flights, const int src, const int dst, const int k) 
    {
        // 그래프 구성
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // 비용, 현재 도시, 남은 경유지 수
        queue<vector<int>> q;
        q.push({0, src, k + 1});

        // 최소 비용을 저장할 벡터, 초기값은 무한대
        vector<int> minCost(n, numeric_limits<int>::max());
        minCost[src] = 0;

        while (!q.empty()) {
            const auto current = q.front(); q.pop();
            const int cost = current[0];
            const int city = current[1];
            const int stops = current[2];

            if (stops > 0) {
                for (const auto& next : graph[city]) {
                    const int nextCity = next.first;
                    const int nextCost = next.second;
                    // 다음 도시로 가는 새로운 비용이 현재 저장된 비용보다 작으면 업데이트
                    if (cost + nextCost < minCost[nextCity]) {
                        minCost[nextCity] = cost + nextCost;
                        q.push({cost + nextCost, nextCity, stops - 1});
                    }
                }
            }
        }

        return minCost[dst] == numeric_limits<int>::max() ? -1 : minCost[dst];
    }
};

// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

/*

### 한국어 번역

n개의 도시가 일부 수의 항공편으로 연결되어 있습니다. flights 배열이 주어지는데, flights[i] = [fromi, toi, pricei]는 도시 fromi에서 도시 toi까지 비용이 pricei인 항공편이 있다는 것을 나타냅니다.

또한 세 개의 정수 src, dst, k가 주어지며, 최대 k번의 정류장을 거쳐서 src에서 dst까지 가는 가장 저렴한 가격을 반환합니다. 그러한 경로가 없다면 -1을 반환합니다.

### 요약

주어진 도시 간의 항공편 정보를 바탕으로, 시작 도시(src)에서 목적지 도시(dst)까지 최대 k번의 경유지를 거쳐 갈 때의 최소 비용을 찾는 문제입니다. 가능한 경로가 없을 경우 -1을 반환합니다.

### 문제 풀이 방향

이 문제는 그래프 탐색 문제로 볼 수 있으며, 다음과 같은 방법으로 접근할 수 있습니다:

1. **그래프 구성**: 도시들 사이의 항공편 정보를 바탕으로 그래프를 구성합니다. 각 노드는 도시를 나타내며, 간선은 항공편과 그 비용을 나타냅니다.

2. **BFS(너비 우선 탐색) 또는 다익스트라 알고리즘 사용**: 최소 비용 경로를 찾기 위해 BFS 또는 다익스트라 알고리즘을 사용할 수 있습니다. BFS를 사용할 경우, 각 단계에서 k번의 경유지를 고려하여 탐색을 진행합니다. 다익스트라 알고리즘을 사용할 경우, 최소 비용 경로를 효율적으로 찾을 수 있습니다.

3. **경유지 제한 고려**: 탐색 과정에서 경유지의 수가 k를 초과하지 않도록 주의해야 합니다. 각 탐색 단계에서 현재 경로의 경유지 수를 추적하고, k를 초과하는 경로는 고려하지 않습니다.

4. **최소 비용 계산**: 탐색을 통해 src에서 dst까지의 경로 중 경유지 수가 k 이하인 경로들의 비용을 계산하고, 그 중 최소 비용을 찾습니다.

5. **결과 반환**: 최소 비용 경로를 찾았다면 해당 비용을 반환하고, 가능한 경로가 없다면 -1을 반환합니다.

이 문제는 다양한 그래프 알고리즘을 적용할 수 있는 좋은 예시이며, 특히 다익스트라 알고리즘을 사용하면 효율적으로 최소 비용 경로를 찾을 수 있습니다.
*/
