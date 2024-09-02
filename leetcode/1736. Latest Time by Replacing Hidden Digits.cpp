class Solution 
{
public:
    string maximumTime(string& time) 
    {
        // 시간의 첫 번째 자리를 결정
        if (time[0] == '?') 
        {
            if (time[1] == '?' || time[1] <= '3') 
            {
                time[0] = '2';  // 최대 가능한 값인 2를 할당
            } 
            else 
            {
                time[0] = '1';  // 앞자리가 1이 될 수 있는 최대 값
            }
        }

        // 시간의 두 번째 자리를 결정
        if (time[1] == '?') 
        {
            if (time[0] == '2') 
            {
                time[1] = '3';  // 첫 자리가 2일 때, 최대 가능한 값 3
            } 
            else 
            {
                time[1] = '9';  // 첫 자리가 0이나 1일 때, 최대 가능한 값 9
            }
        }

        // 분의 첫 번째 자리를 결정
        if (time[3] == '?') 
        {
            time[3] = '5';  // 최대 가능한 값인 5를 할당
        }

        // 분의 두 번째 자리를 결정
        if (time[4] == '?') 
        {
            time[4] = '9';  // 최대 가능한 값인 9를 할당
        }

        return time;
    }
};

// https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/


/*

다음은 LeetCode 문제 1736의 한국어 번역입니다:

---

### 1736. 숨겨진 숫자를 대체하여 가장 늦은 시간을 찾기

**난이도: 쉬움**

#### 문제 설명

시간을 나타내는 문자열 `time`이 주어집니다. 형식은 `hh:mm`이며, 문자열의 일부 자릿수는 숨겨져 있을 수 있습니다 (숨겨진 숫자는 `?`로 표시됩니다).

유효한 시간은 `00:00`부터 `23:59`까지의 시간입니다.

숨겨진 숫자를 대체하여 만들 수 있는 가장 늦은 유효한 시간을 반환하세요.

#### 예제

**예제 1**:

- 입력: `time = "2?:?0"`
- 출력: `"23:50"`
- 설명: 숫자 '2'로 시작하는 가장 늦은 시간은 `23:00`이며, '0'으로 끝나는 가장 늦은 분은 `50`입니다.

**예제 2**:

- 입력: `time = "0?:3?"`
- 출력: `"09:39"`
- 설명: 숫자 '0'으로 시작하는 가장 늦은 시간은 `09:00`이며, `?`로 끝나는 가장 늦은 분은 `39`입니다.

**예제 3**:

- 입력: `time = "1?:22"`
- 출력: `"19:22"`
- 설명: 숫자 '1'로 시작하는 가장 늦은 시간은 `19:00`입니다.

#### 제약 조건

- `time`은 `hh:mm` 형식입니다.
- 주어진 입력은 항상 유효한 시간으로 대체할 수 있습니다.
*/