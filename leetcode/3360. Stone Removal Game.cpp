class Solution 
{
public:
    bool canAliceWin(int totalStones) 
    {
        int stonesToRemove = 10;
        bool isAliceTurn = true;

        while (totalStones >= stonesToRemove)
        {
            totalStones -= stonesToRemove;
            --stonesToRemove;
            isAliceTurn = !isAliceTurn;
        }

        return isAliceTurn == false;
    }
};

// https://leetcode.com/problems/stone-removal-game/description/

/*

**3360. 돌 제거 게임**  
난이도: 쉬움

---

앨리스와 밥은 번갈아 가며 돌을 제거하는 게임을 하고 있습니다. 앨리스가 먼저 시작합니다.

게임 규칙은 다음과 같습니다:
- **첫 번째 턴**에, 앨리스는 정확히 **10개의 돌**을 제거합니다.
- **이후의 턴**에서는, 각 플레이어가 이전 상대방이 제거한 돌보다 정확히 **1개 적은** 돌을 제거합니다.
- 제거할 수 있는 돌이 없는 플레이어가 게임에서 **패배**하게 됩니다.

양의 정수 `n`이 주어질 때, **앨리스가 게임에서 이길 수 있다면 `true`를 반환**하고, 그렇지 않다면 **`false`를 반환**하세요.

---

### 예제 1:

입력: 
```
n = 12
```
출력: 
```
true
```
설명:

- 앨리스는 첫 번째 턴에 **10개의 돌**을 제거하고, 돌 **2개**가 남습니다.
- 밥은 **9개의 돌**을 제거할 수 없기 때문에, 앨리스가 승리합니다.

### 예제 2:

입력: 
```
n = 1
```
출력: 
```
false
```
설명:

- 앨리스는 **10개의 돌**을 제거할 수 없기 때문에, 앨리스가 패배합니다.

---

이 문제는 앨리스와 밥이 번갈아 가며 돌을 제거하는 과정에서 앨리스가 이길 수 있는지를 결정하는 문제입니다.
*/
