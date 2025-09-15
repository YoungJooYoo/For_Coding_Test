class Solution
{
public:
    vector<int> getMaximumXor(vector<int>& nums, const int maximumBit) const
    {
        const size_t n = nums.size();
        const int upper = (1 << maximumBit); // 2^maximumBit
        const int mask = ((1 << maximumBit) - 1);
        int xorSum = getTotalXORSum(nums);
        vector<int> answer;

        assert(n >= static_cast<size_t>(MIN_N) && n <= static_cast<size_t>(MAX_N));
        assert(maximumBit >= MIN_MAXBIT && maximumBit <= MAX_MAXBIT);
    
        for (size_t i = 0; i < n; ++i) // i번째 질의의 정답을 앞에서부터 push
        {
            //assert(nums[i - 1] <= nums[i]);
            assert(nums[i] >= 0 && nums[i] < upper);
            const int k = (mask ^ xorSum);
            answer.push_back(k);
            const size_t idx_from_end = (n - 1 - i); // 배열의 "마지막 원소"를 제거한다고 가정 → XOR에서 빼기 == 다시 XOR
            xorSum ^= nums[idx_from_end];
        }

        return answer;
    }

private:
    static int getTotalXORSum(const vector<int>& nums)
    {
        int result = 0;

        for (const int num : nums)
        {
            result ^= num;
        }

        return result;
    }

    enum
    {
        MIN_N = 1,
        MAX_N = 100000,
        MIN_MAXBIT = 1,
        MAX_MAXBIT = 20
        // 각 nums[i]는 0 <= nums[i] < 2^maximumBit
    };
};

// https://leetcode.com/problems/maximum-xor-for-each-query/description/

/*

=
---

## 1829. 각 쿼리에 대한 최대 XOR

**난이도: 중간**

---

정렬된 정수 배열 `nums` (길이 `n`)과 정수 `maximumBit`이 주어집니다.
당신은 총 `n`번의 쿼리를 다음과 같이 수행해야 합니다:

* `0 ≤ k < 2^maximumBit` 인 **비음수 정수 k**를 찾아서,

  ```
  nums[0] XOR nums[1] XOR ... XOR nums[n-1] XOR k
  ```

  의 결과가 최대가 되도록 합니다.
  여기서 `k`가 해당 쿼리의 답이 됩니다.

* 그런 뒤, 배열 `nums`에서 **마지막 원소를 제거**합니다.

모든 쿼리에 대한 답을 배열 `answer`로 반환하세요.
즉, `answer[i]`는 `i`번째 쿼리의 답입니다.

---

### 예시 1

```
입력: nums = [0,1,1,3], maximumBit = 2
출력: [0,3,2,3]
```

**설명**

* 1번째 쿼리: nums = \[0,1,1,3] → XOR 결과는 3, 따라서 k = 0.
* 2번째 쿼리: nums = \[0,1,1] → XOR 결과는 0, 따라서 k = 3.
* 3번째 쿼리: nums = \[0,1] → XOR 결과는 1, 따라서 k = 2.
* 4번째 쿼리: nums = \[0] → XOR 결과는 0, 따라서 k = 3.

---

### 예시 2

```
입력: nums = [2,3,4,7], maximumBit = 3
출력: [5,2,6,5]
```

**설명**

* 1번째 쿼리: 전체 XOR = 2 ⊕ 3 ⊕ 4 ⊕ 7 = 2.
  최대 k = 5 → 결과는 7.
* 2번째 쿼리: \[2,3,4] → XOR = 5 → k = 2.
* 3번째 쿼리: \[2,3] → XOR = 1 → k = 6.
* 4번째 쿼리: \[2] → XOR = 2 → k = 5.

---

### 예시 3

```
입력: nums = [0,1,2,2,5,7], maximumBit = 3
출력: [4,3,6,4,6,7]
```

---

### 제약조건

* 1 ≤ nums.length ≤ 10⁵
* 0 ≤ nums\[i] < 2^maximumBit
* 1 ≤ maximumBit ≤ 20

---

=
*/
