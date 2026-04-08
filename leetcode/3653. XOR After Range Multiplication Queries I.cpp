class Solution
{
public:
    int xorAfterQueries(vector<int>& nums, const vector<vector<int>>& queries) const
    {
        assert(MIN_SIZE <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_SIZE);
        assert(MIN_SIZE <= static_cast<int>(queries.size()) && static_cast<int>(queries.size()) <= MAX_SIZE);

        for (const auto& query : queries)
        {
            const int li = query[LI];
            const int ri = query[RI];
            const int ki = query[KI];
            const int vi = query[VI];
            for (int idx = li; idx <= ri; idx += ki)
            {
                nums[idx] = static_cast<int>((static_cast<long long>(nums[idx]) * vi) % MOD);
            }
            assert(static_cast<int>(query.size()) == QUERY_SIZE);
            assert(0 <= li && li <= ri && ri < static_cast<int>(nums.size()));
            assert(MIN_KI <= ki);
            assert(MIN_VI <= vi);
        }

        int xorResult = 0;
        for (const int num : nums)
        {
            xorResult ^= num;
        }

        assert(xorResult >= 0);
        return xorResult;
    }

private:
    enum
    {
        MIN_SIZE   = 1,
        MAX_SIZE   = 100000,
        MIN_KI     = 1,
        MIN_VI     = 1,
        MOD        = 1000000007,  // 10^9 + 7
        QUERY_SIZE = 4,

        // query 인덱스
        LI = 0,
        RI = 1,
        KI = 2,
        VI = 3,
    };
};

/*
## 문제 번역

**3653. 범위 곱셈 쿼리 후 XOR**

길이가 `n`인 정수 배열 `nums`와 크기가 `q`인 2D 정수 배열 `queries`가 주어집니다.
`queries[i] = [li, ri, ki, vi]` 형태입니다.

각 쿼리마다 아래 연산을 **순서대로** 수행해야 합니다:

- `idx = li` 로 설정
- `idx <= ri` 인 동안 반복:
  - `nums[idx] = (nums[idx] * vi) % (10^9 + 7)` 로 업데이트
  - `idx += ki` 로 증가

모든 쿼리를 처리한 후 `nums`의 **모든 원소를 비트 XOR** 한 결과를 반환하세요.

---

**예시 1**
- 입력: `nums = [1,1,1]`, `queries = [[0,2,1,4]]`
- 출력: `4`
- 설명:
  - 쿼리 `[0,2,1,4]`: 인덱스 0~2의 모든 원소에 4를 곱함
  - `[1,1,1]` → `[4,4,4]`
  - XOR: `4 ^ 4 ^ 4 = 4`

**예시 2**
- 입력: `nums = [2,3,1,5,4]`, `queries = [[1,4,2,3],[0,2,1,2]]`
- 출력: `31`
- 설명:
  - 쿼리 `[1,4,2,3]`: 인덱스 1, 3에 3을 곱함 → `[2,9,1,15,4]`
  - 쿼리 `[0,2,1,2]`: 인덱스 0, 1, 2에 2를 곱함 → `[4,18,2,15,4]`
  - XOR: `4 ^ 18 ^ 2 ^ 15 ^ 4 = 31`

---

**제약 조건** (원문에 명시되지 않았으나 Medium 난이도 기준 일반적으로):
- `1 <= n <= 10^5`
- `1 <= q <= 10^5`
- `0 <= li <= ri < n`
- `1 <= ki, vi <= 10^9`

---

## 요약

각 쿼리마다 **시작 인덱스 `li`에서 `ki` 간격으로 `ri`까지** 원소에 `vi`를 곱하고 `10^9+7`로 나머지 연산. 전부 처리 후 **전체 XOR** 반환.

---

## 풀이 방향

1. 각 쿼리를 순서대로 처리
2. `idx = li` 부터 `ki` 씩 증가하며 `ri` 까지 순회
3. `nums[idx] = (nums[idx] * vi) % MOD` 업데이트
4. 모든 쿼리 처리 후 전체 원소 XOR 반환

```
MOD = 10^9 + 7 → enum으로 정의!
```
https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/?envType=daily-question&envId=2026-04-08

*/
