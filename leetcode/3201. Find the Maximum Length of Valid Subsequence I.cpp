class Solution
{
public:
    int maximumLength(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        const size_t n = nums.size();
        size_t evenCount = 0;
        size_t oddCount = 0;

        for (size_t i = 0; i < n; ++i)
        {
            assert(MIN_VALUE <= nums[i] && nums[i] <= MAX_VALUE);
            if (nums[i] % 2 == 0)
            {
                ++evenCount;
            }
            else
            {
                ++oddCount;
            }
        }

        // 교차(짝-홀-짝...) subsequence
        bool bIsEven = (nums[0] % 2 == 0);
        size_t crossCount = 1;

        for (size_t i = 1; i < n; ++i)
        {
            if (bIsEven == true && nums[i] % 2 == 1) // 짝홀
            {
                ++crossCount;
                bIsEven = false;
            }
            else if (bIsEven == false && nums[i] % 2 == 0) // 홀짝
            {
                ++crossCount;
                bIsEven = true;
            }
        }

        return static_cast<int>(max({evenCount, oddCount, crossCount}));
    }

private:
    enum
    {
        MIN_LENGTH = 2,
        MAX_LENGTH = 200000,
        MIN_VALUE = 1,
        MAX_VALUE = 10000000
    };
};


// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/?envType=daily-question&envId=2025-07-16

/*



## 3201. 유효한 부분수열의 최대 길이 찾기 I

**난이도: 중**

---

### 문제 설명

정수 배열 `nums`가 주어집니다.

길이가 `x`인 `nums`의 부분수열 `sub`가 **유효(valid)** 하려면 아래 조건을 만족해야 합니다.

* `(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2`

즉, **인접한 두 수의 합을 2로 나눈 나머지가 모두 동일**해야 합니다.

`nums`에서 유효한 부분수열 중 **가장 긴 부분수열의 길이**를 구해 반환하세요.

**부분수열**이란, 배열에서 일부 원소(혹은 아무 원소도 안 지워도 됨)를 순서를 바꾸지 않고 골라낸 배열입니다.

---

### 예시

#### 예시 1

**입력:**
nums = \[1, 2, 3, 4]

**출력:**
4

**설명:**
가장 긴 유효 부분수열은 \[1, 2, 3, 4]입니다.

---

#### 예시 2

**입력:**
nums = \[1, 2, 1, 1, 2, 1, 2]

**출력:**
6

**설명:**
가장 긴 유효 부분수열은 \[1, 2, 1, 2, 1, 2]입니다.

---

#### 예시 3

**입력:**
nums = \[1, 3]

**출력:**
2

**설명:**
가장 긴 유효 부분수열은 \[1, 3]입니다.

---

### 제약사항

* 2 <= nums.length <= 200,000
* 1 <= nums\[i] <= 10,000,000

---

다른 궁금한 점이나 코드 구조 요청, 설명 등이 필요하면 언제든 말씀해 주세요!

*/
