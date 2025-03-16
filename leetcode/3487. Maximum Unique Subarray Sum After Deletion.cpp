class Solution 
{
public:
    int maxSum(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        unordered_set<int> uniquePositives;
    
        for (const int number : nums)
        {
            assert(MIN_NUM <= number && number <= MAX_NUM);
            if (number > 0)
            {
                uniquePositives.insert(number);
            }
        }
        
        const int totalUniqueSum = accumulate(uniquePositives.begin(), uniquePositives.end(), 0);
        
        if (totalUniqueSum == 0)
        {
            return *max_element(nums.begin(), nums.end());
        }

        return totalUniqueSum;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = -100,
        MAX_NUM = 100,
    };
};


// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/



/*

**3487. 삭제 후 최대 고유 부분 배열 합**

**난이도:** 쉬움

**문제 설명:**  
정수 배열 **nums**가 주어집니다.

배열 **nums**에서 원하는 만큼의 원소를 삭제할 수 있으며, 단 배열이 비어있어서는 안 됩니다. 삭제를 완료한 후, **nums**의 부분 배열 중 아래 두 조건을 만족하는 부분 배열을 선택하세요:

1. 해당 부분 배열의 모든 원소는 서로 유일해야 합니다.
2. 부분 배열의 원소 합이 최대가 되어야 합니다.

이와 같은 조건을 만족하는 부분 배열의 최대 합을 반환하세요.

---

**예제 1:**

- **입력:** nums = [1,2,3,4,5]  
- **출력:** 15  
- **설명:**  
  어떤 원소도 삭제하지 않고 전체 배열을 선택하면 최대 합을 얻을 수 있습니다.

---

**예제 2:**

- **입력:** nums = [1,1,0,1,1]  
- **출력:** 1  
- **설명:**  
  nums[0] == 1, nums[1] == 1, nums[2] == 0, nums[3] == 1 원소들을 삭제하고, 남은 [1]을 선택하면 최대 합을 얻을 수 있습니다.

---

**예제 3:**

- **입력:** nums = [1,2,-1,-2,1,0,-1]  
- **출력:** 3  
- **설명:**  
  nums[2] == -1, nums[3] == -2를 삭제한 후, 남은 [1,2,1,0,-1]에서 [2, 1] 부분 배열을 선택하면 최대 합을 얻을 수 있습니다.

---

**제약 조건:**

- 1 <= nums.length <= 100  
- -100 <= nums[i] <= 100

---
*/
