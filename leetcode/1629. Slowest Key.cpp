class Solution 
{
public:
    char slowestKey(const vector<int>& releaseTimes, const string& keysPressed) 
    {
        const size_t LENGTH = releaseTimes.size();
        int maxTime = INT_MIN;
        int prevTime = 0;
        char key = keysPressed[0];

        for (size_t i = 0; i < LENGTH; ++i)
        {
            const int currTime = releaseTimes[i] - prevTime;
            if (maxTime < currTime || (maxTime == currTime && keysPressed[i] > key))
            {
                maxTime = currTime;
                key = keysPressed[i];
            }
            prevTime = releaseTimes[i];
        }

        return key; 
    }
};

// https://leetcode.com/problems/slowest-key/description/

/*
### 1629. 가장 느린 키
**난이도: 쉬움**

#### 문제 설명
새로 설계된 키패드를 테스트하였고, 테스트하는 사람이 일련의 n개의 키를 한 번에 하나씩 눌렀습니다.

당신은 길이 n인 문자열 `keysPressed`와 정렬된 리스트 `releaseTimes`를 받았습니다. `keysPressed[i]`는 테스트 시퀀스에서 i번째로 눌린 키를 나타내고, `releaseTimes[i]`는 i번째 키가 놓인 시간을 나타냅니다. 두 배열은 0-인덱스입니다. 0번째 키는 시간 0에 눌렸고, 이후의 각 키는 이전 키가 놓인 정확한 시간에 눌렸습니다.

테스터는 가장 오랫동안 눌린 키를 알고 싶어 합니다. i번째 키가 눌린 시간은 `releaseTimes[i] - releaseTimes[i - 1]`이며, 0번째 키가 눌린 시간은 `releaseTimes[0]`입니다.

테스트 중에 동일한 키가 여러 번 눌릴 수 있으며, 이러한 동일한 키의 여러 번의 누름은 지속 시간이 같지 않을 수 있습니다.

가장 오랫동안 눌린 키를 반환하세요. 만약 그러한 키가 여러 개라면, 사전적으로 가장 큰 키를 반환하세요.

#### 예제

**예제 1**:

- 입력: `releaseTimes = [9,29,49,50]`, `keysPressed = "cbcd"`
- 출력: `"c"`
- 설명: 키 눌림은 다음과 같습니다:
  - 'c' 키는 9의 지속 시간 동안 눌렸습니다 (시간 0에 눌리고 9에 놓임).
  - 'b' 키는 29 - 9 = 20의 지속 시간 동안 눌렸습니다 (시간 9에 바로 눌리고 29에 놓임).
  - 'c' 키는 49 - 29 = 20의 지속 시간 동안 눌렸습니다 (시간 29에 바로 눌리고 49에 놓임).
  - 'd' 키는 50 - 49 = 1의 지속 시간 동안 눌렸습니다 (시간 49에 바로 눌리고 50에 놓임).
  - 이 중에서 가장 긴 것은 'b'와 두 번째 'c'의 20의 지속 시간입니다.
  - 'c'는 'b'보다 사전적으로 더 크므로, 답은 'c'입니다.

**예제 2**:

- 입력: `releaseTimes = [12,23,36,46,62]`, `keysPressed = "spuda"`
- 출력: `"a"`
- 설명: 키 눌림은 다음과 같습니다:
  - 's' 키는 12의 지속 시간 동안 눌렸습니다.
  - 'p' 키는 23 - 12 = 11의 지속 시간 동안 눌렸습니다.
  - 'u' 키는 36 - 23 = 13의 지속 시간 동안 눌렸습니다.
  - 'd' 키는 46 - 36 = 10의 지속 시간 동안 눌렸습니다.
  - 'a' 키는 62 - 46 = 16의 지속 시간 동안 눌렸습니다.
  - 이 중에서 가장 긴 것은 'a'의 16의 지속 시간입니다.

#### 제약 조건

- `releaseTimes.length == n`
- `keysPressed.length == n`
- `2 <= n <= 1000`
- `1 <= releaseTimes[i] <= 10^9`
- `releaseTimes[i] < releaseTimes[i+1]`
- `keysPressed`는 오직 소문자 영어 문자만 포함합니다.
*/
