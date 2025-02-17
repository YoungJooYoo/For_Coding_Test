class Solution 
{
public:
    int sumOfGoodNumbers(const vector<int>& nums, const int k) const
    {
        assert(nums.size() >= MIN_SIZE && nums.size() <= MAX_SIZE);
        assert(k >= MIN_K && k <= (nums.size() / 2));

        const int LENGTH = nums.size();
        int sum = 0;

        for (int i = 0; i < LENGTH; ++i)
        {
            assert(nums[i] >= MIN_VALUE && nums[i] <= MAX_VALUE);
            if (((i - k < 0) || (nums[i] > nums[i - k])) && ((i + k >= LENGTH) || (nums[i] > nums[i + k])))
            {
                sum += nums[i];
            }
        }

        return sum;  
    }

private:
    enum
    {
        MIN_SIZE  = 2,
        MAX_SIZE  = 100,
        MIN_VALUE = 1,
        MAX_VALUE = 1000,
        MIN_K     = 1
    };
};

// https://leetcode.com/problems/sum-of-good-numbers/description/

/*
다음은 문제 원문을 그대로 한국어로 번역한 내용입니다.

---

**3452. 좋은 수들의 합**  
*Easy*  
*Hint*

정수 배열 **nums**와 정수 **k**가 주어집니다.  
만약 인덱스 **i - k**와 **i + k**(해당 인덱스가 존재하는 경우)의 요소보다 **nums[i]**가 엄격하게 크다면, **nums[i]**를 좋은 요소(good number)로 간주합니다.  
만약 이 두 인덱스 중 어느 것도 존재하지 않는다면, **nums[i]**는 여전히 좋은 요소로 간주됩니다.

배열 내 모든 좋은 요소들의 합을 반환하세요.

---

**예제 1:**

```
입력: nums = [1,3,2,1,5,4], k = 2
출력: 12
```

*설명:*  
좋은 수들은 다음과 같습니다:  
- **nums[1] = 3** (인덱스 - k와 + k의 값보다 큼),  
- **nums[4] = 5**,  
- **nums[5] = 4**  
따라서 이들의 합은 3 + 5 + 4 = 12입니다.

---

**예제 2:**

```
입력: nums = [2,1], k = 1
출력: 2
```

*설명:*  
유일한 좋은 수는 **nums[0] = 2**입니다. (nums[0]가 nums[1]보다 엄격하게 큽니다.)

---

**제약 조건:**

- 2 <= nums.length <= 100  
- 1 <= nums[i] <= 1000  
- 1 <= k <= ⌊nums.length / 2⌋

---

**힌트:**  
각 인덱스마다, **nums[i]**가 **nums[i - k]**와 **nums[i + k]**보다 엄격하게 큰지 확인하세요.
*/
