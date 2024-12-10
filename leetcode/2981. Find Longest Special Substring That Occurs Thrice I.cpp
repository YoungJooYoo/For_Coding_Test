class Solution 
{
public:
    int maximumLength(const string& s) 
    {
        const size_t LENGTH = s.length();
        int maxLength = FAIL;

        for (size_t subStrLen = 1; subStrLen <= LENGTH; ++subStrLen) // 모든 가능한 길이의 부분 문자열 탐색
        {
            std::unordered_map<std::string, int> substringCount;
            for (size_t i = 0; i + subStrLen <= LENGTH; ++i) // 길이 len의 부분 문자열을 탐색
            {
                const std::string sub = s.substr(i, subStrLen);
                if (isSpecial(sub) ==  true) // 특별한 문자열인지 확인
                {
                    ++substringCount[sub];
                }
            }

            for (const auto& [sub, count] : substringCount) // 등장 횟수가 3번 이상인 문자열 중 가장 긴 길이를 갱신
            {
                if (count >= MIN_COUNT) 
                {
                    maxLength = std::max(maxLength, static_cast<int>(sub.length()));
                }
            }
        }

        return maxLength;     
    }

private:
    bool isSpecial(const std::string& str) const 
    {
        const char firstChar = str[0];
        for (const char ch : str) 
        {
            if (ch != firstChar) 
            {
                return false;
            }
        }
        
        return true;
    }

    enum 
    { 
        FAIL = -1,
        MIN_COUNT = 3
    };
};

/*
**2981. 최소 3번 이상 등장하는 가장 긴 특별한 부분 문자열 찾기 I**  
난이도: 중간

---

**문제 설명**  
소문자로만 이루어진 문자열 `s`가 주어집니다.

**특별한 문자열**이란 단일 문자로만 이루어진 문자열을 의미합니다.  
예를 들어, 문자열 `"abc"`는 특별하지 않지만, 문자열 `"ddd"`, `"zz"`, `"f"`는 특별합니다.

문자열 `s`에서 **최소 3번 이상 등장하는 가장 긴 특별한 부분 문자열의 길이**를 반환하세요.  
만약 그러한 부분 문자열이 없다면 `-1`을 반환하세요.

**부분 문자열**은 문자열 내의 연속적인 문자들로 이루어진 비어 있지 않은 문자열입니다.

---

### **예제**

- **예제 1**:
  ```plaintext
  입력: s = "aaaa"
  출력: 2
  설명:
  최소 3번 이상 등장하는 가장 긴 특별한 부분 문자열은 "aa"입니다.  
  부분 문자열 `"aa"`는 `"aaaa"`, `"aaaa"`, `"aaaa"`에서 최소 3번 나타납니다.  
  최대로 가능한 길이는 2입니다.
  ```

- **예제 2**:
  ```plaintext
  입력: s = "abcdef"
  출력: -1
  설명:
  최소 3번 이상 등장하는 특별한 부분 문자열이 존재하지 않으므로 -1을 반환합니다.
  ```

- **예제 3**:
  ```plaintext
  입력: s = "abcaba"
  출력: 1
  설명:
  최소 3번 이상 등장하는 가장 긴 특별한 부분 문자열은 "a"입니다.  
  부분 문자열 `"a"`는 `"abcaba"`, `"abcaba"`, `"abcaba"`에서 최소 3번 나타납니다.  
  최대로 가능한 길이는 1입니다.
  ```

---

### **제약 사항**
- `3 <= s.length <= 50`
- `s`는 소문자로만 이루어져 있습니다.
*/
