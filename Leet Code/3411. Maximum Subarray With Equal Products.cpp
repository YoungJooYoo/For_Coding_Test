class Solution 
{
public:
    int maxLength(const vector<int>& nums) 
    {
        const int LENGTH = nums.size();
        int maxLength = 0;

        for (int start = 0; start < LENGTH; ++start) 
        {
            unsigned long long prod = 1;           // 곱 초기화
            int currentGCD = nums[start]; // 첫 번째 값으로 GCD 초기화
            int currentLCM = nums[start]; // 첫 번째 값으로 LCM 초기화

            for (int end = start; end < LENGTH; ++end) // 부분 배열을 확장하면서 곱, GCD, LCM 갱신
            {
                prod *= nums[end];
                currentGCD = gcd(currentGCD, nums[end]);
                currentLCM = (currentLCM / gcd(currentLCM, nums[end])) * nums[end];

                if (prod == currentGCD * currentLCM) // 조건 확인: prod == GCD * LCM
                {
                    maxLength = max(maxLength, end - start + 1);
                }
            }
        }

        return maxLength;
    }

private:
    int gcd(int a, int b) const
    {
        while (b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
};

// https://leetcode.com/problems/maximum-subarray-with-equal-products/description/

/*
### **3411. 곱이 동일한 최대 부분 배열 (Maximum Subarray With Equal Products)**  
**난이도**: Easy  

---

### **문제 설명**

양의 정수로 이루어진 배열 `nums`가 주어집니다.  

**배열 arr**는 다음 조건을 만족할 때 **곱이 동일한 배열(product equivalent)**이라고 합니다:
- \( \text{prod}(arr) = \text{lcm}(arr) \times \text{gcd}(arr) \),
  - 여기서:
    - \( \text{prod}(arr) \): 배열 `arr`의 모든 요소의 곱.
    - \( \text{gcd}(arr) \): 배열 `arr`의 모든 요소의 최대공약수(GCD).
    - \( \text{lcm}(arr) \): 배열 `arr`의 모든 요소의 최소공배수(LCM).

주어진 배열 `nums`에서 **곱이 동일한 가장 긴 연속 부분 배열(subarray)**의 길이를 반환하세요.

- **부분 배열(subarray)**은 배열 내에서 연속적이고 비어 있지 않은 요소들의 나열입니다.

---

### **예제**

#### 예제 1:
- **입력**:  
  \( \text{nums} = [1,2,1,2,1,1,1] \)
- **출력**:  
  \( 5 \)
- **설명**:  
  가장 긴 곱이 동일한 부분 배열은 `[1, 2, 1, 1, 1]`입니다.  
  - \( \text{prod}([1, 2, 1, 1, 1]) = 2 \),
  - \( \text{gcd}([1, 2, 1, 1, 1]) = 1 \),
  - \( \text{lcm}([1, 2, 1, 1, 1]) = 2 \).

---

#### 예제 2:
- **입력**:  
  \( \text{nums} = [2,3,4,5,6] \)
- **출력**:  
  \( 3 \)
- **설명**:  
  가장 긴 곱이 동일한 부분 배열은 `[3, 4, 5]`입니다.

---

#### 예제 3:
- **입력**:  
  \( \text{nums} = [1,2,3,1,4,5,1] \)
- **출력**:  
  \( 5 \)

---

### **제약 조건**

1. \( 2 \leq \text{nums.length} \leq 100 \)
2. \( 1 \leq \text{nums}[i] \leq 10 \)

---

### **용어 정의**

1. **최대공약수(GCD)**:
   - 두 정수의 공통된 약수 중 가장 큰 값을 의미합니다.
   - 예: \( \text{gcd}(12, 18) = 6 \).

2. **최소공배수(LCM)**:
   - 두 정수의 공통된 배수 중 가장 작은 값을 의미합니다.
   - 예: \( \text{lcm}(12, 18) = 36 \).

---

### **문제 풀이 힌트**

1. **문제의 핵심**:
   - \( \text{prod}(arr) = \text{lcm}(arr) \times \text{gcd}(arr) \) 조건을 만족하는지 확인해야 합니다.

2. **효율적인 계산**:
   - 연속 부분 배열에 대해 \( \text{prod}, \text{gcd}, \text{lcm} \)을 효율적으로 계산하는 방법이 필요합니다.
   - \( \text{gcd} \)와 \( \text{lcm} \)은 공식을 사용해 빠르게 계산할 수 있습니다:
     - \( \text{lcm}(a, b) = \frac{a \times b}{\text{gcd}(a, b)} \).

3. **부분 배열 순회**:
   - \( O(N^2) \) 또는 \( O(N^3) \) 알고리즘으로 모든 부분 배열을 검사하는 방법이 가능합니다(문제 크기가 작기 때문).

4. **최적화 가능성**:
   - \( \text{prod}, \text{gcd}, \text{lcm} \)을 중간 계산 값으로 캐싱하거나, 배열을 슬라이딩 윈도우로 처리해 최적화할 수 있습니다.
*/
