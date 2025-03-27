class Solution 
{
public:
    int minimumIndex(const vector<int>& nums) const 
    {
        assert(nums.size() >= MIN_SIZE && nums.size() <= MAX_SIZE);

        const int arraySize = nums.size();
        unordered_map<int, int> frequency;
        int dominantElement = 0;
        int dominantCount = 0;
        int leftCount = 0;

        for (const int num : nums) 
        {
            ++frequency[num];
            if (frequency[num] > dominantCount) 
            {
                dominantElement = num;
                dominantCount = frequency[num];
            }
        }
        
        for (size_t i = 0; i < arraySize; ++i) 
        {
            assert(nums[i] >= MIN_VALUE && nums[i] <= MAX_VALUE);
            if (nums[i] == dominantElement) 
            {
                ++leftCount;
                const int rightCount = dominantCount - leftCount;
                const int rightLength = arraySize - (i + 1);
                if (isDominant(leftCount, i + 1) == true && isDominant(rightCount, rightLength) == true) 
                {
                    return i;
                }
            }
        }
        
        return FAIL;
    }
    
private:
    bool isDominant(const int frequency, const int subarrayLength) const 
    {
        return (2 * frequency) > subarrayLength;
    }
    
    enum 
    {
        FAIL = -1,
        MIN_SIZE = 1,
        MAX_SIZE = 100000,
        MIN_VALUE = 1,
        MAX_VALUE = 1000000000
    };
};


// https://leetcode.com/problems/minimum-index-of-a-valid-split/description/?envType=daily-question&envId=2025-03-27

/*


---

**2780. 유효한 분할의 최소 인덱스 찾기**

**난이도:** 중간

**문제 설명:**  
정수 배열 **nums**가 주어집니다. 이 배열은 길이 m인 배열로, 배열의 어떤 원소 x가 **dominant**하다는 것은, 배열의 원소들 중 절반보다 많은 원소가 x의 값임을 의미합니다.

배열 **nums**는 한 개의 dominant 원소를 가지며, 0-indexed로 주어집니다.

배열 **nums**를 인덱스 i에서 두 부분으로 나눌 수 있습니다. 즉, **nums[0, …, i]**와 **nums[i+1, …, n-1]**로 분할할 수 있는데, 이 분할이 유효하려면 아래 조건을 만족해야 합니다:

- 0 <= i < n - 1  
- 분할된 두 배열 **nums[0, …, i]**와 **nums[i+1, …, n-1]** 모두에서 같은 dominant 원소가 존재해야 합니다.

여기서 **nums[i, …, j]**는 인덱스 i부터 j까지의 연속 부분 배열을 의미하며, 만약 j < i인 경우 빈 배열로 간주합니다.

유효한 분할 중에서 최소 인덱스 i를 반환하세요. 만약 유효한 분할이 존재하지 않으면 -1을 반환합니다.

---

**예제 1:**

- **입력:** nums = [1, 2, 2, 2]
- **출력:** 2
- **설명:**  
  배열을 인덱스 2에서 분할하면 [1, 2, 2]와 [2]가 됩니다.  
  - 배열 [1, 2, 2]에서는 원소 2가 2번 등장하며, 2 * 2 > 3이므로 dominant 원소는 2입니다.  
  - 배열 [2]에서는 2가 1번 등장하며, 1 * 2 > 1이므로 dominant 원소는 2입니다.  
  두 부분 배열 모두 dominant 원소가 2이므로, 이 분할은 유효하며 최소 인덱스는 2입니다.

---

**예제 2:**

- **입력:** nums = [2, 1, 3, 1, 1, 1, 7, 1, 2, 1]
- **출력:** 4
- **설명:**  
  배열을 인덱스 4에서 분할하면 [2, 1, 3, 1, 1]과 [1, 7, 1, 2, 1]이 됩니다.  
  - 배열 [2, 1, 3, 1, 1]에서는 원소 1이 3번 등장하며, 3 * 2 > 5이므로 dominant 원소는 1입니다.  
  - 배열 [1, 7, 1, 2, 1]에서도 원소 1이 3번 등장하여 dominant 원소는 1입니다.  
  따라서 유효한 분할이며 최소 인덱스는 4입니다.

---

**예제 3:**

- **입력:** nums = [3, 3, 3, 3, 7, 2, 2]
- **출력:** -1
- **설명:**  
  어떤 분할을 시도해도 두 부분 배열 모두에서 같은 dominant 원소를 갖는 유효한 분할을 만들 수 없으므로 -1을 반환합니다.

---

**제약 조건:**

- 1 <= nums.length <= 10^5  
- 1 <= nums[i] <= 10^9  
- **nums**에는 정확히 한 개의 dominant 원소가 존재합니다.

---
*/
