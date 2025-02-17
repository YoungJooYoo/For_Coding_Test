class Solution 
{
public:
    bool hasSpecialSubstring(const string &s, const int k) const
    {
        assert(k >= MIN_K && k <= s.size());
        assert(s.size() >= MIN_LEN && s.size() <= MAX_LEN);
        
        const int n = s.size();
        
        assert(n - k >= 0);
        for (int i = 0; i <= n - k; i++)
        {
            const char c = s[i];
            bool bValid = true;
            for (int j = i + 1; j < i + k; j++)
            {
                if (s[j] != c)
                {
                    bValid = false;
                    break;
                }
            }

            if ((bValid == false) || (i > 0 && s[i - 1] == c) || (i + k < n && s[i + k] == c))
            {
                continue;
            }

            return true;
        }
        
        return false;
    }

private:
    enum
    {
        MIN_K   = 1,
        MIN_LEN = 1,
        MAX_LEN = 100
    };
};

// https://leetcode.com/problems/find-special-substring-of-length-k/description/

/*
다음은 문제 원문을 그대로 한국어로 번역한 내용입니다.

---

**3456. 길이가 k인 특수 부분 문자열 찾기**  
*Easy*  
*Hint*

문자열 **s**와 정수 **k**가 주어집니다.

문자열 **s**에서 다음 조건을 만족하는 길이가 정확히 **k**인 부분 문자열이 존재하는지 확인하세요:

- 해당 부분 문자열은 오직 한 종류의 문자로만 구성되어 있어야 합니다. (예: "aaa" 또는 "bbb")
- 부분 문자열 바로 앞에 문자가 존재한다면, 그 문자는 부분 문자열에 있는 문자와 달라야 합니다.
- 부분 문자열 바로 뒤에 문자가 존재한다면, 그 문자는 부분 문자열에 있는 문자와 달라야 합니다.

이와 같은 조건을 만족하는 부분 문자열이 존재하면 **true**를, 존재하지 않으면 **false**를 반환하세요.

---

**예제 1:**

```
입력: s = "aaabaaa", k = 3
출력: true
```

*설명:*

- 부분 문자열 s[4..6] = "aaa"는 길이가 3이며, 모든 문자가 'a'로 동일합니다.
- "aaa" 바로 앞의 문자는 'b'로, 'a'와 다릅니다.
- "aaa" 뒤에는 문자가 존재하지 않습니다.
  
따라서 조건을 만족합니다.

---

**예제 2:**

```
입력: s = "abc", k = 2
출력: false
```

*설명:*

- 길이가 2이면서 모든 문자가 동일한 부분 문자열이 없으므로, 조건을 만족하는 부분 문자열이 존재하지 않습니다.

---

**제약 조건:**

- 1 <= k <= s.length <= 100  
- s는 소문자 영어 알파벳으로만 구성되어 있습니다.
*/
