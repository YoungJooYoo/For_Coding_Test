class Solution 
{
public:
    int maxProduct(const int n) const
    {
        const string number = to_string(n);
        const size_t LENGTH = number.size();
        int result = numeric_limits<int>::min();

        assert(MIN_N <= n && n <= MAX_N);
        for (size_t i = 0; i < LENGTH; ++i)
        {
            for (size_t j = i + 1; j < LENGTH; ++j)
            {
                const int currNum = (number[i] - '0') * (number[j] - '0');
                result = max(result, currNum);
            }
        }

        assert(result != numeric_limits<int>::min());
        return result;
    }

private:
    enum
    {
        MIN_N = 10,
        MAX_N = 1000000000,
    };
};

// https://leetcode.com/problems/maximum-product-of-two-digits/description/

/*
**3536. 두 자리 숫자의 최대 곱**

**난이도:** 쉬움

**문제 설명:**  
양의 정수 **n**이 주어집니다.

정수 **n**의 각 자릿수 중 **서로 다른 두 자리(digit)**를 골라 그 곱을 계산할 때, 가능한 곱 중 **최댓값**을 반환하세요.  
단, 같은 자릿수가 **두 번 이상** 등장한다면, 동일한 숫자를 두 번 골라 곱해도 됩니다.

---

**예제 1:**

- **입력:** `n = 31`  
- **출력:** `3`  
- **설명:**  
  자릿수는 [3, 1]이고, 가능한 곱은 3×1 = 3이므로, 답은 3입니다.

---

**예제 2:**

- **입력:** `n = 22`  
- **출력:** `4`  
- **설명:**  
  자릿수는 [2, 2]이고, 가능한 곱은 2×2 = 4이므로, 답은 4입니다.

---

**예제 3:**

- **입력:** `n = 124`  
- **출력:** `8`  
- **설명:**  
  자릿수는 [1, 2, 4]이고, 가능한 곱은  
  1×2 = 2, 1×4 = 4, 2×4 = 8 중 최댓값이 8입니다.

---

**제약 조건:**

- 10 ≤ n ≤ 10^9
*/
