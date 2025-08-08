class Solution
{
public:
    int minFlips(const int a, const int b, const int c) const
    {
        assert(MIN_RANGE <= a && a <= MAX_RANGE);
        assert(MIN_RANGE <= b && b <= MAX_RANGE);
        assert(MIN_RANGE <= c && c <= MAX_RANGE);

        const string numberA = getStringBinary(a);
        const string numberB = getStringBinary(b);
        const string numberC = getStringBinary(c);

        const size_t lenA = numberA.size(); // 뒤(LSB)에서부터 한 비트씩 비교
        const size_t lenB = numberB.size();
        const size_t lenC = numberC.size();

        const size_t maxLen = max(lenA, max(lenB, lenC));
        int count = 0;

        for (size_t i = 0; i < maxLen; ++i)
        {
            const int aBit = (i < lenA) ? numberA[lenA - 1 - i] - '0' : 0;
            const int bBit = (i < lenB) ? numberB[lenB - 1 - i] - '0' : 0;
            const int cBit = (i < lenC) ? numberC[lenC - 1 - i] - '0' : 0;

            if (cBit == 1) // (aBit | bBit) 를 cBit로 만들기 위한 최소 뒤집기 수
            {
                if ((aBit | bBit) == 0) // 둘 다 0이면 1번 뒤집어야 함 (a 또는 b 중 하나를 1로)
                {
                    ++count;
                }
            }
            else // cBit == 0
            {
                count += aBit; // aBit, bBit 중 1인 개수만큼 0으로 내려야 함
                count += bBit;
            }
        }

        return count;
    }

private:
    string getStringBinary(int number) const
    {
        assert(number >= 1);

        string strBinary;

        while (number != 0)
        {
            const int bit = number % 2;
            strBinary.push_back(static_cast<char>(bit + '0'));
            number /= 2;
        }

        reverse(strBinary.begin(), strBinary.end());
        return strBinary;
    }

    enum
    {
        MIN_RANGE = 1,
        MAX_RANGE = 1000000000
    };
};


// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/

/*
---

## **1318. a OR b를 c와 같게 만들기 위한 최소 비트 뒤집기 횟수**

**난이도:** Medium
**주제:** 비트 조작

---

### **문제 설명**

세 개의 양의 정수 **a**, **b**, **c**가 주어집니다.
`(a OR b) == c`가 되도록 **a**와 **b**의 일부 비트를 뒤집는 최소 횟수를 구하세요.
여기서 `OR`은 **비트 단위 OR 연산**입니다.

비트 뒤집기(Flip) 연산이란, 어떤 비트의 값을 **1 → 0** 또는 **0 → 1**로 변경하는 것을 의미합니다.

---

### **예제**

#### 예제 1

```
입력: a = 2, b = 6, c = 5
출력: 3
설명:
a = 2  → 이진수 010
b = 6  → 이진수 110
c = 5  → 이진수 101

다음과 같이 3번의 비트 변경으로 (a OR b) == c를 만들 수 있습니다:
a = 1 (001), b = 4 (100) → (001 OR 100) == 101 (c)
```

#### 예제 2

```
입력: a = 4, b = 2, c = 7
출력: 1
```

#### 예제 3

```
입력: a = 1, b = 2, c = 3
출력: 0
```

이미 (a OR b) == c이므로 뒤집을 필요가 없습니다.

---

### **제약 조건**

* 1 <= a <= 10^9
* 1 <= b <= 10^9
* 1 <= c <= 10^9

---

💡 **힌트:**
비트를 하나씩 확인하면서 해당 비트를 뒤집을 필요가 있는지 판단하세요.

---


*/
