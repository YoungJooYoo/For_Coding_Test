class Solution 
{
public:
    int lengthAfterTransformations(const string& s, const int t) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);
        assert(MIN_LENGTH <= t && t <= MAX_LENGTH);

        vector<long long> freq(ALPHABET_LENGTH, 0LL); // 초기 문자 빈도 계산
        for (const char ch : s)
        {
            const size_t idx = ch - 'a';
            freq[idx] = (freq[idx] + 1) % MOD;
        }

        for (int step = 0; step < t; ++step) // t번 변환 수행 (O(26) each)
        {
            vector<long long> next(ALPHABET_LENGTH, 0LL);
            for (int i = 0; i < ALPHABET_LENGTH - 1; ++i) // 'a'..'y'는 다음 문자로 이동
            {
                next[i + 1] = (next[i + 1] + freq[i]) % MOD;
            }
            const long long zCount = freq[ALPHABET_LENGTH - 1]; // 'z'는 "ab"로 쪼개짐
            next[0] = (next[0] + zCount) % MOD;
            next[1] = (next[1] + zCount) % MOD;
            freq = next;
        }

        long long total = 0;  // 최종 길이 합산
        for (const long long c : freq)
        {
            total += c;
            total %= MOD;
        }

        return static_cast<int>(total);
    }

private:
    enum
    {
        ALPHABET_LENGTH = 26,
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MOD = 1000000000 + 7
    };
};

// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13

/*


**3335. 변환 후 문자열의 총 문자 수 I**  
난이도: 중간

주제: 문자열, 변환, 반복

---

문자열 `s`와 정수 `t`가 주어집니다. 
`t`는 수행할 변환 횟수를 나타냅니다. 한 번의 변환에서 문자열 `s`의 모든 문자는 다음 규칙에 따라 변환됩니다:

- 문자가 `'z'`인 경우, 문자열 `"ab"`로 교체합니다.
- 그렇지 않은 경우, 알파벳에서 다음 문자로 교체합니다. 
예를 들어, `'a'`는 `'b'`로, `'b'`는 `'c'`로 교체되며, 
이러한 방식으로 진행됩니다.

`t`번의 변환 후에 결과 문자열의 길이를 반환하세요.

결과가 매우 클 수 있으므로, `10^9 + 7`로 나눈 나머지를 반환하세요.

---

### 예제 1:

입력: 
```
s = "abcyy", t = 2
```
출력: 
```
7
```
설명:

- 첫 번째 변환 (t = 1):
  - `'a'`는 `'b'`로
  - `'b'`는 `'c'`로
  - `'c'`는 `'d'`로
  - `'y'`는 `'z'`로
  - `'y'`는 `'z'`로
  - 변환 후 문자열: `"bcdzz"`
  
- 두 번째 변환 (t = 2):
  - `'b'`는 `'c'`로
  - `'c'`는 `'d'`로
  - `'d'`는 `'e'`로
  - `'z'`는 `"ab"`로
  - `'z'`는 `"ab"`로
  - 변환 후 문자열: `"cdeabab"`

- 최종 문자열의 길이: `"cdeabab"`이며, 총 7개의 문자를 가집니다.

### 예제 2:

입력: 
```
s = "azbk", t = 1
```
출력: 
```
5
```
설명:

- 첫 번째 변환 (t = 1):
  - `'a'`는 `'b'`로
  - `'z'`는 `"ab"`로
  - `'b'`는 `'c'`로
  - `'k'`는 `'l'`로
  - 변환 후 문자열: `"babcl"`

- 최종 문자열의 길이: `"babcl"`이며, 총 5개의 문자를 가집니다.

---

### 제약 사항:

- `1 <= s.length <= 10^5`
- `s`는 소문자 영어 문자로만 구성됩니다.
- `1 <= t <= 10^5`

--- 

이 문제는 주어진 변환 규칙에 따라 여러 번 변환을 수행한 후 결과 문자열의 길이를 계산하는 문제입니다. 변환 과정에서 길이가 기하급수적으로 증가할 수 있으므로, 효율적으로 계산하는 방식이 필요합니다.
*/
