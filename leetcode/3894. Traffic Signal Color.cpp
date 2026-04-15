class Solution
{
public:
    string trafficSignal(const int timer) const
    {
        assert(MIN_TIMER <= timer && timer <= MAX_TIMER);

        if (timer == GREEN_TIMER)
        {
            return SIGNAL_GREEN;
        }
        else if (timer == ORANGE_TIMER)
        {
            return SIGNAL_ORANGE;
        }
        else if (ORANGE_TIMER < timer && timer <= RED_TIMER_MAX)
        {
            return SIGNAL_RED;
        }
        else
        {
            return SIGNAL_INVALID;
        }
    }

private:
    enum
    {
        MIN_TIMER     = 0,
        MAX_TIMER     = 1000,
        GREEN_TIMER   = 0,
        ORANGE_TIMER  = 30,
        RED_TIMER_MAX = 90,
    };

    inline static const string SIGNAL_GREEN   = "Green";
    inline static const string SIGNAL_ORANGE  = "Orange";
    inline static const string SIGNAL_RED     = "Red";
    inline static const string SIGNAL_INVALID = "Invalid";
};

/*
https://leetcode.com/problems/traffic-signal-color/submissions/1978743123/

## 문제 번역

**3894. 교통 신호 색상**

교통 신호의 남은 시간(초)을 나타내는 정수 `timer`가 주어집니다.

신호는 아래 규칙을 따릅니다:

- `timer == 0` → 신호는 `"Green"` (초록)
- `timer == 30` → 신호는 `"Orange"` (주황)
- `30 < timer <= 90` → 신호는 `"Red"` (빨강)

현재 신호 상태를 반환하세요. 위 조건 중 어느 것도 해당하지 않으면 `"Invalid"`를 반환하세요.

---

**예시 1**
- 입력: `timer = 60`
- 출력: `"Red"`
- 설명: `30 < 60 <= 90` 이므로 `"Red"`

**예시 2**
- 입력: `timer = 5`
- 출력: `"Invalid"`
- 설명: 어떤 조건도 만족하지 않으므로 `"Invalid"`

---

**제약 조건**
- `0 <= timer <= 1000`

---

## 요약

`timer` 값에 따라 **4가지 중 하나의 문자열** 반환. 조건 분기 문제.

---

## 풀이 방향

```
timer == 0          → "Green"
timer == 30         → "Orange"
30 < timer <= 90    → "Red"
그 외               → "Invalid"
```


*/
