class Solution
{
public:
    int maximumUniqueSubarray(const vector<int>& nums) const
    {
        assert(MIN_LEN <= nums.size() && nums.size() <= MAX_LEN);

        unordered_map<int, int> freq;
        const size_t LENGTH = nums.size();
        size_t left = 0;
        size_t right = 0;
        int maxSum = 0;
        int windowSum = 0;

        while (right < LENGTH)
        {
            const int currNum = nums[right];
            assert(MIN_NUM <= currNum && currNum <= MAX_NUM);
            if (freq[currNum] == 0)
            {
                windowSum += currNum;
                ++freq[currNum];
                maxSum = max(maxSum, windowSum);
                ++right;
            }
            else
            {
                windowSum -= nums[left];
                --freq[nums[left]];
                ++left;
            }
        }

        return maxSum;
    }

private:
    enum
    {
        MIN_LEN = 1,
        MAX_LEN = 100000,
        MIN_NUM = 1,
        MAX_NUM = 10000
    };
};

// https://leetcode.com/problems/maximum-erasure-value/description/?envType=daily-question&envId=2025-07-22

/*



## 1695. 최대 지우기 점수

**난이도: 중**

---

### 문제 설명

양의 정수 배열 `nums`가 주어집니다.
\*\*서로 다른 원소로만 이루어진 연속된 부분 배열(subarray)\*\*을 하나 골라 \*\*그 합(점수)\*\*을 구하려고 합니다.

부분 배열을 한 번만 골라 지울 수 있을 때,
\*\*얻을 수 있는 최대 점수(부분 배열의 합의 최댓값)\*\*를 반환하세요.

여기서 "부분 배열(subarray)"란,
`a[l], a[l+1], ..., a[r]` (l ≤ r)와 같이 **배열에서 연속된 구간**을 의미합니다.

---

### 예시

#### 예시 1

**입력:**
nums = \[4,2,4,5,6]

**출력:**
17

**설명:**
최적의 부분 배열은 \[2,4,5,6]이며, 합은 2+4+5+6=17입니다.

---

#### 예시 2

**입력:**
nums = \[5,2,1,2,5,2,1,2,5]

**출력:**
8

**설명:**
최적의 부분 배열은 \[5,2,1] 또는 \[1,2,5]이고, 합은 8입니다.

---

### 제약사항

* 1 <= nums.length <= 100,000
* 1 <= nums\[i] <= 10,000

---

### 힌트

* 부분 배열 내의 각 원소가 모두 **서로 달라야** 하며,
  각 인덱스에서 시작하는 부분 배열 중 **가장 처음 나오는** 유니크 배열만 고려하면 됨
* **투 포인터(슬라이딩 윈도우)** 기법으로 해결할 수 있음



*/
