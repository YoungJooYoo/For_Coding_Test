class Solution 
{
public:
    int punishmentNumber(const int n) 
    {
        assert(n >= MIN_N && n <= MAX_N);

        int result = 0;
        
        for (int i = 1; i <= n; ++i)
        {
            const int square = (i * i);
            if (canPartitionRecursive(square, i) == true)
            {
                result += square;
            }
        }
        
        return result;
    }

private:
    bool canPartitionRecursive(int square, const int target) const
    {
        assert(square >= 0);

        vector<int> digits;
        
        while (square > 0) // square의 자릿수를 추출 (역순으로 저장되므로 나중에 reverse)
        {
            digits.push_back(square % 10);
            square /= 10;
        }
        reverse(digits.begin(), digits.end());

        return dfsPartitionRecursive(digits, 0, 0, target) ? true : false;
    }
    
    bool dfsPartitionRecursive(const vector<int>& digits, const int index, const int currentSum, const int target) const
    {
        if (index == digits.size())
        {
            return (currentSum == target) ? true : false;
        }
        
        int segmentValue = 0;
        for (int j = index; j < digits.size(); ++j)
        {
            segmentValue = (segmentValue * 10) + digits[j];
            if (dfsPartitionRecursive(digits, j + 1, currentSum + segmentValue, target) == true)
            {
                return true;
            }
        }

        return false;
    }

private:
    enum 
    { 
        MIN_N = 1, 
        MAX_N = 1000 
    };
};

// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/?envType=daily-question&envId=2025-02-15

/*
다음은 문제 원문을 그대로 한국어로 번역한 내용입니다.

---

**2698. 정수의 Punishment Number 찾기**  
*Medium*  
*Topics*  
*Companies*  
*Hint*

양의 정수 **n**이 주어질 때, **n**의 punishment number를 반환하세요.

**Punishment number**는 다음 조건을 만족하는 모든 정수 **i** (1 ≤ i ≤ n)의 제곱 값을 모두 더한 값으로 정의됩니다:

- **i**의 제곱 **(i * i)**의 십진수 표현을 연속된 부분 문자열로 분할할 수 있으며, 이 분할된 각 부분 문자열을 정수로 변환한 값들의 합이 **i**와 동일해야 합니다.

---

**예제 1:**

- **입력:** n = 10  
- **출력:** 182  
- **설명:**  
  [1, 10] 범위 내에서 조건을 만족하는 정수 **i**는 정확히 3개입니다.
  - **1**: 1 * 1 = 1  
  - **9**: 9 * 9 = 81 → "81"을 "8"과 "1"로 분할하면, 8 + 1 = 9  
  - **10**: 10 * 10 = 100 → "100"을 "10"과 "0"으로 분할하면, 10 + 0 = 10  
  따라서, punishment number는 1 + 81 + 100 = 182입니다.

---

**예제 2:**

- **입력:** n = 37  
- **출력:** 1478  
- **설명:**  
  [1, 37] 범위 내에서 조건을 만족하는 정수 **i**는 정확히 4개입니다.
  - **1**: 1 * 1 = 1  
  - **9**: 9 * 9 = 81 → "81"을 "8"과 "1"로 분할하면, 8 + 1 = 9  
  - **10**: 10 * 10 = 100 → "100"을 "10"과 "0"으로 분할하면, 10 + 0 = 10  
  - **36**: 36 * 36 = 1296 → "1296"을 "1", "29", "6"으로 분할하면, 1 + 29 + 6 = 36  
  따라서, punishment number는 1 + 81 + 100 + 1296 = 1478입니다.

---

**제약 조건:**

- 1 ≤ n ≤ (제약 조건이 주어지지 않은 경우 생략)

---

*/
