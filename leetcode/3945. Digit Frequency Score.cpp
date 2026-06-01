class Solution
{
public:
    int digitFrequencyScore(const int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);

        const string strNum = to_string(n);
        unordered_map<int, int> digitFreq;

        for (const char ch : strNum)
        {
            const int digit = ch - '0';
            ++digitFreq[digit];
        }

        int score = 0;
        for (const auto& [digit, freq] : digitFreq)
        {
            score += digit * freq;
        }

        assert(score >= 0);
        return score;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 1000000000,
    };
};

/*
https://leetcode.com/problems/digit-frequency-score/




**3945. 숫자 빈도 점수**

정수 `n`이 주어집니다.

`n`의 점수는 모든 서로 다른 숫자(digit) `d`에 대해 `d × freq(d)`의 합으로 정의됩니다. 여기서 `freq(d)`는 숫자 `d`가 `n`에 등장하는 횟수입니다.

`n`의 점수를 반환하세요.

---

**예시 1**
- 입력: `n = 122`
- 출력: `5`
- 설명:
  - 숫자 1: 1회 등장 → `1 × 1 = 1`
  - 숫자 2: 2회 등장 → `2 × 2 = 4`
  - 점수 = `1 + 4 = 5`

**예시 2**
- 입력: `n = 101`
- 출력: `2`
- 설명:
  - 숫자 0: 1회 등장 → `0 × 1 = 0`
  - 숫자 1: 2회 등장 → `1 × 2 = 2`
  - 점수 = `0 + 2 = 2`

---

**제약 조건**
- `1 ≤ n ≤ 10^9`

---

## 요약

각 자릿수 `d`의 등장 횟수를 세고 `d × 횟수`를 합산.

---

## 풀이 방향

1. `n`을 문자열로 변환
2. 각 자릿수의 빈도수를 `unordered_map`으로 집계
3. 각 항목에 대해 `d × freq(d)` 계산 후 합산


*/
