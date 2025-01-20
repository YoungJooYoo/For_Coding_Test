class Solution 
{
public:
    int subarraySum(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        int totalSum = 0;

        assert(MIN_LENGTH <= LENGTH && LENGTH <= MAX_LENGTH);

        for (int i = 0; i < LENGTH; ++i)
        {
            assert(MIN_VALUE <= nums[i] && nums[i] <= MAX_VALUE);
            const int start = max(0, i - nums[i]);
            const int sum = getSubArraySum(start, i, nums);
            totalSum += sum;
        }
        
        assert(totalSum > 0);
        return totalSum;
    }

private:
    int getSubArraySum(const int start, const int end, const vector<int>& nums)
    {
        int sum = 0;

        for (int i = start; i <= end; ++i)
        {
            sum += nums[i];
        }

        return sum;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VALUE = 1,
        MAX_VALUE = 1000
    };
};

// https://leetcode.com/problems/sum-of-variable-length-subarrays/

/*
### 문제 번역: 3427. 가변 길이 부분 배열의 합

---

**난이도**: 쉬움

---

### **문제 설명**

정수 배열 `nums`가 주어집니다. 이 배열의 크기는 `n`입니다.  
각 인덱스 `i`에 대해 \( 0 \leq i < n \)일 때, 다음과 같이 부분 배열을 정의합니다:

- 부분 배열: `nums[start ... i]`
- 여기서 \( start = \max(0, i - nums[i]) \)

각 인덱스에 대해 정의된 부분 배열의 모든 요소를 더한 값을 구한 뒤, 이 총합을 반환하세요.

---

### **예제**

#### **예제 1**
- **입력**:  
  `nums = [2, 3, 1]`
- **출력**:  
  `11`
- **설명**:

| \( i \) | 부분 배열 | 합 |
|---------|-----------|-----|
| 0       | nums[0] = [2] | 2 |
| 1       | nums[0 ... 1] = [2, 3] | 5 |
| 2       | nums[1 ... 2] = [3, 1] | 4 |
| **총합** |            | 11 |

따라서 결과는 `11`입니다.

---

#### **예제 2**
- **입력**:  
  `nums = [3, 1, 1, 2]`
- **출력**:  
  `13`
- **설명**:

| \( i \) | 부분 배열 | 합 |
|---------|-----------|-----|
| 0       | nums[0] = [3] | 3 |
| 1       | nums[0 ... 1] = [3, 1] | 4 |
| 2       | nums[1 ... 2] = [1, 1] | 2 |
| 3       | nums[1 ... 3] = [1, 1, 2] | 4 |
| **총합** |            | 13 |

따라서 결과는 `13`입니다.

---

### **제약 조건**
- \( 1 \leq n = \text{nums.length} \leq 100 \)
- \( 1 \leq \text{nums}[i] \leq 1000 \)  

---


*/
