class Solution 
{
public:
    int countCompleteSubarrays(const vector<int>& nums) const
    {
        assert(nums.size() >= MIN_SIZE && nums.size() <= MAX_SIZE);
  
        const unordered_set<int> fullSet(nums.begin(), nums.end());
        const size_t distinctCount = fullSet.size();
        const size_t n = nums.size();
        int result = 0;
        
        for (size_t i = 0; i < n; ++i) 
        {
            assert(nums[i] >= MIN_VALUE && nums[i] <= MAX_VALUE);
            unordered_set<int> windowSet;
            for (size_t j = i; j < n; ++j) 
            {
                windowSet.insert(nums[j]);
                if (windowSet.size() == distinctCount) 
                {
                    ++result;
                }
            }
        }

        assert(result >= 0);
        return result;
    }

private:
    enum 
    {
        MIN_SIZE   = 1,
        MAX_SIZE   = 1000,
        MIN_VALUE  = 1,
        MAX_VALUE  = 2000
    };
};

// https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24

/*
**2799. 배열에서 완전 부분 배열 개수 세기**

**난이도:** 중간

**문제 설명:**  
양의 정수로 이루어진 배열 **nums**가 주어집니다.

하나의 **부분 배열(subarray)**이 **완전(complete)**하다고 부르는 조건은 다음과 같습니다:

> 부분 배열 내에 포함된 **서로 다른(distinct)** 원소의 개수가,  
> **원래 배열 nums 전체**에서 등장하는 서로 다른 원소의 개수와 같아야 한다.

연속된 비어 있지 않은 배열 구간을 부분 배열이라 할 때,  
완전 부분 배열의 개수를 반환하세요.

---

**예제 1:**

- **입력:** nums = [1,3,1,2,2]  
- **출력:** 4  
- **설명:** 원래 배열에서는 distinct 원소가 {1,3,2}로 3개 있습니다.  
  부분 배열 중에서 3개의 서로 다른 원소를 모두 포함하는 구간은 다음 4가지입니다:  
  - [1,3,1,2]  
  - [1,3,1,2,2]  
  - [3,1,2]  
  - [3,1,2,2]

---

**예제 2:**

- **입력:** nums = [5,5,5,5]  
- **출력:** 10  
- **설명:** 전체 배열에 등장하는 distinct 원소는 {5} 1개뿐이므로, 모든 부분 배열이 완전 부분 배열입니다.  
  길이 4짜리 배열의 부분 배열 개수는 \(4 \times (4+1)/2 = 10\)개입니다.

---

**제약 조건:**

- 1 ≤ nums.length ≤ 1000  
- 1 ≤ nums[i] ≤ 2000
*/
