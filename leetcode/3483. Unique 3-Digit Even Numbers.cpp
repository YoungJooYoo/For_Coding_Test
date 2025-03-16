class Solution 
{
public:
    int totalNumbers(const vector<int>& digits) const
    {
        assert(MIN_LENGTH <= digits.size() && digits.size() <= MAX_LENGTH);

        const size_t n = digits.size();
        unordered_set<int> uniqueEvenNumbers;

        for (size_t i = 0; i < n; ++i) 
        {
            assert(MIN_NUM <= digits[i] && digits[i] <= MAX_NUM);
            for (size_t j = 0; j < n; ++j) 
            {
                if (i == j) continue;
                for (size_t k = 0; k < n; ++k) 
                {
                    if (i == k || j == k) continue;
                    const string numberStr = { char(digits[i] + '0'), char(digits[j] + '0'), char(digits[k] + '0') };
                    const int number = stoi(numberStr);
                    if ((100 <= number && number <= 999) && number % 2 == 0)
                    {
                        uniqueEvenNumbers.insert(number);
                    }
                }
            }
        }

        return uniqueEvenNumbers.size();
    }

private:
    enum
    {
        MIN_NUM = 0,
        MAX_NUM = 9,
        MIN_LENGTH = 3,
        MAX_LENGTH = 10
    };
};


// https://leetcode.com/problems/unique-3-digit-even-numbers/description/

/*

**3483. 고유한 3자리 짝수**

**난이도:** 쉬움

**문제 설명:**  
정수로 이루어진 배열 **digits**가 주어집니다. 이 배열에 포함된 숫자들을 사용하여 만들 수 있는 서로 다른 3자리 짝수의 개수를 구하는 문제입니다.

**제약 사항:**

- 각 숫자는 한 숫자 당 한 번만 사용할 수 있습니다.
- 숫자를 재사용하려면 배열에 해당 숫자가 여러 번 존재해야 합니다.
- 3자리 수를 만들 때 맨 앞 자리에 0이 올 수 없습니다.

---

**예제 1:**

- **입력:** digits = [1,2,3,4]  
- **출력:** 12  
- **설명:**  
  만들 수 있는 12개의 고유한 3자리 짝수는 다음과 같습니다:  
  124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, 432.  
  예를 들어, 숫자 2는 배열에 한 번만 있으므로 222는 만들 수 없습니다.

---

**예제 2:**

- **입력:** digits = [0,2,2]  
- **출력:** 2  
- **설명:**  
  만들 수 있는 유일한 3자리 짝수는 202와 220입니다.  
  배열에 숫자 2가 두 번 있으므로 숫자 2를 두 번 사용할 수 있습니다.

---

**예제 3:**

- **입력:** digits = [6,6,6]  
- **출력:** 1  
- **설명:**  
  만들 수 있는 3자리 짝수는 666뿐입니다.

---

**예제 4:**

- **입력:** digits = [1,3,5]  
- **출력:** 0  
- **설명:**  
  짝수인 3자리 수를 만들 수 없습니다.

---

**제약 조건:**

- 3 <= digits.length <= 10  
- 0 <= digits[i] <= 9

---
*/
