
class Solution 
{
public:
    vector<int> findOrder(const int numCourses, const vector<vector<int>>& prerequisites) const
    {
        assert(MIN_COURSES <= numCourses && numCourses <= MAX_COURSES);
        assert(prerequisites.size() <= static_cast<size_t>(numCourses) * (numCourses - 1));
     
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> q;
        vector<int> order;

        for (const auto& pre : prerequisites) // prerequisites[i] = [a, b] : b -> a
        {
            assert(pre.size() == 2);
            assert(0 <= pre[0] && pre[0] < numCourses);
            assert(0 <= pre[1] && pre[1] < numCourses);
            assert(pre[0] != pre[1]);
            const int course = pre[0];
            const int preCourse = pre[1];
            graph[preCourse].push_back(course);
            ++inDegree[course];
        }
        
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            const int current = q.front();
            q.pop();
            order.push_back(current);

            for (const int next : graph[current])
            {
                --inDegree[next];
                if (inDegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        
        if (order.size() != static_cast<size_t>(numCourses))     // 사이클이 있으면 전체 코스를 모두 넣을 수 없음
        {
            return {};
        }

        return order;
    }

private:
    enum
    {
        MIN_COURSES = 1,
        MAX_COURSES = 2000
    };
};

// https://leetcode.com/problems/course-schedule-ii/description/?envType=company&envId=qualcomm&favoriteSlug=qualcomm-all

/*
**문제 210. 코스 수강 순서 II**
중간 난이도

---

총 `numCourses`개의 코스(0번부터 numCourses-1번까지 번호 매김)가 있습니다.
각 코스는 선행되어야 하는 코스가 있을 수 있습니다.
2차원 배열 `prerequisites`가 주어지며,
`prerequisites[i] = [ai, bi]`는 **코스 ai를 들으려면, 코스 bi를 먼저 수강해야 한다**는 의미입니다.

예를 들어, `[0, 1]`이 있다면, 0번 코스를 들으려면 1번 코스를 먼저 들어야 합니다.

모든 코스를 수강할 수 있도록 코스 수강 순서를 반환하세요.
가능한 순서가 여러 개라면 아무 순서나 반환해도 됩니다.
만약 모든 코스를 수강하는 것이 불가능하다면(순환 구조가 있는 경우), **빈 배열**을 반환하세요.

---

## 예시 1

```
입력: numCourses = 2, prerequisites = [[1,0]]
출력: [0,1]
```

**설명:**
두 개의 코스가 있습니다. 1번 코스를 들으려면 0번을 먼저 들어야 하므로, 올바른 순서는 \[0,1]입니다.

---

## 예시 2

```
입력: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
출력: [0,2,1,3]
```

**설명:**
총 4개의 코스가 있습니다.
3번 코스를 듣기 위해선 1번, 2번 모두를 이수해야 하고, 1번과 2번 모두 0번을 선행 이수해야 합니다.
따라서 가능한 순서 중 하나는 \[0,1,2,3], 또는 \[0,2,1,3] 등입니다.

---

## 예시 3

```
입력: numCourses = 1, prerequisites = []
출력: [0]
```

**설명:**
코스가 1개이므로 바로 0번 코스를 듣기만 하면 됩니다.

---

## 제약사항

* 1 ≤ numCourses ≤ 2000
* 0 ≤ prerequisites.length ≤ numCourses × (numCourses - 1)
* prerequisites\[i].length == 2
* 0 ≤ ai, bi < numCourses
* ai != bi
* 모든 \[ai, bi] 쌍은 서로 다릅니다.

---

**힌트:**

* 이 문제는 **유향 그래프에서 위상 정렬(topological sort)** 을 찾는 것과 같습니다.
* 만약 순환(cycle)이 있으면, 모든 코스를 수강하는 것이 불가능합니다.
* 위상 정렬은 DFS, BFS(진입 차수 이용) 등으로 구현할 수 있습니다.

*/
