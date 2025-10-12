class Solution 
{
public:
    int sumDivisibleByK(const vector<int>& nums, const int k) const
    {
        assert (MIN_K <= k && k <= MAX_K);
        assert (MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        unordered_map<int, int> freq;
        int sum = 0;

        for (const auto num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            ++freq[num];
        }

        for (const auto& [num, count] : freq)
        {
            assert(count >= 0);
            if (count % k == 0)
            {
                sum += (count * num);
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
        MIN_NUM = 1,
        MAX_NUM = 100,
        MIN_K = 1,
        MAX_K = 100,
    };
};

//https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/description/ 

/*
### 3712. 빈도수가 K로 나누어 떨어지는 원소들의 합

정수 배열 `nums`와 정수 `k`가 주어집니다.

`nums`에 있는 모든 원소 중에서, 해당 원소의 빈도수(frequency)가 `k`로 나누어 떨어지는 원소들의 합을 반환하세요. 
그러한 원소가 없으면 `0`을 반환하세요.

**참고:** 어떤 원소의 총 빈도수가 `k`로 나누어 떨어지는 경우, 
해당 원소는 배열에 나타난 횟수만큼 정확히 합계에 포함됩니다.

원소 `x`의 빈도수는 배열에 `x`가 나타나는 횟수입니다.

**예시 1:**

**입력:** `nums = [1,2,2,3,3,3,3,4], k = 2`

**출력:** `16`

**설명:**

*   숫자 1은 한 번 나타납니다 (홀수 빈도수).
*   숫자 2는 두 번 나타납니다 (짝수 빈도수).
*   숫자 3은 네 번 나타납니다 (짝수 빈도수).
*   숫자 4는 한 번 나타납니다 (홀수 빈도수).

따라서 총합은 2 + 2 + 3 + 3 + 3 + 3 = 16입니다.

**예시 2:**

**입력:** `nums = [1,2,3,4,5], k = 2`

**출력:** `0`

**설명:**

짝수 번 나타나는 원소가 없으므로, 총합은 0입니다.

**예시 3:**

**입력:** `nums = [4,4,4,1,2,3], k = 3`

**출력:** `12`

**설명:**

*   숫자 1은 한 번 나타납니다.
*   숫자 2는 한 번 나타납니다.
*   숫자 3은 한 번 나타납니다.
*   숫자 4는 세 번 나타납니다.

따라서 총합은 4 + 4 + 4 = 12입니다.

**제약 조건:**

*   `1 <= nums.length <= 100`
*   `1 <= nums[i] <= 100`
*   `1 <= k <= 100`
*/
