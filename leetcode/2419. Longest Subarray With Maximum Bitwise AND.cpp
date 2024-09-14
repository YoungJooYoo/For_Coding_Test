class Solution 
{
public:
    int longestSubarray(const vector<int>& nums) 
    {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        int maxLength = numeric_limits<int>::min();
        int currLength = 0;

        for (const auto& num : nums)
        {
            if (num == MAX_NUM)
            {
                ++currLength;
                maxLength = max(maxLength, currLength);
            }
            else
            {
                currLength ^= currLength;
            }
        }

        assert(maxLength != numeric_limits<int>::min());
        return maxLength;
    }
};

// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2024-09-14

/*
2419. 최대 비트 AND를 갖는 가장 긴 부분 배열
중간 난이도
주제
회사
힌트

정수 배열 `nums`가 주어집니다.

`nums`에서 가능한 최대한의 비트 AND 값을 갖는 비어 있지 않은 부분 배열을 고려하세요.

다시 말해, 어떤 부분 배열의 비트 AND의 최대 값을 `k`라고 하면, 비트 AND가 `k`인 부분 배열만 고려합니다.
그러한 부분 배열 중 가장 긴 길이를 반환하세요.

배열의 비트 AND는 그 배열에 있는 모든 숫자의 비트 AND입니다.

부분 배열은 배열 내의 연속된 요소들의 시퀀스입니다.

---

**예제 1:**

```
입력: nums = [1,2,3,3,2,2]
출력: 2
설명:
부분 배열의 비트 AND의 가능한 최대 값은 3입니다.
그 값과 같은 가장 긴 부분 배열은 [3,3]이므로, 결과는 2입니다.
```

**예제 2:**

```
입력: nums = [1,2,3,4]
출력: 1
설명:
부분 배열의 비트 AND의 가능한 최대 값은 4입니다.
그 값과 같은 가장 긴 부분 배열은 [4]이므로, 결과는 1입니다.
```

---

**제약 사항:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`

*/
