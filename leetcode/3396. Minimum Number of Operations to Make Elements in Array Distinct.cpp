class Solution 
{
public:
    int minimumOperations(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        int count = 0;

        for (size_t i = 0; i < LENGTH; i = i + 3)
        {
            if (minimumOperationsHelper(nums, i) == false)
            {
                ++count;
            }
        }

        return count;
    }

private: 
    bool minimumOperationsHelper(const vector<int>& nums, const int start) const
    {
        const size_t LENGTH = nums.size();
        unordered_map<int, int> freq;

        for (size_t i = start; i < LENGTH; ++i)
        {
            ++freq[nums[i]];
        }

        return (freq.size() == (LENGTH - start)) ? true : false;
    }
};

// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/

/*
### 문제: 배열 요소를 고유하게 만들기 위한 최소 작업 수

정수 배열 `nums`가 주어집니다. 배열의 요소를 고유하게 만들어야 합니다. 이를 위해 다음 작업을 원하는 만큼 수행할 수 있습니다:

- 배열의 **앞에서 3개의 요소를 제거**합니다. 배열에 3개보다 적은 요소가 있다면, 남아 있는 모든 요소를 제거합니다.

빈 배열은 고유한 요소를 가진 것으로 간주합니다. 배열의 요소를 고유하게 만들기 위해 필요한 최소 작업 수를 반환하세요.

---

### 예제

#### 예제 1:
**입력**:  
`nums = [1,2,3,4,2,3,3,5,7]`  
**출력**:  
`2`  

**설명**:  
1. 첫 번째 작업에서 앞의 3개의 요소를 제거하면 배열은 `[4, 2, 3, 3, 5, 7]`가 됩니다.  
2. 두 번째 작업에서 다음 3개의 요소를 제거하면 배열은 `[3, 5, 7]`가 됩니다. 이 배열은 고유한 요소를 가지고 있습니다.  
총 작업 수는 2입니다.

---

#### 예제 2:
**입력**:  
`nums = [4,5,6,4,4]`  
**출력**:  
`2`  

**설명**:  
1. 첫 번째 작업에서 앞의 3개의 요소를 제거하면 배열은 `[4, 4]`가 됩니다.  
2. 두 번째 작업에서 남은 모든 요소를 제거하면 배열은 비어 있습니다.  
총 작업 수는 2입니다.

---

#### 예제 3:
**입력**:  
`nums = [6,7,8,9]`  
**출력**:  
`0`  

**설명**:  
배열은 이미 고유한 요소로 이루어져 있으므로 작업이 필요하지 않습니다.

---

### 제한 사항:
- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`
*/
