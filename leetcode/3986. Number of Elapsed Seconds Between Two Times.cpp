class Solution
{
public:
    int secondsBetweenTimes(string startTime, string endTime) const
    {
        assert(startTime.length() == TIME_LENGTH);
        assert(endTime.length() == TIME_LENGTH);
        assert(startTime[COLON_INDEX_FIRST] == ':');
        assert(startTime[COLON_INDEX_SECOND] == ':');
        assert(endTime[COLON_INDEX_FIRST] == ':');
        assert(endTime[COLON_INDEX_SECOND] == ':');

        const int startHour = stoi(startTime.substr(HOUR_INDEX, DIGIT_COUNT));
        const int startMinute = stoi(startTime.substr(MINUTE_INDEX, DIGIT_COUNT));
        const int startSecond = stoi(startTime.substr(SECOND_INDEX, DIGIT_COUNT));
        const int endHour = stoi(endTime.substr(HOUR_INDEX, DIGIT_COUNT));
        const int endMinute = stoi(endTime.substr(MINUTE_INDEX, DIGIT_COUNT));
        const int endSecond = stoi(endTime.substr(SECOND_INDEX, DIGIT_COUNT));

        assert(MIN_HOUR <= startHour && startHour <= MAX_HOUR);
        assert(MIN_MINUTE <= startMinute && startMinute <= MAX_MINUTE);
        assert(MIN_SECOND <= startSecond && startSecond <= MAX_SECOND);
        assert(MIN_HOUR <= endHour && endHour <= MAX_HOUR);
        assert(MIN_MINUTE <= endMinute && endMinute <= MAX_MINUTE);
        assert(MIN_SECOND <= endSecond && endSecond <= MAX_SECOND);
        assert(getSecond(startTime) <= getSecond(endTime));

        const int diffTime = getSecond(endTime) - getSecond(startTime);
        assert(diffTime >= 0);

        return diffTime;
    }

private:
    int getSecond(const string& time) const
    {
        const int hour = stoi(time.substr(HOUR_INDEX, DIGIT_COUNT));
        const int minute = stoi(time.substr(MINUTE_INDEX, DIGIT_COUNT));
        const int second = stoi(time.substr(SECOND_INDEX, DIGIT_COUNT));
        const int totalSeconds = hour * SECONDS_PER_HOUR + minute * SECONDS_PER_MINUTE + second;

        assert(totalSeconds >= 0);
        return totalSeconds;
    }

    enum
    {
        TIME_LENGTH = 8,
        MIN_HOUR = 0,
        MAX_HOUR = 23,
        MIN_MINUTE = 0,
        MAX_MINUTE = 59,
        MIN_SECOND = 0,
        MAX_SECOND = 59,
        SECONDS_PER_HOUR = 3600,
        SECONDS_PER_MINUTE = 60,
        HOUR_INDEX = 0,
        MINUTE_INDEX = 3,
        SECOND_INDEX = 6,
        COLON_INDEX_FIRST = 2,
        COLON_INDEX_SECOND = 5,
        DIGIT_COUNT = 2
    };
};

/*
https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/description/

## 3986. 두 시각 사이에 경과한 초의 수 (Number of Elapsed Seconds Between Two Times)

**난이도: Easy**

두 개의 유효한 시각 `startTime`과 `endTime`이 주어지며, 각각 `"HH:MM:SS"` 형식의 문자열로 표현됩니다.

`startTime`부터 `endTime`까지 경과한 초의 수를 반환하세요.

---

**예제 1:**
```
입력: startTime = "01:00:00", endTime = "01:00:25"
출력: 25
설명:
endTime은 startTime보다 25초 뒤입니다.
```

**예제 2:**
```
입력: startTime = "12:34:56", endTime = "13:00:00"
출력: 1504
설명:
endTime은 startTime보다 25분 4초 뒤이며, 이는 1504초와 같습니다.
```

---

**제약 조건:**
- `startTime.length == 8`
- `endTime.length == 8`
- `startTime`과 `endTime`은 `"HH:MM:SS"` 형식의 유효한 시각입니다.
- `00 <= HH <= 23`
- `00 <= MM <= 59`
- `00 <= SS <= 59`
- `endTime`은 `startTime`보다 이르지 않습니다.
*/
