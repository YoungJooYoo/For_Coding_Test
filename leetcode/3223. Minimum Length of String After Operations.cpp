class Solution
{
public:
    int minimumLength(const string& s) const
    {
        assert(MIN_LEN <= s.size() && s.size() <= MAX_LEN);

        int freq[ALPHA] = {0, };
        size_t result = 0;

        for (const char ch : s)
        {
            assert(islower(static_cast<unsigned char>(ch)));
            ++freq[ch - 'a'];
        }

        for (size_t i = 0; i < ALPHA; ++i)
        {
            const int f = freq[i];
            if (f > 0)
            {
               result += (f % 2 == 0) ? 2 : 1; // f가 짝수면 2, 홀수면 1 남김
            }
        }

        assert(result >= 1);
        return static_cast<int>(result);
    }

private:
    enum
    {
        MIN_LEN = 1,
        MAX_LEN = 200000,
        ALPHA = 26
    };
};


// https://leetcode.com/problems/minimum-length-of-string-after-operations/

/*


## 3223. 연산 후 문자열의 최소 길이

**난이도:** Medium

---

### 문제 설명

문자열 `s`가 주어집니다.

다음 과정을 **원하는 만큼 반복**할 수 있습니다.

1. 문자열에서 인덱스 `i`를 하나 선택합니다.
   단, `s[i]`와 같은 문자가 **`i`의 왼쪽**에도 **적어도 하나**, **`i`의 오른쪽**에도 **적어도 하나** 존재해야 합니다.
2. `i`의 **왼쪽에서 가장 가까운** `s[i]` 문자를 삭제합니다.
3. `i`의 **오른쪽에서 가장 가까운** `s[i]` 문자를 삭제합니다.

이 과정을 거친 뒤, 만들 수 있는 문자열 `s`의 **최소 길이**를 반환하세요.

---

### 예시

#### 예시 1

```
입력: s = "abaacbcbb"
출력: 5
```

**설명:**

* 인덱스 `2` 선택 (`s[2] = 'a'`)
  → 왼쪽에서 가장 가까운 'a' (`인덱스 0`)와
  오른쪽에서 가장 가까운 'a' (`인덱스 3`)를 삭제
  → 결과: `"bacbcbb"`
* 인덱스 `3` 선택 (`s[3] = 'b'`)
  → 왼쪽에서 가장 가까운 'b' (`인덱스 0`)와
  오른쪽에서 가장 가까운 'b' (`인덱스 5`)를 삭제
  → 결과: `"acbcb"`
* 최종 길이 = 5

---

#### 예시 2

```
입력: s = "aa"
출력: 2
```

**설명:**

* 어떤 인덱스도 조건을 만족하지 않으므로 연산 불가
* 원래 문자열 길이(2) 반환

---

### 제약 조건

* 1 <= s.length <= 200,000
* `s`는 오직 소문자 영어 알파벳으로만 구성됨


*/
