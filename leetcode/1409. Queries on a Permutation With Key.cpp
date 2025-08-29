#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution 
{
public:
    vector<int> processQueries(const vector<int>& queries, const int m) const
    {
        assert(MIN_M <= m && m <= MAX_M);

        const size_t queryCount = queries.size();
        vector<int> cards;
        vector<int> results;

        assert(MIN_QUERY_COUNT <= queryCount && queryCount <= MAX_QUERY_COUNT);
        for (size_t i = 0; i < static_cast<size_t>(m); ++i)
        {
            cards.push_back(static_cast<int>(i + 1));
        }
        assert(cards.size() == m);

        for (const int query : queries)
        {
            assert(MIN_VALUE <= query && query <= m);
            const auto it = find(cards.begin(), cards.end(), query);
            assert(it != cards.end()); // 반드시 존재해야 함
            const int foundIndex = static_cast<int>(distance(cards.begin(), it));
            results.push_back(foundIndex);
            cards.erase(it); // 해당 카드를 맨 앞으로 이동
            cards.insert(cards.begin(), query);
            assert(foundIndex >= 0);
        }

        assert(results.size() == queries.size());
        return results;
    }

private:
    enum
    {
        MIN_M = 1,
        MAX_M = 1000,           // 문제 조건상 m 제한 (LeetCode: 최대 1000)
        MIN_QUERY_COUNT = 1,
        MAX_QUERY_COUNT = 1000, // queries 길이 제한
        MIN_VALUE = 1           // queries[i]는 최소 1
    };
};

// https://leetcode.com/problems/queries-on-a-permutation-with-key/description/

/*
1409. 키를 사용한 순열에 대한 쿼리
**난이도:** 중간
**주제**
**회사**
**힌트**

**문제 설명:**

양의 정수로 이루어진 배열 `queries`가 1부터 `m`까지의 수를 포함하고 있습니다. 당신은 다음의 규칙에 따라 모든 `queries[i]` (i = 0부터 i = queries.length - 1까지)를 처리해야 합니다:

1. 처음에, 순열 `P = [1, 2, 3, ..., m]`이 주어집니다.
2. 현재의 `i`에 대해, 순열 `P`에서 `queries[i]`의 위치(0부터 시작하는 인덱스)를 찾은 다음, 이를 순열 `P`의 맨 앞으로 이동시킵니다. 이때, `queries[i]`의 위치가 해당 쿼리의 결과가 됩니다.

주어진 쿼리에 대한 결과를 담은 배열을 반환하세요.

---

**예제 1:**

```
입력: queries = [3,1,2,1], m = 5
출력: [2,1,2,1]
```

**설명:**

쿼리는 다음과 같이 처리됩니다:

- i=0: queries[0]=3, P=[1,2,3,4,5], 3의 위치는 2, 3을 P의 맨 앞으로 이동하여 P=[3,1,2,4,5].
- i=1: queries[1]=1, P=[3,1,2,4,5], 1의 위치는 1, 1을 P의 맨 앞으로 이동하여 P=[1,3,2,4,5].
- i=2: queries[2]=2, P=[1,3,2,4,5], 2의 위치는 2, 2를 P의 맨 앞으로 이동하여 P=[2,1,3,4,5].
- i=3: queries[3]=1, P=[2,1,3,4,5], 1의 위치는 1, 1을 P의 맨 앞으로 이동하여 P=[1,2,3,4,5].

따라서 결과 배열은 [2,1,2,1]입니다.

---

**예제 2:**

```
입력: queries = [4,1,2,2], m = 4
출력: [3,1,2,0]
```

**예제 3:**

```
입력: queries = [7,5,5,8,3], m = 8
출력: [6,5,0,7,5]
```

---

**제약 사항:**

- 1 <= m <= 10^3
- 1 <= queries.length <= m
- 1 <= queries[i] <= m
*/
