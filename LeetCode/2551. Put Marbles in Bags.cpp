class Solution 
{
public:
    long long putMarbles(const vector<int>& weights, const int k) const 
    {    
        if (k == 1) 
        {
            return 0LL; // k == 1인 경우, 분할이 없으므로 차이는 0입니다.
        }

        const int n = weights.size();
        vector<long long> gapCosts;

        assert(k >= MIN_BAGS && k <= n);
        assert(n >= MIN_LENGTH && n <= MAX_LENGTH);

        for (int i = 0; i < n - 1; ++i) 
        {
            assert(weights[i] >= MIN_WEIGHT && weights[i] <= MAX_WEIGHT);
            assert(weights[i + 1] >= MIN_WEIGHT && weights[i + 1] <= MAX_WEIGHT);
            const long long gap = static_cast<long long>(weights[i]) + weights[i + 1];
            gapCosts.push_back(gap);
        }
        
        sort(gapCosts.begin(), gapCosts.end()); // gapCosts를 정렬합니다.
        
        const int numSplits = k - 1;
        long long extraCostMin = 0;
        long long extraCostMax = 0;

        for (int i = 0; i < numSplits; ++i) 
        {
            extraCostMin += gapCosts[i];
            extraCostMax += gapCosts[gapCosts.size() - 1 - i];
        }

        assert(extraCostMax - extraCostMin >= 0);
        return extraCostMax - extraCostMin;
    }

private:
    enum {
        MIN_BAGS = 1,
        MIN_LENGTH = 1,       // 최소 1개의 구슬 (문제 조건에 따라)
        MAX_LENGTH = 100000,
        MIN_WEIGHT = 1,
        MAX_WEIGHT = 1000000000
    };
};

// https://leetcode.com/problems/put-marbles-in-bags/?envType=daily-question&envId=2025-03-31

/*


**2551. 구슬을 가방에 넣기**

**난이도:** 어려움

**문제 설명:**  
당신은 k개의 가방을 가지고 있습니다. 0-indexed 정수 배열 **weights**가 주어지며, 여기서 **weights[i]**는 i번째 구슬의 무게를 나타냅니다. 또한 정수 **k**가 주어집니다.

구슬들을 아래 규칙에 따라 k개의 가방에 나누어 담으세요:

- 어떤 가방도 비어 있으면 안 됩니다.
- 만약 i번째 구슬과 j번째 구슬이 같은 가방에 있다면, i번째와 j번째 사이의 모든 구슬도 반드시 그 가방에 있어야 합니다.
- 만약 한 가방이 인덱스 i부터 j까지의 모든 구슬을 포함한다면, 그 가방의 비용은 **weights[i] + weights[j]**로 정의됩니다.

구슬들을 분배한 후의 점수는 k개의 모든 가방의 비용의 합입니다.  
여러 구슬 분배 방법 중에서, 가방들의 점수가 최대가 되는 경우와 최소가 되는 경우의 차이를 반환하세요.

---

**예제 1:**

- **입력:** weights = [1, 3, 5, 1], k = 2  
- **출력:** 4  
- **설명:**  
  - 분배 방법 중 [1], [3,5,1]인 경우:  
    - 첫 번째 가방의 비용: weights[0] + weights[0] = 1 + 1 = 2  
    - 두 번째 가방의 비용: weights[?]  
    - (설명에 따르면 [1],[3,5,1]의 총 비용은 (1+1) + (3+1) = 6)  
  - 분배 방법 중 [1,3], [5,1]인 경우:  
    - 첫 번째 가방의 비용: 1 + 3 = 4  
    - 두 번째 가방의 비용: 5 + 1 = 6  
    - 총 비용: 4 + 6 = 10  
  - 따라서, 최대 점수와 최소 점수의 차이는 10 - 6 = 4입니다.

**예제 2:**

- **입력:** weights = [1, 3], k = 2  
- **출력:** 0  
- **설명:**  
  - 가능한 유일한 분배 방법은 [1], [3]입니다.  
  - 두 가방의 비용이 같으므로 점수 차이는 0입니다.

---

**제약 조건:**

- 1 <= k <= weights.length <= 10^5  
- 1 <= weights[i] <= 10^9

---
*/
