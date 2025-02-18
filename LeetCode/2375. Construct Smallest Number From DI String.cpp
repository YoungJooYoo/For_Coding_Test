class Solution 
{
public:
    string smallestNumber(const string& pattern) 
    {
        assert(pattern.length() >= MIN_PATTERN_LENGTH && pattern.length() <= MAX_PATTERN_LENGTH);
    
        const size_t patternSize = pattern.size();
        stack<int> st;
        string result = "";
        
        for (size_t i = 0; i <= patternSize; i++)
        {
            st.push(i + 1);
            if (i == patternSize || pattern[i] == 'I')
            {
                while (!st.empty())
                {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        
        return result;  
    }

private:
    enum 
    {
        MIN_PATTERN_LENGTH = 1,
        MAX_PATTERN_LENGTH = 8
    };
};

// https://leetcode.com/problems/construct-smallest-number-from-di-string/description/?envType=daily-question&envId=2025-02-18


/*


**2375. DI 문자열로부터 가장 작은 수 구성하기**  
*Medium*  
*Topics*  
*Companies*  
*Hint*

문자 'I' (증가를 의미)와 'D' (감소를 의미)로 구성된 길이 n의 0-인덱스 문자열 **pattern**이 주어집니다.

아래 조건들을 만족하는 길이 n+1의 0-인덱스 문자열 **num**을 구성합니다:

- **num**은 '1'부터 '9'까지의 숫자로 구성되며, 각 숫자는 최대 한 번씩만 사용됩니다.
- 만약 **pattern[i]**가 'I'라면, **num[i] < num[i + 1]** 여야 합니다.
- 만약 **pattern[i]**가 'D'라면, **num[i] > num[i + 1]** 여야 합니다.

위 조건들을 만족하는 사전 순으로 가장 작은 문자열 **num**을 반환하세요.

---

**예제 1:**

```
입력: pattern = "IIIDIDDD"
출력: "123549876"
```

*설명:*  
- 인덱스 0, 1, 2, 4에서는 **num[i] < num[i+1]** 여야 합니다.  
- 인덱스 3, 5, 6, 7에서는 **num[i] > num[i+1]** 여야 합니다.  
- 가능한 **num**의 예로는 "245639871", "135749862", "123849765" 등이 있으며,  
  이 중 "123549876"이 조건을 만족하는 사전 순으로 가장 작은 수임이 증명됩니다.  
- "123414321"은 숫자 '1'이 여러 번 사용되어 불가능합니다.

---

**예제 2:**

```
입력: pattern = "DDD"
출력: "4321"
```

*설명:*  
- 가능한 **num**의 예로는 "9876", "7321", "8742" 등이 있으며,  
  이 중 "4321"이 조건을 만족하는 사전 순으로 가장 작은 수임이 증명됩니다.

---

**제약 조건:**

- 1 <= pattern.length <= 8  
- **pattern**은 문자 'I'와 'D'로만 구성되어 있습니다.
*/
