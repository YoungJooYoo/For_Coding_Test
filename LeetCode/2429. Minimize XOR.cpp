class Solution 
{
public:
    int minimizeXor(int num1, const int num2) 
    {
        assert(num1 >= MIN_VALUE && num1 <= MAX_VALUE);
        assert(num2 >= MIN_VALUE && num2 <= MAX_VALUE);

        const int targetOnes = __builtin_popcount(num2); // num2의 1 비트 개수

        // Step 1: num1에서 1 비트를 설정하며 목표 비트 수 맞추기
        while (__builtin_popcount(num1) < targetOnes) 
        {
            num1 |= (num1 + 1) & ~num1; // 가장 낮은 0 비트를 찾아 1로 설정
        }

        // Step 2: num1에서 1 비트를 제거하며 목표 비트 수 맞추기
        while (__builtin_popcount(num1) > targetOnes) 
        {
            num1 &= (num1 - 1); // 가장 낮은 1 비트를 0으로 설정
        }

        assert(num1 >= 0);
        return num1; 
    }

private:
    enum 
    {
        MIN_VALUE = 1,
        MAX_VALUE = 1000000000
    };
};

// https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15

/*
다음은 LeetCode 문제 **2429. Minimize XOR**의 번역입니다.

---

## **문제 설명**

두 개의 양의 정수 `num1`과 `num2`가 주어질 때, 다음 조건을 만족하는 양의 정수 `x`를 찾으세요:

1. `x`는 `num2`와 동일한 수의 1 비트(= set bits)를 가져야 합니다.
2. `x XOR num1`의 값이 최소가 되어야 합니다.  
   (여기서 XOR은 비트 단위 XOR 연산입니다.)

테스트 케이스는 항상 `x`가 유일하게 결정되도록 생성됩니다.

**힌트:**  
정수의 set bits는 이진 표현에서 1로 표시된 비트의 개수를 의미합니다.

---

## **예제**

### 예제 1
- **입력:**  
  `num1 = 3`, `num2 = 5`  
- **출력:**  
  `3`
- **설명:**  
  `num1`과 `num2`의 이진 표현은 각각 `0011`과 `0101`입니다.  
  정수 `3`은 `num2`와 동일한 수의 1 비트를 가지며, `3 XOR 3 = 0`으로 최소입니다.

---

### 예제 2
- **입력:**  
  `num1 = 1`, `num2 = 12`
- **출력:**  
  `3`
- **설명:**  
  `num1`과 `num2`의 이진 표현은 각각 `0001`과 `1100`입니다.  
  정수 `3`은 `num2`와 동일한 수의 1 비트를 가지며, `3 XOR 1 = 2`로 최소입니다.

---

## **제약 조건**
- \( 1 \leq num1, num2 \leq 10^9 \) 

---

위 문제를 해결하려면 `num2`의 1 비트 수를 먼저 계산한 후, `num1`을 기반으로 가능한 최소 XOR 값을 갖는 `x`를 생성해야 합니다. 필요하면 풀이 방향에 대한 힌트나 코드를 추가로 제공할 수 있습니다. 😊
*/
