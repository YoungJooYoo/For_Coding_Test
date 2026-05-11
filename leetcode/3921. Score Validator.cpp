class Solution
{
public:
    vector<int> scoreValidator(const vector<string>& events) const
    {
        assert(MIN_LENGTH <= static_cast<int>(events.size()) && static_cast<int>(events.size()) <= MAX_LENGTH);

        int score   = 0;
        int counter = 0;

        for (const auto& event : events) // counter가 10이 되면 즉시 중단
        {
            if (counter == MAX_COUNTER)
            {
                break;
            }
            else if (event == "W")
            {
                ++counter;
            }
            else if (event == "WD" || event == "NB")
            {
                score += SCORE_ONE;
            }
            else if (event == "0" || event == "1" || event == "2" ||
                     event == "3" || event == "4" || event == "6")
            {
                score += stoi(event);
            }
            else
            {
                assert(false); // 유효하지 않은 이벤트
            }
        }

        assert(score >= 0 && counter >= 0);
        return {score, counter};
    }

private:
    enum
    {
        MIN_LENGTH   = 1,
        MAX_LENGTH   = 1000,
        MAX_COUNTER  = 10,
        SCORE_ONE    = 1,
    };
};

/*
https://leetcode.com/problems/score-validator/description/
## 문제 번역

**3921. 점수 검증기**

문자열 배열 `events`가 주어집니다.

초기 상태: `score = 0`, `counter = 0`

각 이벤트의 동작은 다음과 같습니다:

| 이벤트 | 동작 |
|--------|------|
| `"0"`, `"1"`, `"2"`, `"3"`, `"4"`, `"6"` | 해당 숫자를 `score`에 더함 |
| `"W"` | `counter`를 1 증가 (점수 없음) |
| `"WD"` | `score`에 1을 더함 |
| `"NB"` | `score`에 1을 더함 |

배열을 **왼쪽에서 오른쪽으로** 처리합니다. 아래 두 조건 중 하나를 만족하면 **즉시 중단**합니다:

- 모든 이벤트를 처리 완료했거나
- `counter`가 **10**이 되었을 때

최종 `[score, counter]`를 반환하세요.

---

**예시 1**
- 입력: `events = ["1","4","W","6","WD"]`
- 출력: `[12, 1]`

| 이벤트 | score | counter |
|--------|-------|---------|
| `"1"` | 1 | 0 |
| `"4"` | 5 | 0 |
| `"W"` | 5 | 1 |
| `"6"` | 11 | 1 |
| `"WD"` | 12 | 1 |

**예시 2**
- 입력: `events = ["WD","NB","0","4","4"]`
- 출력: `[10, 0]`

| 이벤트 | score | counter |
|--------|-------|---------|
| `"WD"` | 1 | 0 |
| `"NB"` | 2 | 0 |
| `"0"` | 2 | 0 |
| `"4"` | 6 | 0 |
| `"4"` | 10 | 0 |

**예시 3**
- 입력: `events = ["W","W","W","W","W","W","W","W","W","W","W"]`
- 출력: `[0, 10]`
- 설명: `"W"` 10번 처리 후 `counter == 10` → 즉시 중단, 나머지 무시

---

**제약 조건**
- `1 <= events.length <= 1000`
- `events[i]` 는 `"0"`, `"1"`, `"2"`, `"3"`, `"4"`, `"6"`, `"W"`, `"WD"`, `"NB"` 중 하나

---

## 요약

이벤트 배열을 순서대로 처리하며 `score`와 `counter`를 누적. `counter == 10` 이 되는 순간 즉시 중단 후 `[score, counter]` 반환.

---

## 풀이 방향

1. `score`, `counter` 초기화
2. 각 이벤트를 순서대로 처리
3. `counter == MAX_COUNTER(10)` 이면 즉시 `break`
4. 이벤트 종류에 따라 분기 처리
5. `[score, counter]` 반환


*/
