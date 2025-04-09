class Solution 
{
public:
    int minimumPairRemoval(vector<int>& nums) 
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        int result = 0;
        
        while (isSorted(nums) == false)
        {
            int bestIndex = 0;
            int minSum = numeric_limits<int>::max();  
            for (size_t i = 0; i < nums.size() - 1; ++i)
            {
                // assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
                const int pairSum = nums[i] + nums[i + 1];
                if (pairSum < minSum)
                {
                    minSum = pairSum;
                    bestIndex = i;
                }
            }
            nums[bestIndex] = minSum;
            nums.erase(nums.begin() + bestIndex + 1);
            ++result;
        }
        
        return result;
    }

private:
    bool isSorted(const vector<int>& nums) const
    {
        for (size_t i = 0; i < nums.size() - 1; ++i)
        {
            // assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            if (nums[i] > nums[i + 1]) return false;
        }

        return true;
    }

    enum 
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 50,
        MIN_NUM = -1000,
        MAX_NUM = 1000,
    };
};

// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/

/*
---

**3507. 배열을 정렬하기 위한 최소 쌍 제거 I**

**난이도:** 쉬움

**문제 설명:**  
정수 배열 **nums**가 주어집니다.  
배열에 대해 아래의 연산을 원하는 만큼 (0회 이상) 수행할 수 있습니다.

- **연산:**  
  1. **인접 쌍 선택:** 배열 **nums**에서 인접한 원소들 중, 합이 가장 작은 쌍을 선택합니다.  
     - 만약 합이 가장 작은 쌍이 여러 개 존재하면, 가장 왼쪽에 있는 쌍을 선택합니다.
  2. **쌍 제거 및 대체:** 선택한 두 원소를 그 합으로 대체합니다.

이 연산을 반복해서 배열 **nums**가 **비감소(non-decreasing)** 배열이 되도록 만들 때, 필요한 최소 연산 횟수를 반환하세요.

**비감소 배열의 정의:**  
배열의 각 원소가 그 이전 원소보다 작지 않은 경우(즉, 같거나 큰 경우)를 말합니다.

---

**예제 1:**

- **입력:** nums = [5, 2, 3, 1]  
- **출력:** 2  
- **설명:**  
  1. 인접 쌍 중 (3, 1)의 합이 4로 최소입니다.  
     - (3, 1)을 4로 대체하면, nums = [5, 2, 4]가 됩니다.  
  2. 이제 인접 쌍 중 (2, 4)의 합이 6으로 최소입니다.  
     - (2, 4)를 6으로 대체하면, nums = [5, 6]이 됩니다.  
  최종 배열 [5, 6]은 비감소 배열이므로, 총 2회의 연산으로 배열을 정렬할 수 있습니다.

---

**예제 2:**

- **입력:** nums = [1, 2, 2]  
- **출력:** 0  
- **설명:**  
  배열 [1, 2, 2]는 이미 비감소 배열이므로, 연산을 수행할 필요 없이 0을 반환합니다.

---

**제약 조건:**

- 1 <= nums.length <= 50  
- -1000 <= nums[i] <= 1000

---
*/
