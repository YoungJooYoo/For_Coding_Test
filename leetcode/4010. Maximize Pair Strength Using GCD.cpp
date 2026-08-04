class Solution
{
public:
    long long maxPairStrength(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        long long maxStrength = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                assert(MIN_NUM <= nums[j] && nums[j] <= MAX_NUM);
                const long long g = getGCDRecursive(nums[i], nums[j]);
                const long long strength = (nums[i] / g) * (nums[j] / g);
                maxStrength = max(maxStrength, strength);
            }
        }

        return maxStrength;
    }

private:
    enum
    {
        MIN_LENGTH = 2,
        MAX_LENGTH = 2000,
        MIN_NUM = 1,
        MAX_NUM = 100000
    };

    long long getGCDRecursive(const long long a, const long long b) const
    {
        assert(a > 0 && b >= 0);

        if (b == 0)
        {
            return a;
        }

        return getGCDRecursive(b, a % b);
    }
};
/*
https://leetcode.com/problems/maximize-pair-strength-using-gcd/
## 4010. GCD를 사용한 쌍의 강도 최대화 (Maximize Pair Strength Using GCD)

**난이도: Easy**

정수 배열 `nums`가 주어집니다.

서로 다른 두 인덱스 `i`와 `j`로 이루어진 쌍을 정확히 하나 선택하세요. 쌍의 **강도(strength)**는 다음과 같이 정의됩니다:

```
(nums[i] * nums[j]) / gcd(nums[i], nums[j])²
```

가능한 모든 쌍에 대해 강도의 **최대값**을 반환하세요.

---

**예제 1:**
```
입력: nums = [2,3,5]
출력: 15
설명:
i = 1, j = 2를 선택하면 강도는 (3 * 5) / gcd(3, 5)² = 15 / 1 = 15이며,
이것이 모든 쌍 중 최대값입니다.
```

**예제 2:**
```
입력: nums = [4,6,8]
출력: 12
설명:
i = 1, j = 2를 선택하면 강도는 (6 * 8) / gcd(6, 8)² = 48 / 4 = 12이며,
이것이 모든 쌍 중 최대값입니다.
```

**예제 3:**
```
입력: nums = [3,3]
출력: 1
설명:
i = 0, j = 1을 선택하면 강도는 (3 * 3) / gcd(3, 3)² = 9 / 9 = 1이며,
이것이 모든 쌍 중 최대값입니다.
```

---

**제약 조건:**
- `2 <= nums.length <= 2000`
- `1 <= nums[i] <= 10⁵`

---

용어 보충:
- **gcd(a, b)**: a와 b의 최대공약수 (Greatest Common Divisor). 예: gcd(6, 8) = 2
- 참고로 이 강도 공식은 수학적으로 `(a / gcd) × (b / gcd)`, 즉 두 수를 각각 최대공약수로 나눈 몫들의 곱과 같습니다.
*/
