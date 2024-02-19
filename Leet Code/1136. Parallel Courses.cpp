#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumSemesters(const int n, const vector<vector<int>>& relations) 
    {
        vector<int> inDegree(n + 1, 0); // 각 노드의 진입 차수를 저장할 벡터
        vector<vector<int>> graph(n + 1); // 그래프의 인접 리스트 표현
        for (const auto& r : relations) {
            graph[r[0]].push_back(r[1]); // 방향 그래프 구성
            ++inDegree[r[1]]; // 진입 차수 업데이트, 간선수 업데이트
        }

        queue<int> q; // 진입 차수가 0인 노드들을 저장할 큐, 화살표가 나가기만 하는 노드들
        for (int i = 1; i <= n; ++i) {
            if (inDegree[i] == 0) q.push(i); // 초기 진입 차수가 0인 노드를 큐에 추가
        }

        int semester = 0; // 학기 수
        int studied = 0; // 수강한 과목 수
        while (!q.empty()) {
            const int size = q.size(); // 현재 학기에 수강할 수 있는 과목 수
            for (int i = 0; i < size; ++i) {
                const int course = q.front(); q.pop();
                ++studied; // 수강한 과목 수 증가
                for (const int nextCourse : graph[course]) {
                    --inDegree[nextCourse]; // 해당 과목을 선수 과목으로 하는 과목의 진입 차수 감소
                    if (inDegree[nextCourse] == 0) q.push(nextCourse); // 새로 진입 차수가 0이 된 과목을 큐에 추가
                }
            }
            ++semester; // 다음 학기로
        }

        return studied == n ? semester : -1; // 모든 과목을 수강했다면 학기 수 반환, 아니면 -1 반환
    }
};

// https://leetcode.com/problems/parallel-courses/

/*

### 문제 번역

1136번: 병렬 과정
난이도: 중간

주어진 정수 `n`은 1부터 `n`까지 라벨링된 `n`개의 과목이 있음을 나타냅니다. 배열 `relations`이 주어지는데, `relations[i] = [prevCoursei, nextCoursei]`는 과목 `prevCoursei`가 과목 `nextCoursei`의 선수 과목임을 나타냅니다. 즉, 과목 `prevCoursei`는 과목 `nextCoursei`를 수강하기 전에 수강해야 합니다.

한 학기에, 이전 학기에 모든 선수 과목을 수강했다면 원하는 만큼 많은 과목을 수강할 수 있습니다.

모든 과목을 수강하기 위해 필요한 최소 학기 수를 반환합니다. 모든 과목을 수강할 방법이 없다면 -1을 반환합니다.

### 문제 요약

- `n`개의 과목과 일부 과목 간의 선수 관계가 주어집니다.
- 한 학기에 선수 과목을 모두 이수한 경우에만 해당 과목을 수강할 수 있습니다.
- 모든 과목을 수강하기 위한 최소 학기 수를 구해야 합니다.
- 모든 과목을 수강할 수 없는 경우 -1을 반환합니다.

### 문제 풀이 방향

이 문제는 그래프 이론을 사용하여 해결할 수 있으며, 특히 위상 정렬(Topological Sorting) 알고리즘을 적용할 수 있습니다. 위상 정렬은 방향 그래프의 모든 노드를 "선행 노드가 후행 노드보다 먼저 오도록" 나열하는 것입니다. 이 경우, 과목 간의 선수 관계가 방향 그래프를 형성하며, 이 그래프를 위상 정렬하여 각 학기에 어떤 과목을 수강할 수 있는지 결정할 수 있습니다.

1. **그래프 초기화**: `n`개의 노드를 가진 그래프를 초기화하고, `relations` 배열을 사용하여 방향성을 가진 간선을 추가합니다.
2. **진입 차수 계산**: 각 노드의 진입 차수(해당 노드로 들어오는 간선의 수)를 계산합니다.
3. **위상 정렬 실행**:
   - 진입 차수가 0인 모든 노드를 찾아 큐에 추가합니다. 이 노드들은 선수 과목이 없는 과목을 나타냅니다.
   - 큐가 비어있지 않은 동안, 큐에서 노드를 하나씩 꺼내 해당 노드에서 나가는 간선을 제거하고, 각 대상 노드의 진입 차수를 감소시킵니다. 진입 차수가 0이 된 노드를 큐에 추가합니다.
   - 각 단계에서 큐에 추가된 노드의 수를 카운트하여 학기 수를 계산합니다.
4. **모든 과목을 수강할 수 있는지 확인**: 위상 정렬을 통해 모든 노드를 방문했다면, 모든 과목을 수강할 수 있는 것입니다. 방문하지 못한 노드가 있다면, -1을 반환합니다.

위상 정렬을 통해 각 학기마다 수강할 수 있는 과목의 집합을 결정하고, 모든 과목을 수강하기 위해 필요한 최소 학기 수를 계산할 수 있습니다.
*/
