class Solution 
{
public:
    int maximumMatchingIndices(vector<int>& nums1, const vector<int>& nums2) 
    {
        assert(MIN_LENGTH <= nums1.size() && nums1.size() <= MAX_LENGTH);

        const size_t originalNums1Length = nums1.size();
        const size_t nums2Length = nums2.size();
        int maxMatchingCount = 0;

        nums1.insert(nums1.end(), nums1.begin(), nums1.end());
        assert(MIN_LENGTH <= nums2Length && nums2Length <= MAX_LENGTH);

        for (size_t i = 0; i < originalNums1Length; ++i)
        {
            assert(MIN_VALUE <= nums1[i] && nums1[i] <= MAX_VALUE);
            int shiftMatchCount = 0;
            for (size_t j = 0, k = i; j < nums2Length; ++j, ++k)
            {
                assert(MIN_VALUE <= nums2[j] && nums2[j] <= MAX_VALUE);
                if (nums1[k] == nums2[j])
                {
                    ++shiftMatchCount;         
                }
            }
            maxMatchingCount = max(maxMatchingCount, shiftMatchCount);
        }
        
        assert(maxMatchingCount >= 0);
        return maxMatchingCount;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 3000,
        MIN_VALUE = 1,
        MAX_VALUE = 1000000000
    };
};

// https://leetcode.com/problems/maximum-number-of-matching-indices-after-right-shifts/description/

/*

### **3400. 오른쪽 이동 후 최대 일치하는 인덱스 수 구하기**  

---

### **문제 설명**  
두 개의 정수 배열 `nums1`과 `nums2`가 주어집니다.  
이 두 배열은 **길이가 동일**합니다.  

- 인덱스 `i`가 **매칭(matching)** 되려면 `nums1[i] == nums2[i]`가 되어야 합니다.
- `nums1`을 **오른쪽으로 여러 번 이동(right shift)** 할 수 있습니다.
- **오른쪽 이동(right shift)** 은 **각 요소를 한 칸씩 오른쪽으로 밀고, 마지막 요소를 맨 앞으로 이동**시키는 연산입니다.

이때, **오른쪽 이동을 임의로 수행한 후 최대 몇 개의 인덱스가 매칭될 수 있는지 반환**하세요.

---

### **입출력 예제**

#### **예제 1**
**입력**:
```plaintext
nums1 = [3,1,2,3,1,2]
nums2 = [1,2,3,1,2,3]
```
**출력**:
```plaintext
6
```
**설명**:  
- `nums1`을 **오른쪽으로 2번 이동**하면 `[1,2,3,1,2,3]`이 됩니다.  
- 이 경우, **모든 인덱스(0~5)가 일치**하므로 **정답은 6**입니다.

---

#### **예제 2**
**입력**:
```plaintext
nums1 = [1,4,2,5,3,1]
nums2 = [2,3,1,2,4,6]
```
**출력**:
```plaintext
3
```
**설명**:
- `nums1`을 **오른쪽으로 3번 이동**하면 `[5,3,1,1,4,2]`가 됩니다.
- 이때, **인덱스 1, 2, 4가 일치**하므로, 정답은 **3**입니다.

---

### **제약 조건**
1. `nums1.length == nums2.length`
2. `1 <= nums1.length, nums2.length <= 3000`
3. `1 <= nums1[i], nums2[i] <= 10^9`

---

### **풀이 아이디어**
1. **배열 `nums1`을 오른쪽으로 이동하면서 비교**:
   - 최대 `n-1`번까지 이동하며 `nums1`과 `nums2`의 매칭 인덱스 수를 계산.
   - `O(n^2)` 방식으로 하면 시간 초과 가능 → **효율적인 방법 필요**.

2. **효율적인 접근 (원형 배열 특징 활용)**:
   - `nums1`을 **한 번만 두 배로 확장하여 원형 배열처럼 사용**.
   - `nums1`을 `[nums1 + nums1]` 형태로 확장한 뒤, `nums2`와 비교하면서 가장 많이 일치하는 경우를 찾음.
   - **`O(n)`** 시간 복잡도로 해결 가능. 🚀


*/
