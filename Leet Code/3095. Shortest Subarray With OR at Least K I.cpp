class Solution {
public:
    int minimumSubarrayLength(const vector<int>& nums, const int k) 
    {
        const size_t ARRAY_LENGTH = nums.size();
        int min_length = INT_MAX;

        for (int i = 0; i <ARRAY_LENGTH; ++i) {
            int or_sum = 0;
            for (int j = i; j < ARRAY_LENGTH; ++j) {
                or_sum |= nums[j];
                if (or_sum >= k) {
                    min_length = min(min_length, j - i + 1);
                }
            }
        }

        return min_length == INT_MAX ? -1 : min_length;
    }
};

// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/description/

/*

**문제:**

비음수 정수 배열 `nums`와 정수 `k`가 주어집니다.

배열의 모든 요소의 비트 OR이 적어도 `k`와 같으면 해당 배열은 특별한 배열입니다.

`nums`의 가장 짧은 특별한 비어 있지 않은 부분 배열의 길이를 반환하거나, 특별한 부분 배열이 존재하지 않으면 -1을 반환합니다.

**예시:**

```
Input: nums = [1,2,3], k = 2
Output: 1
설명: [3] 부분 배열의 OR 값은 3입니다. 따라서, 1을 반환합니다.

Input: nums = [2,1,8], k = 10
Output: 3
설명: [2,1,8] 부분 배열의 OR 값은 11입니다. 따라서, 3을 반환합니다.

Input: nums = [1,2], k = 0
Output: 1
설명: [1] 부분 배열의 OR 값은 1입니다. 따라서, 1을 반환합니다.
```

**제한사항:**

- 1 <= nums.length <= 50
- 0 <= nums[i] <= 50
- 0 <= k < 64
*/
