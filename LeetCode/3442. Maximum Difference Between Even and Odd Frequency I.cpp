class Solution 
{
public:
    int maxDifference(const string &s) 
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);
        
        unordered_map<char, int> charFrequency;
        for (const char ch : s)
        {
            assert('a' <= ch && ch <= 'z');
            ++charFrequency[ch];
        }
        
        int oddMin = numeric_limits<int>::max();
        int oddMax = numeric_limits<int>::min();
        int evenMin = numeric_limits<int>::max();
        int evenMax = numeric_limits<int>::min();
        
        for (const auto& [character, frequency] : charFrequency)
        {
            if (frequency % 2 == 0)
            {
                evenMin = min(evenMin, frequency);
                evenMax = max(evenMax, frequency);
            }
            else // 홀수 빈도
            {
                oddMin = min(oddMin, frequency);
                oddMax = max(oddMax, frequency);
            }
        }

        const int diffCandidate1 = oddMin  - evenMin;
        const int diffCandidate2 = oddMin  - evenMax;
        const int diffCandidate3 = oddMax  - evenMin;
        const int diffCandidate4 = oddMax  - evenMax;
        
        return max({diffCandidate1, diffCandidate2, diffCandidate3, diffCandidate4});
    }

private:
    enum Constraint 
    {
        MIN_LENGTH = 3,
        MAX_LENGTH = 100
    };
};

 https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/

 
/*
다음은 문제 원문을 그대로 국문으로 번역한 내용입니다.

---

**3442. 짝수 빈도와 홀수 빈도 사이의 최대 차이 I**  
Easy  
Hint

소문자 영문자로만 구성된 문자열 **s**가 주어집니다.  
당신의 작업은 문자열 내에서 두 문자의 빈도 차이가 최대가 되도록 하는 문자 쌍을 찾는 것입니다. 단, 조건은 다음과 같습니다:

- 한 문자는 문자열에서 **짝수** 번 등장해야 합니다.
- 다른 문자는 문자열에서 **홀수** 번 등장해야 합니다.

반환 값은 **홀수 빈도를 가진 문자**의 빈도에서 **짝수 빈도를 가진 문자**의 빈도를 뺀 값으로 계산된 최대 차이입니다.

---

**Example 1:**

```
Input: s = "aaaaabbc"
Output: 3
```

*Explanation:*  
문자 'a'는 홀수 빈도인 5번 등장하고, 문자 'b'는 짝수 빈도인 2번 등장합니다.  
따라서 최대 차이는 5 - 2 = 3입니다.

---

**Example 2:**

```
Input: s = "abcabcab"
Output: 1
```

*Explanation:*  
문자 'a'는 홀수 빈도인 3번 등장하고, 문자 'c'는 짝수 빈도인 2번 등장합니다.  
따라서 최대 차이는 3 - 2 = 1입니다.

---

**Constraints:**

- 3 <= s.length <= 100  
- s는 소문자 영문자로만 구성되어 있습니다.  
- s에는 최소 하나 이상의 홀수 빈도 문자가 존재하며, 동시에 최소 하나 이상의 짝수 빈도 문자가 존재합니다.
*/
