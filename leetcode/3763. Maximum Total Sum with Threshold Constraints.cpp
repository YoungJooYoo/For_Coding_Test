class Solution
{
public:
    int maxSum(const vector<int>& nums, const vector<int>& threshold) const
    {
        const int n = (int)nums.size();
        assert(n == (int)threshold.size());
        assert(n >= MIN_N && n <= MAX_N);

        if (n == 0) 
        {
            return 0;
        }

        vector<int> order(n);
        priority_queue<pair<int, int>> pq; // (nums[i], i)
        long long total = 0;
        int step = 1;
        int idx = 0;

        for (int i = 0; i < n; ++i) 
        {
            order[i] = i;
        }

        ranges::sort(order, [&](const int a, const int b) 
        {
            return threshold[a] < threshold[b];
        });

        while (true) 
        {
            while (idx < n && threshold[order[idx]] <= step) 
            {
                const int i = order[idx++];
                pq.emplace(nums[i], i);
            }

            if (pq.empty()) 
            {
                break;
            }

            total += pq.top().first;
            pq.pop();
            ++step;
        }

        return (int)total;
    }

private:
    enum 
    {
        MIN_N = 0,
        MAX_N = 100000
    };
};

// https://leetcode.com/problems/maximum-total-sum-with-threshold-constraints/description/

/*
### 3763. 임계값 제약을 가진 최대 총합

두 정수 배열 `nums`와 `threshold`가 주어집니다. 두 배열의 길이는 `n`입니다.

처음에 `step = 1`로 시작하여 다음 과정을 반복합니다:

- 아직 사용하지 않은 인덱스 `i` 중에서 `threshold[i] <= step`인 것을 하나 선택합니다.
- 만약 그러한 인덱스가 없다면 과정이 종료됩니다.
- 선택한 인덱스 `i`에 대해 `nums[i]`를 누적 합에 더합니다.
- 인덱스 `i`를 사용된 것으로 표시하고, `step`을 1 증가시킵니다.

적절하게 인덱스를 선택하여 얻을 수 있는 누적 합의 최대값을 반환하세요.

---

예시 1:

입력: nums = [1,10,4,2,1,6], threshold = [5,1,5,5,2,2]  
출력: 17

설명:
- step = 1에서 threshold[1] = 1 이므로 i = 1 선택 → 총합 = 10
- step = 2에서 threshold[4] = 2 이므로 i = 4 선택 → 총합 = 11
- step = 3에서 threshold[5] = 2 ≤ 3 이므로 i = 5 선택 → 총합 = 17
- step = 4에서는 남은 인덱스 0,2,3의 threshold가 모두 4보다 크므로 종료

예시 2:

입력: nums = [4,1,5,2,3], threshold = [3,3,2,3,3]  
출력: 0

설명:
- step = 1에서 threshold[i] ≤ 1인 인덱스가 없어 즉시 종료 → 총합 = 0

예시 3:

입력: nums = [2,6,10,13], threshold = [2,1,1,1]  
출력: 31

설명:
- step = 1에서 i = 3 선택 (threshold[3] = 1) → 총합 = 13
- step = 2에서 i = 2 선택 → 총합 = 23
- step = 3에서 i = 1 선택 → 총합 = 29
- step = 4에서 i = 0 선택 → 총합 = 31
- 모든 인덱스를 선택했으므로 종료

---

제약 조건:

- `n == nums.length == threshold.length`
- `1 <= n <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= threshold[i] <= n`
*/
