class Solution 
{
public:
    long long countBadPairs(const vector<int>& nums) 
    {
        unordered_map<long long, long long> diffFrequency;
        const size_t LENGTH = nums.size();
        const long long totalPairs = static_cast<long long>(LENGTH )* (LENGTH - 1) / 2;
        long long goodPairs = 0;

        for (size_t i = 0; i < LENGTH; i++)
        {
            const long long diff = static_cast<long long>(i) - nums[i];
            ++diffFrequency[diff];
        }

        for (const auto& [diff, frequency] : diffFrequency)
        {
            goodPairs += frequency * (frequency - 1) / 2;
        }

        return totalPairs - goodPairs;
    }
};

// https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09

/*

다음은 문제 원문을 그대로 한국어로 번역한 내용입니다.

---

**2364. 나쁜 쌍의 개수 세기**  
Medium  
Topics  
Companies  
Hint

0-인덱스 정수 배열 **nums**가 주어집니다.  
두 인덱스 **(i, j)**가 나쁜 쌍(bad pair)이라고 하는 조건은 **i < j** 이면서 **j - i ≠ nums[j] - nums[i]** 인 경우입니다.

**nums**에서 나쁜 쌍의 총 개수를 반환하세요.

---

**예제 1:**

```
Input: nums = [4,1,3,3]
Output: 5
```

*설명:*
- 쌍 (0, 1)은 1 - 0 ≠ 1 - 4 이므로 나쁜 쌍입니다.
- 쌍 (0, 2)는 2 - 0 ≠ 3 - 4, 즉 2 ≠ -1 이므로 나쁜 쌍입니다.
- 쌍 (0, 3)은 3 - 0 ≠ 3 - 4, 즉 3 ≠ -1 이므로 나쁜 쌍입니다.
- 쌍 (1, 2)는 2 - 1 ≠ 3 - 1, 즉 1 ≠ 2 이므로 나쁜 쌍입니다.
- 쌍 (2, 3)은 3 - 2 ≠ 3 - 3, 즉 1 ≠ 0 이므로 나쁜 쌍입니다.

총 5개의 나쁜 쌍이 있으므로 5를 반환합니다.

---

**예제 2:**

```
Input: nums = [1,2,3,4,5]
Output: 0
```

*설명:*  
나쁜 쌍이 하나도 없으므로 0을 반환합니다.

---

**제약 조건:**

- 1 <= nums.length <= 10⁵  
- 1 <= nums[i] <= 10⁹
*/
