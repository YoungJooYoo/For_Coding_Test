class Solution 
{
public:
    vector<int> minCosts(const vector<int>& cost) const 
    {
        assert(MIN_LENGTH <= cost.size() && cost.size() <= MAX_LENGTH);

        vector<int> result;
        int minCost = cost[0];

        for (const auto elem : cost)
        {
            assert(MIN_COST <= elem && elem <= MAX_COST);
            minCost = min(minCost, elem);
            result.push_back(minCost); 
        }

        assert(result.size() == cost.size());
        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_COST = 1,
        MAX_COST = 100
    };
};

// https://leetcode.com/problems/minimum-cost-to-reach-every-position/

/*
다음은 문제의 국문 번역입니다.

---

**3502. 모든 위치에 도달하기 위한 최소 비용**

**난이도:** 쉬움

**문제 설명:**  
크기가 n인 정수 배열 **cost**가 주어집니다. 현재, 당신은 n+1명의 사람들이 줄을 서 있는 상황에서, 줄의 맨 끝인 인덱스 n에 위치해 있습니다 (사람들의 번호는 0부터 n까지 부여됩니다).

당신은 줄에서 앞으로 이동하고 싶지만, 당신보다 앞에 있는 각 사람은 자리를 교환하기 위해 특정 비용을 청구합니다. 사람 i와 자리를 교환하는 비용은 **cost[i]**로 주어집니다.

자리를 교환하는 규칙은 다음과 같습니다:
- 만약 교환하려는 사람이 당신보다 앞에 있다면, 그 사람과 자리를 교환하기 위해 **cost[i]**만큼의 비용을 지불해야 합니다.
- 만약 교환하려는 사람이 당신보다 뒤에 있다면, 그 사람과의 자리 교환은 무료입니다.

길이가 n인 배열 **answer**를 반환해야 하며, 여기서 **answer[i]**는 줄의 i번 위치에 도달하기 위한 최소 총 비용을 나타냅니다.

---

**예제 1:**

- **입력:** cost = [5, 3, 4, 1, 3, 2]
- **출력:** [5, 3, 3, 1, 1, 1]
- **설명:**
  - i = 0: 사람 0과 자리를 교환하면 비용이 5 발생합니다.
  - i = 1: 사람 1과 자리를 교환하면 비용이 3 발생합니다.
  - i = 2: 사람 1과 교환하여 비용 3를 지불한 후, 사람 2와 무료로 교환합니다.
  - i = 3: 사람 3과 자리를 교환하면 비용이 1 발생합니다.
  - i = 4: 사람 3과 교환하여 비용 1을 지불한 후, 사람 4와 무료로 교환합니다.
  - i = 5: 사람 3과 교환하여 비용 1을 지불한 후, 사람 5와 무료로 교환합니다.

---

**예제 2:**

- **입력:** cost = [1, 2, 4, 6, 7]
- **출력:** [1, 1, 1, 1, 1]
- **설명:**
  - 사람 0과 자리를 교환하면 비용이 1 발생하고, 그 후에는 어떤 위치로든 무료로 이동할 수 있습니다.

---

**제약 조건:**

- 1 <= n == cost.length <= 100
- 1 <= cost[i] <= 100

---

**힌트:**

1. 한 번 비용이 낮은 위치로 교환하면, 그 이후의 위치들은 모두 무료로 이동할 수 있습니다.
2. 최소 prefix 배열(min prefix array)을 사용하여 문제를 해결할 수 있습니다.

---
*/
