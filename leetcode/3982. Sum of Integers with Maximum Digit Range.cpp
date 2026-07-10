class Solution
{
public:
    int maxDigitRange(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        int maxRange = numeric_limits<int>::min();
        int sum = 0;

        for (const int num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            const int range = getDigitRange(num);
            assert(range >= 0);
            if (range > maxRange)
            {
                maxRange = range;
                sum = num;
            }
            else if (range == maxRange)
            {
                sum += num;
            }
        }
        
        assert(sum >= 0);
        return sum;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = 10,
        MAX_NUM = 100000
    };

    static int getDigitRange(const int num)
    {
        string strNum = to_string(num);
        ranges::sort(strNum);
        return (strNum.back() - '0') - (strNum.front() - '0');
    }
};

/*
https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/description/

## 3982. 최대 자릿수 범위를 가진 정수들의 합 (Sum of Integers with Maximum Digit Range)

**난이도: Easy**

정수 배열 `nums`가 주어집니다.

정수의 **자릿수 범위(digit range)**는 그 정수의 가장 큰 자릿수와 가장 작은 자릿수의 차이로 정의됩니다.

예를 들어, `5724`의 자릿수 범위는 `7 - 2 = 5`입니다.

배열 내 모든 정수 중 **최대 자릿수 범위**와 같은 자릿수 범위를 가진 모든 정수들의 합을 반환하세요.

---

**예제 1:**
```
입력: nums = [5724,111,350]
출력: 6074
설명:
i    nums[i]  최대 자릿수  최소 자릿수  자릿수 범위
0    5724     7           2           5
1    111      1           1           0
2    350      5           0           5

최대 자릿수 범위는 5입니다. 이 범위를 가진 정수는 5724와 350이므로,
정답은 5724 + 350 = 6074입니다.
```

**예제 2:**
```
입력: nums = [90,900]
출력: 990
설명:
i    nums[i]  최대 자릿수  최소 자릿수  자릿수 범위
0    90       9           0           9
1    900      9           0           9

최대 자릿수 범위는 9입니다. 두 정수 모두 이 범위를 가지므로,
정답은 90 + 900 = 990입니다.
```

---

**제약 조건:**
- `1 <= nums.length <= 100`
- `10 <= nums[i] <= 10⁵`
*/
