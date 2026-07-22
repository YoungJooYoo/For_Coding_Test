class Solution
{
public:
    bool canReach(const vector<int>& start, const vector<int>& target) const
    {
        assert(start.size() == COORDINATE_LENGTH && target.size() == COORDINATE_LENGTH);
        assert(MIN_POSITION <= start[X] && start[X] <= MAX_POSITION);
        assert(MIN_POSITION <= start[Y] && start[Y] <= MAX_POSITION);
        assert(MIN_POSITION <= target[X] && target[X] <= MAX_POSITION);
        assert(MIN_POSITION <= target[Y] && target[Y] <= MAX_POSITION);

        const int startColor = (start[X] + start[Y]) % 2;
        const int targetColor = (target[X] + target[Y]) % 2;

        return (startColor == targetColor) ? true : false;
    }

private:
    enum
    {
        COORDINATE_LENGTH = 2,
        MIN_POSITION = 0,
        MAX_POSITION = 7,
        X = 0,
        Y = 1
    };
};

/*
https://leetcode.com/problems/even-number-of-knight-moves/description/
## 3996. 짝수 번의 나이트 이동 (Even Number of Knight Moves)

**난이도: Easy**

두 개의 정수 배열 `start`와 `target`이 주어지며, 각 배열은 표준 8 x 8 체스판 위의 칸을 나타내는 `[x, y]` 형태입니다.

나이트(knight)가 `start`에서 `target`까지 **짝수 번**의 이동으로 도달할 수 있으면 `true`를 반환하고, 그렇지 않으면 `false`를 반환하세요.

**참고**: 유효한 나이트 이동은 한 방향으로 두 칸 이동한 뒤, 그와 수직인 방향으로 한 칸 이동하는 것입니다. 한 칸에서 가능한 8가지 이동이 있습니다.

---

**예제 1:**
```
입력: start = [1,1], target = [2,2]
출력: true
설명:
가능한 이동 순서 중 하나는 (1, 1) -> (3, 2) -> (2, 4) -> (4, 3) -> (2, 2)입니다.
나이트가 4번의 이동으로 목표에 도달하며, 4는 짝수입니다. 따라서 정답은 true입니다.
```

**예제 2:**
```
입력: start = [4,5], target = [6,6]
출력: false
설명:
start = [4, 5]에서 target = [6, 6]까지 짝수 번의 이동으로 도달하는 것은
불가능합니다. 따라서 정답은 false입니다.
```

---

**제약 조건:**
- `start.length == target.length == 2`
- `0 <= start[i], target[i] <= 7`
*/
