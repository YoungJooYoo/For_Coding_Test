class Solution 
{
public:
    bool checkPowersOfThree(int n) 
    {
        while (n > 0)
        {
            const int digit = n % 3;
            if (digit == 2)
            {
                return false;
            }
            n /= 3;
        }
        
        return true;
    }
};

// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/?envType=daily-question&envId=2025-03-04

/*


**1780. 3의 거듭제곱의 합으로 표현 가능한지 확인하기**  
*Medium*  
*Topics*  
*Hint*

정수 **n**이 주어질 때, **n**을 서로 다른 3의 거듭제곱들의 합으로 표현할 수 있으면 **true**를, 그렇지 않으면 **false**를 반환하세요.

여기서, 정수 **y**가 3의 거듭제곱이라는 것은, 어떤 정수 **x**가 존재하여 \(y = 3^x\)가 되는 경우를 의미합니다.

---

**예제 1:**

- **입력:** n = 12  
- **출력:** true  
- **설명:** 12는 \(3^1 + 3^2 = 3 + 9\)로 표현할 수 있습니다.

---

**예제 2:**

- **입력:** n = 91  
- **출력:** true  
- **설명:** 91은 \(3^0 + 3^2 + 3^4 = 1 + 9 + 81\)로 표현할 수 있습니다.

---

**예제 3:**

- **입력:** n = 21  
- **출력:** false

---

**제약 조건:**

- \(1 \le n \le 10^7\)

---

**힌트 1:**  
풀이에서 사용할 최대 3의 거듭제곱은 \(3^{16}\)입니다.

**힌트 2:**  
만약 n의 3진법 표현에 2가 포함되어 있다면, n은 3의 거듭제곱들의 합으로 표현될 수 없습니다.
*/
