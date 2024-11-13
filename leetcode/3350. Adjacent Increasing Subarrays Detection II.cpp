class Solution 
{
public:
    int maxIncreasingSubarrays(const vector<int>& nums) 
    {
        const int LENGTH = nums.size();
        vector<int> suff(LENGTH, 1);

        for (int i = LENGTH - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                suff[i] = suff[i + 1] + 1;
            }
        }

        return performBinarySearch(nums, suff);
    }

private:
    bool checkIncreasingSubarrays(const int mid, const vector<int>& suff, const vector<int>& nums) const
    {
        
        const int LENGTH = nums.size();
        int i = 0;

        while (i <= (LENGTH - 2 * mid))
        {
            if (suff[i] >= mid && suff[i + mid] >= mid)
            {
                return true;
            }
            ++i;
        }

        return false;
    }

    int performBinarySearch(const vector<int>& nums, const vector<int>& suff) const
    {
        int left = 1;
        int right = nums.size() / 2;
        int result = 0;

        while (left <= right)
        {
            const int mid = left + (right - left) / 2;

            if (checkIncreasingSubarrays(mid, suff, nums) == true)
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};






// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/











// Time limit 1

class Solution 
{
public:
    int maxIncreasingSubarrays(const vector<int>& nums) 
    {
        const long long LENGTH = nums.size();
        int maxK = 0;
        int k = 0;

        while (k < LENGTH)
        {
            for (long long i = 0; i <= LENGTH - 2 * k; ++i)
            {
                if (maxIncreasingSubarraysHelper(i, i + k, nums) == true && maxIncreasingSubarraysHelper(i + k, i + 2 * k, nums) == true)
                {
                    maxK = max(maxK, k);
                }
            }
            ++k;
        }

        return maxK;
    }

private:
    bool maxIncreasingSubarraysHelper(const long long start, const long long end, const vector<int>& nums)
    {
        for (long long i = start; i < end - 1; ++i)
        {
            if (nums[i] >= nums[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};


// time limit 2
class Solution 
{
public:
    int maxIncreasingSubarrays(const vector<int>& nums) 
    {
        const long long LENGTH = nums.size();
        int left = 0;
        int right = LENGTH / 2;
        int maxK = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canFindIncreasingSubarrays(mid, nums))
            {
                maxK = mid;  // 현재 mid가 가능하므로 최댓값을 갱신
                left = mid + 1;  // 더 큰 값도 가능할 수 있으므로 left를 증가
            }
            else
            {
                right = mid - 1;  // mid가 불가능하면 더 작은 값으로 탐색
            }
        }

        return maxK;
    }

private:
    bool canFindIncreasingSubarrays(const int k, const vector<int>& nums)
    {
        const long long LENGTH = nums.size();

        for (long long i = 0; i <= LENGTH - 2 * k; ++i)
        {
            if (isStrictlyIncreasing(i, i + k, nums) && isStrictlyIncreasing(i + k, i + 2 * k, nums))
            {
                return true;
            }
        }

        return false;
    }

    bool isStrictlyIncreasing(const long long start, const long long end, const vector<int>& nums)
    {
        for (long long i = start; i < end - 1; ++i)
        {
            if (nums[i] >= nums[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};

/*

**3350. 인접한 증가하는 부분 배열 감지 II**  
난이도: 중간

---

정수 `n`개로 이루어진 배열 `nums`가 주어졌을 때, 길이가 `k`인 **두 개의 인접한 부분 배열**이 모두 엄격히 증가하도록 할 수 있는 **최대 k의 값**을 찾는 것이 목표입니다. 특히, 인덱스 `a`와 `b` (`a < b`)에서 시작하는 두 길이 `k`인 부분 배열 `nums[a..a + k - 1]` 및 `nums[b..b + k - 1]`이 다음 조건을 만족해야 합니다:

1. 두 부분 배열 모두 엄격히 증가하는 부분 배열입니다.
2. 두 부분 배열은 인접해야 하며, 이는 `b = a + k`임을 의미합니다.

**k**의 가능한 최대 값을 반환하세요.

부분 배열이란 배열 내에서 연속된 비어 있지 않은 요소들의 서열입니다.

---

### 예제 1:

입력: 
```
nums = [2,5,7,8,9,2,3,4,3,1]
```
출력: 
```
3
```
설명:
- 인덱스 `2`에서 시작하는 부분 배열은 `[7, 8, 9]`로 엄격히 증가합니다.
- 인덱스 `5`에서 시작하는 부분 배열은 `[2, 3, 4]`로 엄격히 증가합니다.
- 이 두 부분 배열은 인접하며, `k = 3`이 가능한 최대 값입니다.

### 예제 2:

입력: 
```
nums = [1,2,3,4,4,4,4,5,6,7]
```
출력: 
```
2
```
설명:
- 인덱스 `0`에서 시작하는 부분 배열은 `[1, 2]`로 엄격히 증가합니다.
- 인덱스 `2`에서 시작하는 부분 배열은 `[3, 4]`로 엄격히 증가합니다.
- 이 두 부분 배열은 인접하며, `k = 2`가 가능한 최대 값입니다.

---

### 제약 사항:

- `2 <= nums.length <= 2 * 10^5`
- `-10^9 <= nums[i] <= 10^9`

이 문제는 배열 내의 두 개의 인접한 부분 배열이 엄격히 증가할 수 있는 최대 `k` 값을 찾는 문제입니다. 배열 내의 연속된 구간을 탐색하여 이 조건을 만족하는 최대 길이를 계산해야 합니다.

*/
