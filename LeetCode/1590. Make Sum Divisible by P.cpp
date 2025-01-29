class Solution 
{
public:
    int minSubarray(vector<int>& nums, const int divisor) 
    {
        unordered_map<int, int> remainderIndexMap;
        const int ARRAY_LENGTH = nums.size();
        int totalRemainder = 0;
        int minSubarrayLength = ARRAY_LENGTH;
        int runningSum = 0;

        assert(MIN_ARRAY_SIZE <= ARRAY_LENGTH && ARRAY_LENGTH <= MAX_ARRAY_SIZE);
        assert(MIN_DIVISOR <= divisor && divisor <= MAX_DIVISOR);

        remainderIndexMap[0] = FAILURE;
        for (const int num : nums) 
        {
            totalRemainder = (totalRemainder + num) % divisor;
        }
        if (totalRemainder == 0) 
        {
            return 0;
        }

        for (int i = 0; i < ARRAY_LENGTH; ++i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            const int currentSum = runningSum + nums[i];
            runningSum = currentSum % divisor;
            remainderIndexMap[runningSum] = i;
            const int adjustedModValue = runningSum - totalRemainder + divisor;
            const int targetRemainder = adjustedModValue % divisor;

            if (remainderIndexMap.count(targetRemainder)) 
            {
                const int subarrayLength = i - remainderIndexMap[targetRemainder];
                minSubarrayLength = min(minSubarrayLength, subarrayLength);
            }
        } 

        return (minSubarrayLength == ARRAY_LENGTH) ? FAILURE : minSubarrayLength;
    }

private:
    enum 
    {
        FAILURE = -1,
        MIN_ARRAY_SIZE = 1,   // 최소 배열 크기
        MAX_ARRAY_SIZE = 100000, // 최대 배열 크기
        MIN_NUM = 1,          // 최소 숫자 값
        MAX_NUM = 1000000000, // 최대 숫자 값
        MIN_DIVISOR = 1,      // 최소 나눌 값
        MAX_DIVISOR = 1000000000 // 최대 나눌 값
    };
};

// https://leetcode.com/problems/make-sum-divisible-by-p/description/

/*
### **1590. 합을 P로 나눌 수 있도록 만들기**  

---

### **문제 설명**  
양의 정수 배열 `nums`가 주어집니다.  
배열에서 **가장 작은 연속된 부분 배열(subarray)을 제거하여**, 남은 요소들의 합이 `p`로 나누어떨어지도록 만들고 싶습니다.  
**단, 전체 배열을 제거하는 것은 불가능합니다.**  

제거해야 하는 **가장 작은 부분 배열의 길이**를 반환하세요. 만약 불가능하다면 `-1`을 반환하세요.  

---

### **입출력 예제**  

#### **예제 1**  
**입력**:  
```plaintext
nums = [3,1,4,2], p = 6
```
**출력**:  
```plaintext
1
```
**설명**:  
- `nums`의 전체 합은 `10`으로, `6`으로 나누어떨어지지 않습니다.  
- `[4]`를 제거하면 남은 합은 `6`이 되어 `6`으로 나누어떨어집니다.  
- 따라서 **길이 1의 부분 배열**을 제거하면 됩니다.

---

#### **예제 2**  
**입력**:  
```plaintext
nums = [6,3,5,2], p = 9
```
**출력**:  
```plaintext
2
```
**설명**:  
- `nums`의 전체 합은 `16`이며, `9`로 나누어떨어지지 않습니다.  
- `[5,2]`를 제거하면 남은 합은 `9`가 되어 `9`로 나누어떨어집니다.  
- 따라서 **길이 2의 부분 배열**을 제거해야 합니다.

---

#### **예제 3**  
**입력**:  
```plaintext
nums = [1,2,3], p = 3
```
**출력**:  
```plaintext
0
```
**설명**:  
- `nums`의 전체 합은 `6`으로, 이미 `3`으로 나누어떨어집니다.  
- 따라서 **아무것도 제거할 필요가 없습니다.** (정답 `0`)

---

### **제약 조건**
1. `1 <= nums.length <= 10^5`  
2. `1 <= nums[i] <= 10^9`  
3. `1 <= p <= 10^9`

---

### **풀이 아이디어**
1. **누적 합(Prefix Sum) 사용**:  
   - 전체 합(`totalSum`)을 `p`로 나누어 나머지(`totalSum % p`)를 구합니다.
   - 제거해야 하는 부분 배열의 합(`subarraySum`)의 나머지가 `totalSum % p`와 같아야 합니다.

2. **해시맵(Hash Map) 활용**:  
   - `prefixSum % p` 값을 저장하고, `totalSum % p`와 일치하는 값을 빠르게 찾기 위해 해시맵을 사용합니다.

3. **최소 길이의 부분 배열 찾기**:  
   - 부분 배열의 시작과 끝을 조절하며 최소 길이를 찾습니다.

이 방법을 사용하면 **O(n)** 시간 복잡도로 효율적으로 해결할 수 있습니다. 🚀
*/
