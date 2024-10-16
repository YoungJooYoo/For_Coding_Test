class Solution 
{
public:
    int numberOfSpecialSubstrings(const string& s) 
    {
        const int n = s.size();
        int result = 0;
        int lastIndex[ALPHABET_LENGTH];

        for (size_t i = 0; i < ALPHABET_LENGTH; ++i)
        { 
            lastIndex[i] = -1;
        }
        
        int left = 0;
        for (int right = 0; right < n; ++right)
        {
            char currentChar = s[right];
            if (lastIndex[currentChar - 'a'] >= left) 
            {
                left = lastIndex[currentChar - 'a'] + 1; // 중복 문자가 발견되면, 왼쪽 포인터를 이동시킵니다.
            }
            lastIndex[currentChar - 'a'] = right; // 현재 문자의 인덱스를 업데이트합니다.
            result += (right - left + 1); // 현재 윈도우의 길이가 특별한 부분 문자열의 개수에 기여합니다.
        }
        
        return result;
    }

private:
    enum { ALPHABET_LENGTH = 26 };
};

// https://leetcode.com/problems/count-substrings-without-repeating-character/description/
/*

---

### 2743. 중복 문자가 없는 부분 문자열의 개수 세기
**중간 난이도**

**주제**

---

숫자나 기호가 아닌 소문자 영어 알파벳으로만 구성된 문자열 `s`가 주어집니다. 우리는 어떤 부분 문자열이 **특별한 부분 문자열**이라고 부르는데, 이는 부분 문자열 내에 동일한 문자가 두 번 이상 등장하지 않는 경우를 말합니다(즉, 반복 문자가 없는 경우). 여러분의 목표는 특별한 부분 문자열의 개수를 세는 것입니다. 예를 들어, 문자열 `"pop"`에서 부분 문자열 `"po"`는 특별한 부분 문자열이지만, `"pop"`은 `'p'`가 두 번 등장했기 때문에 특별하지 않습니다.

특별한 부분 문자열의 개수를 반환하세요.

**부분 문자열**이란 문자열 내에서 연속된 문자들의 시퀀스를 말합니다. 예를 들어, `"abc"`는 `"abcd"`의 부분 문자열이지만, `"acd"`는 부분 문자열이 아닙니다.

#### 예제 1:

```
입력: s = "abcd"
출력: 10
```

**설명:**
각 문자가 한 번씩만 등장하기 때문에 모든 부분 문자열이 특별한 부분 문자열입니다. 길이 1의 부분 문자열이 4개, 길이 2의 부분 문자열이 3개, 길이 3의 부분 문자열이 2개, 길이 4의 부분 문자열이 1개 있습니다. 따라서 총 4 + 3 + 2 + 1 = 10개의 특별한 부분 문자열이 존재합니다.

#### 예제 2:

```
입력: s = "ooo"
출력: 3
```

**설명:**
길이가 2 이상인 모든 부분 문자열에는 반복 문자가 포함되어 있습니다. 따라서 길이 1의 부분 문자열만 세어야 하며, 이는 3개입니다.

#### 예제 3:

```
입력: s = "abab"
출력: 7
```

**설명:**
특별한 부분 문자열은 다음과 같습니다(시작 위치별로 정렬됨):

- 길이 1의 특별한 부분 문자열: "a", "b", "a", "b"
- 길이 2의 특별한 부분 문자열: "ab", "ba", "ab"

길이가 3 이상인 특별한 부분 문자열은 존재하지 않으므로, 정답은 4 + 3 = 7입니다.

#### 제약 사항:

- `1 <= s.length <= 10^5`
- `s`는 소문자 영어 알파벳으로만 구성됩니다.

---

도움이 되었기를 바랍니다! 추가로 번역이 필요한 내용이 있으면 언제든지 말씀해주세요.

*/
