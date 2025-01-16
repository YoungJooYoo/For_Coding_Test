class Combination 
{
public:
    explicit Combination(const int size)
        : mFactorial(size, 0)
    {
        mFactorial[0] = 1;
        for (int i = 1; i < size; ++i)
        {
            mFactorial[i] = (1LL * i * mFactorial[i - 1]) % MODULO;
        }
    }

    long long power(const long long base, const long long exp) const
    {
        long long result = 1;
        long long baseMod = base % MODULO;
        long long tempExp = exp;

        while (tempExp > 0)
        {
            if (tempExp % 2 == 1)
            {
                result = (result * baseMod) % MODULO;
            }
            baseMod = (baseMod * baseMod) % MODULO;
            tempExp /= 2;
        }

        return result;
    }

    long long modularInverse(const long long n) const
    {
        return power(n, MODULO - 2);
    }

    long long nCr(const long long n, const long long k) const
    {
        if (k > n)
        {
            return 0;
        }
        
        return mFactorial[n] * modularInverse((mFactorial[k] * mFactorial[n - k]) % MODULO) % MODULO;
    }

private:
    vector<long long> mFactorial;

    enum
    {
        MODULO = 1000000000 + 7,
    };

};

class Solution 
{
public:
    int countGoodSubsequences(const string& s) const
    {
        vector<int> frequency(ALPHABET_LENGTH, 0);
        for (const char c : s)
        {
            ++frequency[c - 'a'];
        }

        const int maxFrequency = *max_element(frequency.begin(), frequency.end());
        const Combination comb(maxFrequency + 1);
        long long result = 0;

        for (int k = 1; k <= maxFrequency; ++k)
        {
            long long product = 1;

            for (const int count : frequency)
            {
                if (count >= k)
                {
                    product *= (1 + comb.nCr(count, k));
                    product %= MODULO;
                }
            }

            result += product;
            result %= MODULO;
        }

        return static_cast<int>((result - maxFrequency + MODULO) % MODULO);
    }

private:
    enum
    {
        ALPHABET_LENGTH = 26,
        MODULO = 1000000000 + 7,
    };
};

// https://leetcode.com/problems/count-the-number-of-good-subsequences/description/

/*
다음은 LeetCode 문제 **2539. Count the Number of Good Subsequences**의 번역입니다.

---

## **문제 설명**

문자열의 부분 수열(Subsequence)이 다음 조건을 만족하면 "좋은 부분 수열(Good Subsequences)"로 정의됩니다:
1. 비어 있지 않으며,
2. 각 문자(character)의 빈도수가 동일합니다.

문자열 `s`가 주어질 때, 좋은 부분 수열의 개수를 구하세요.  
답이 너무 클 수 있으므로 \(10^9 + 7\)로 나눈 나머지를 반환하세요.

부분 수열(Subsequence)이란, 원래 문자열에서 몇 개의 문자를 삭제하거나 삭제하지 않으면서 남은 문자들의 순서를 유지하여 만들어진 문자열을 말합니다.

---

## **예제**

### **예제 1**
- **입력:**  
  `s = "aabb"`  
- **출력:**  
  `11`
- **설명:**  
  `s`의 모든 부분 수열 개수는 24개입니다.  
  이 중 다음과 같은 5개의 부분 수열은 "좋지 않은 부분 수열"입니다:  
  - "aabb", "aabb", "aabb", "aabb", 빈 부분 수열.  
  따라서 좋은 부분 수열의 개수는 \(24 - 5 = 11\)입니다.

---

### **예제 2**
- **입력:**  
  `s = "leet"`  
- **출력:**  
  `12`
- **설명:**  
  "leet"에서 좋지 않은 부분 수열은 다음과 같습니다:  
  - "leet", "leet", "leet", 빈 부분 수열.  
  따라서 좋은 부분 수열의 개수는 \(24 - 4 = 12\)입니다.

---

### **예제 3**
- **입력:**  
  `s = "abcd"`  
- **출력:**  
  `15`
- **설명:**  
  "abcd"의 모든 비어 있지 않은 부분 수열은 좋은 부분 수열입니다.  
  \(2^4 - 1 = 15\)

---

## **제약 조건**
- \( 1 \leq s.length \leq 10^4 \)
- \( s \)는 소문자 영어 알파벳으로만 구성됩니다.

---

좋은 부분 수열의 정의를 따라가며, \(10^9 + 7\)로 나눈 나머지를 반환해야 합니다. 구현이 필요하면 알려주세요! 😊
*/
