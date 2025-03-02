class Solution 
{
public:
    int largestInteger(const vector<int>& nums, const int k) const
    {
        const int n = nums.size();

        assert(n >= MIN_ARRAY_SIZE && n <= MAX_ARRAY_SIZE);
        assert(k >= MIN_K && k <= n);

        if (k == 1)
        {
            unordered_map<int, int> freq;
            for (const int num : nums)
            {
                ++freq[num];
            }
            int candidate = FAIL;
            for (const auto& [key, count] : freq)
            {
                if (count == 1)
                {
                    candidate = max(candidate, key);
                }
            }
            return candidate;
        }
        else if (k == n)
        {
            return *max_element(nums.begin(), nums.end());
        }


        const int firstCandidate = nums.front();
        const int lastCandidate = nums.back();
        int countFirst = 0;
        int countLast = 0;

        for (const int num : nums)
        {
            if (num == firstCandidate)
            {
                ++countFirst;
            }
            else if (num == lastCandidate)
            {
                ++countLast;
            }
        }

        const bool firstValid = (countFirst == 1) ? true : false;
        const bool lastValid = (countLast == 1) ? true : false;
        if (firstValid && lastValid == true)
        {
            return max(firstCandidate, lastCandidate);
        }
        else if (firstValid == true)
        {
            return firstCandidate;
        }
        else if (lastValid == true)
        {
            return lastCandidate;
        }

        return FAIL;
    }

private:
    enum
    {
        MIN_ARRAY_SIZE = 1,
        MAX_ARRAY_SIZE = 50,
        MIN_K = 1,
        FAIL = -1
    };
};

// https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/

/*


**3471. 가장 큰 거의 누락된 정수 찾기**  
*Medium*  
*Topics*  
*Companies*  
*Hint*

정수 배열 **nums**와 정수 **k**가 주어집니다.

정수 **x**가 **nums**에서 거의 누락되었다(almost missing)고 하는 조건은, **x**가 **nums** 내의 크기 **k**인 연속 부분 배열(subarray)에 정확히 한 번만 나타나는 경우입니다.

**nums**에서 거의 누락된 정수들 중 가장 큰 값을 반환하세요. 만약 그러한 정수가 존재하지 않으면 -1을 반환합니다.

참고:  
- 부분 배열은 배열 내에서 연속된 원소들의 수열입니다.

---

**예제 1:**

- **입력:** nums = [3, 9, 2, 1, 7], k = 3  
- **출력:** 7  
- **설명:**  
  - 1은 크기 3인 부분 배열 [9, 2, 1]과 [2, 1, 7]에 각각 등장하므로 2번 나타납니다.  
  - 2는 [3, 9, 2], [9, 2, 1], [2, 1, 7]에 등장하여 3번 나타납니다.  
  - 3은 [3, 9, 2]에 한 번 나타납니다.  
  - 7은 [2, 1, 7]에 한 번 나타납니다.  
  - 9는 [3, 9, 2]와 [9, 2, 1]에 등장하여 2번 나타납니다.  
  - 조건을 만족하는 정수 중 가장 큰 값은 7입니다.

---

**예제 2:**

- **입력:** nums = [3, 9, 7, 2, 1, 7], k = 4  
- **출력:** 3  
- **설명:**  
  - 1은 [9, 7, 2, 1]과 [7, 2, 1, 7]에 등장하여 2번 나타납니다.  
  - 2는 [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7]에 등장하여 3번 나타납니다.  
  - 3은 [3, 9, 7, 2]에 한 번 나타납니다.  
  - 7은 [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7]에 등장하여 3번 나타납니다.  
  - 9는 [3, 9, 7, 2]와 [9, 7, 2, 1]에 등장하여 2번 나타납니다.  
  - 조건을 만족하는 정수 중 유일하게 한 번만 나타나는 값은 3이며, 그 중 가장 큰 값은 3입니다.

---

**예제 3:**

- **입력:** nums = [0, 0], k = 1  
- **출력:** -1  
- **설명:**  
  크기 1인 부분 배열에서 단 한 번만 나타나는 정수는 존재하지 않습니다.

---

**제약 조건:**

- 1 <= nums.length <= 50  
- 0 <= nums[i] <= 50  
- 1 <= k <= nums.length

---

**힌트 1:**  
k = 1, k = n, 그리고 1 < k < n 세 가지 경우로 문제를 풀어보세요.

**힌트 2:**  
만약 k = 1이면, nums에서 정확히 한 번 나타나는 가장 큰 정수를 반환하세요.

**힌트 3:**  
만약 k = n이면, nums에서 가장 큰 정수를 반환하세요.

**힌트 4:**  
만약 1 < k < n인 경우, nums[0]와 nums[n - 1]를 제외한 모든 원소는 크기 k인 부분 배열에서 두 번 이상 나타납니다.  
따라서, 답은 다음과 같이 결정됩니다:  
- 만약 nums[0]와 nums[n - 1]가 모두 정확히 한 번씩 나타난다면, 둘 중 더 큰 값을 반환합니다.  
- 만약 둘 중 하나만 한 번 나타난다면, 한 번 나타난 값을 반환합니다.  
- 만약 둘 다 두 번 이상 나타난다면, -1을 반환합니다.



*/
