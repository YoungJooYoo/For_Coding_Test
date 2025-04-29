class Solution 
{
public:
    long long countSubarrays(const vector<int>& nums, const int k) const 
    {
        assert(nums.size() >= MIN_N && nums.size() <= MAX_N);
 
        const int length = nums.size();
        const int maxElement = *max_element(nums.begin(), nums.end());
        long long totalCount = 0;
        int startIndex = 0;
        int endIndex = 0;
        unordered_map<int, int> freqMap;

        while (endIndex < length) 
        {
            const int current = nums[endIndex];
            ++freqMap[current];

            while (freqMap[maxElement] >= k) 
            {
                totalCount += (length - endIndex);
                const int leftValue = nums[startIndex];
                if (--freqMap[leftValue] == 0) 
                {
                    freqMap.erase(leftValue);
                }
                ++startIndex;
            }
            ++endIndex;
        }

        assert(totalCount >= 0);
        return totalCount;
    }

private:
    enum 
    {
        MIN_N       = 1,
        MAX_N       = 100000,
        MIN_K       = 1,
        MIN_VALUE   = 1,
        MAX_VALUE   = 1000000
    };
};

// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2025-04-29


/*
**2962. 최댓값이 최소 K번 등장하는 부분 배열 개수 세기**

**난이도:** 중간

**문제 설명:**  
정수 배열 **nums**와 양의 정수 **k**가 주어집니다.  

배열의 **부분 배열(subarray)**이란, 원본에서 연속된 원소들의 나열을 뜻합니다.  
이때, 부분 배열 내에서 **최댓값이 적어도 k번 이상 등장**하는 부분 배열의 개수를 구하여 반환하세요.

---

**예제 1:**

- **입력:** nums = [1,3,2,3,3], k = 2  
- **출력:** 6  
- **설명:**  
  최댓값이 3인 부분 배열 중 3이 최소 2번 이상 나오는 부분 배열은 다음 6가지입니다.  
  ```
  [1,3,2,3], [1,3,2,3,3], 
  [3,2,3], [3,2,3,3], 
  [2,3,3], [3,3]
  ```

---

**예제 2:**

- **입력:** nums = [1,4,2,1], k = 3  
- **출력:** 0  
- **설명:**  
  최댓값은 4이지만, 4가 3번 이상 등장하는 부분 배열은 존재하지 않습니다.

---

**제약 조건:**

- 1 ≤ nums.length ≤ 10^5  
- 1 ≤ nums[i] ≤ 10^6  
- 1 ≤ k ≤ 10^5
*/
