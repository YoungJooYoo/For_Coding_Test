class Solution
{
public:
    int numSubseq(vector<int>& nums, const int target) const
    {
        assert(nums.size() >= MIN_LENGTH && nums.size() <= MAX_LENGTH);
        assert(target >= MIN_TARGET && target <= MAX_TARGET);

        const size_t length = nums.size();
        int left = 0;
        int right = static_cast<int>(length) - 1;
        int answer = 0;
        vector<int> pow2(length + 1, 1);

        sort(nums.begin(), nums.end());

        for (size_t i = 1; i <= length; ++i)
        {
            pow2[i] = (static_cast<long long>(pow2[i - 1]) * 2) % MOD;
        }

        while (left <= right)
        {
            assert(nums[left] >= MIN_NUM && nums[left] <= MAX_NUM);
            assert(nums[right] >= MIN_NUM && nums[right] <= MAX_NUM);
            if (nums[left] + nums[right] <= target)
            {
                answer = (answer + pow2[right - left]) % MOD;
                ++left;
            }
            else
            {
                --right;
            }
        }

        return answer;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MIN_NUM = 1,
        MAX_NUM = 1000000,
        MIN_TARGET = 1,
        MAX_TARGET = 1000000,
        MOD = 1000000007
    };
};

// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29

/*

아래는 요청하신 문제의 **국문 번역**입니다.

---

**1498. 주어진 합 조건을 만족하는 부분수열의 개수**
중간 난이도

---

정수 배열 `nums`와 정수 `target`이 주어집니다.

`nums`에서 **비어있지 않은 부분수열(subsequence)** 중
그 부분수열에서 **최솟값과 최댓값의 합이 `target` 이하**인 부분수열의 개수를 구하세요.
정답이 매우 클 수 있으므로, **10⁹ + 7로 나눈 나머지**를 반환하세요.

---

### 예시 1

```
입력: nums = [3,5,6,7], target = 9
출력: 4
설명: 조건을 만족하는 부분수열은 4개입니다.
[3]       → 최솟값 + 최댓값 = 3 + 3 = 6 ≤ 9
[3,5]     → 3 + 5 = 8 ≤ 9
[3,5,6]   → 3 + 6 = 9 ≤ 9
[3,6]     → 3 + 6 = 9 ≤ 9
```

---

### 예시 2

```
입력: nums = [3,3,6,8], target = 10
출력: 6
설명: 조건을 만족하는 부분수열은 6개입니다.
[3], [3], [3,3], [3,6], [3,6], [3,3,6]
(중복된 값도 각각 다른 부분수열로 취급합니다)
```

---

### 예시 3

```
입력: nums = [2,3,3,4,6,7], target = 12
출력: 61
설명: 전체 비어있지 않은 부분수열은 63개이고,
이 중 조건을 만족하지 않는 부분수열([6,7], [7]) 2개를 제외한 61개가 조건을 만족합니다.
```

---

### 제약사항

* 1 ≤ nums.length ≤ 10⁵
* 1 ≤ nums\[i] ≤ 10⁶
* 1 ≤ target ≤ 10⁶

---

**힌트**

* nums 배열을 정렬하세요.
* 투포인터(two pointers) 방법을 사용: 인덱스 i(부분수열의 최소값)마다, i 이상에서 조건을 만족하는 최대 j를 찾으세요.
* 부분수열의 개수를 세는 방법을 고민하세요.

---


*/
