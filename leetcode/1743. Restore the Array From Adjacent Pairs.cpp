class Solution 
{
public:
    vector<int> restoreArray(const vector<vector<int>>& adjacentPairs) const
    {
        const int pairCount = adjacentPairs.size();
        const int n = pairCount + 1; // 복원할 배열 길이 n
        unordered_map<int, vector<int>> adj;
        adj.reserve(pairCount * 2);

        assert(pairCount >= MIN_PAIRS && pairCount <= MAX_PAIRS);
        assert(n >= MIN_N && n <= MAX_N);

        for (const auto& pr : adjacentPairs) 
        {
            const int u = pr[0];
            const int v = pr[1];
            assert(pr.size() == PAIR_LEN);
            assert(u >= MIN_VAL && u <= MAX_VAL);
            assert(v >= MIN_VAL && v <= MAX_VAL);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int start = 0; // 차수가 1인 시작점 찾기
        for (const auto& [node, neighbors] : adj) 
        {
            if (neighbors.size() == 1) 
            {
                start = node;
                break;
            }
        }
        
        vector<int> result(n);
        result[0] = start;
        result[1] = adj[start][0];
        for (int i = 2; i < n; ++i)   // 나머지 원소들 복원
        {
            const int prev = result[i - 2];
            const int cur  = result[i - 1];
            const auto& neighbors = adj.at(cur);
            result[i] = (neighbors[0] == prev ? neighbors[1] : neighbors[0]); // 두 이웃 중 prev가 아닌 쪽이 다음
        }
        
        return result;
    }

private:
    enum 
    {
        MIN_N        = 2,
        MAX_N        = 100000,
        MIN_PAIRS    = 1,         // adjacentPairs.length >= 1
        MAX_PAIRS    = 100000 - 1, // n-1 <= 10^5 -1
        PAIR_LEN     = 2,
        MIN_VAL      = -100000,
        MAX_VAL      = 100000
    };
};



/*

**1743. 인접한 쌍으로 배열 복원하기**

**난이도:** 중간

**문제 설명:**
원소들이 모두 서로 다른 $n$개의 정수로 이루어진 배열 **nums**가 있었으나, 그 배열을 잊어버렸습니다. 다만, **nums**에 인접한 두 원소들을 쌍으로 한 **adjacentPairs**만 기억하고 있습니다.

$n-1$개의 쌍이 담긴 2차원 정수 배열 **adjacentPairs**가 주어지는데,
각 \*\*adjacentPairs$i$ = \[u\_i, v\_i]\*\*는 $u_i$와 $v_i$가 **nums**에서 서로 인접해 있었다는 뜻입니다.
인접 쌍 $[\,\text{nums}[i], \;\text{nums}[i+1]\,]$는 **adjacentPairs** 안에 $[\,\text{nums}[i],\;\text{nums}[i+1]\,]$ 또는 $[\,\text{nums}[i+1],\;\text{nums}[i]\,]$ 형태로 반드시 포함되어 있습니다. 순서는 뒤죽박죽 섞여 있을 수 있습니다.

이 정보만으로 원래 배열 **nums**를 복원하여 반환하세요.
가능한 해답이 여러 가지라면 그중 아무 것을 반환해도 됩니다.

---

**예제 1:**

```
Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
```

*설명:*
원래 배열 `[1,2,3,4]`는 인접 쌍으로

* `[1,2]`, `[2,3]`, `[3,4]`를 가지며,
* 입력 쌍 `[2,1]`, `[3,2]`, `[3,4]`는 순서가 뒤집혀 있거나 섞여 있지만 모두 포함되어 있습니다.

---

**예제 2:**

```
Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
```

*설명:*
음수도 나올 수 있습니다.
또 다른 valid한 해답으로 `[-3,1,4,-2]`도 가능합니다.

---

**예제 3:**

```
Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]
```

---

**제약 조건:**

* $\text{nums.length} = n$
* $\text{adjacentPairs.length} = n - 1$
* $\text{adjacentPairs}[i].length = 2$
* $2 \le n \le 10^5$
* $-10^5 \le \text{nums}[i],\,u_i,\,v_i \le 10^5$
* 항상 주어진 **adjacentPairs**에 대응하는 어떤 **nums**가 존재함이 보장됩니다.

*/

// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/
