class Solution 
{
public:
    vector<string> readBinaryWatch(const int turnedOn) 
    {
        vector<string> result;

        for (int hour = 0; hour <= HOUR; ++hour) 
        {
            for (int minute = 0; minute <= MINUTE; ++minute) 
            {
                // bitset을 사용하여 1의 개수를 셉니다.
                const int HOUR_BIT_COUNT = bitset<4>(hour).count();
                const int MIN_BIT_COUNT = bitset<6>(minute).count();
                if (HOUR_BIT_COUNT + MIN_BIT_COUNT == turnedOn) 
                {
                    // 시간 형식으로 추가합니다. 분은 항상 두 자리 수로 표시됩니다.
                    result.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
                }
            }
        }

        return  result;
    }

private:
    enum 
    {
        HOUR = 11,
        MINUTE = 59
    };
};

// https://leetcode.com/problems/binary-watch/
/*

### 문제 설명

401. 이진 시계 (Binary Watch)

이진 시계는 시간을 표현하는 특이한 방식의 시계입니다. 이 시계는 다음과 같은 구조를 가집니다:

- 상단에 4개의 LED가 있으며, 이는 시간을 나타냅니다. 시간은 0부터 11까지 표현됩니다.
- 하단에 6개의 LED가 있으며, 이는 분을 나타냅니다. 분은 0부터 59까지 표현됩니다.
- 각 LED는 0 또는 1을 나타내며, 오른쪽 끝이 가장 작은 비트(least significant bit)입니다.

예를 들어, 아래의 이진 시계는 "4:51"을 나타냅니다.

정수 `turnedOn`이 주어지는데, 이는 현재 켜져 있는 LED의 개수를 나타냅니다. 가능한 모든 시간을 반환하세요. 반환된 시간은 어떤 순서로든 상관없습니다.

- 시간은 선행 0을 포함해서는 안 됩니다. 예를 들어, "01:00"은 유효하지 않으며 "1:00"으로 표현되어야 합니다.
- 분은 두 자릿수여야 하며, 선행 0을 포함할 수 있습니다. 예를 들어, "10:2"는 유효하지 않으며 "10:02"로 표현되어야 합니다.

### 예제

**예제 1:**

- 입력: `turnedOn = 1`
- 출력: `["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]`

**예제 2:**

- 입력: `turnedOn = 9`
- 출력: `[]`

### 제약 조건

- `0 <= turnedOn <= 10`

*/
