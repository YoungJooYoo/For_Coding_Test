class Solution
{
public:
    bool validDigit(const int n, const int x) const
    {
        assert(MIN_N <= n && n <= MAX_N);
        assert(MIN_DIGIT <= x && x <= MAX_DIGIT);

        const string strNum = to_string(n);
        const char chX = static_cast<char>(x + '0');
        const unordered_set<char> charSet(strNum.begin(), strNum.end());

        return (strNum[0] == chX) || (charSet.find(chX) == charSet.end()) ? false : true;
    }

private:
    enum
    {
        MIN_N     = 0,
        MAX_N     = 100000,
        MIN_DIGIT = 0,
        MAX_DIGIT = 9,
    };
};
/*
## 문제 번역

**유효한 숫자 판별**

정수 `n`과 숫자(자릿수) `x`가 주어집니다.

아래 두 조건을 **모두** 만족하면 유효한 숫자입니다:

- `x`가 **최소 한 번 이상** 포함되어 있을 것
- `x`로 **시작하지 않을** 것

`n`이 유효하면 `true`, 아니면 `false`를 반환하세요.

---

**예시 1**
- 입력: `n = 101`, `x = 0`
- 출력: `true`
- 설명: `0`이 인덱스 1에 존재하고, `1`로 시작하므로 두 조건 모두 만족 ✅

**예시 2**
- 입력: `n = 232`, `x = 2`
- 출력: `false`
- 설명: `2`로 시작하므로 조건 위반 ❌

**예시 3**
- 입력: `n = 5`, `x = 1`
- 출력: `false`
- 설명: `1`이 포함되어 있지 않으므로 조건 위반 ❌

---

**제약 조건**
- `0 <= n <= 10^5`
- `0 <= x <= 9`

---

## 요약

`n`을 문자열로 변환해서 **첫 글자가 `x`가 아니면서**, **`x`가 포함**되어 있는지 확인.

---

## 풀이 방향

1. `n`을 문자열로 변환
2. 첫 번째 문자가 `x`인지 확인 → `x`이면 즉시 `false`
3. 문자열 내에 `x`가 존재하는지 확인 → 없으면 `false`
4. 둘 다 통과하면 `true`


*/
