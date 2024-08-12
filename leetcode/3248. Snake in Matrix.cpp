class Solution 
{
public:
    int finalPositionOfSnake(const int n, const vector<string>& commands) 
    {
        int i = 0;
        int j = 0;

        initGrid(n);

        for (const auto& command : commands)
        {
            addDirection(command, i , j);
        }

        return mGrid[i][j];
    }

private:
    void initGrid(const int n)
    {
        vector<vector<int>> array(n, vector<int>(n));
        int num = 0;

        for (auto& row : array)
        {
            for (auto& elem : row)
            {
                elem = num++;
            }
        }

        mGrid = array;
    }

    void addDirection(const string& command, int& outI, int& outJ)
    {
        if (command == "DOWN") ++outI;
        else if (command == "UP") --outI;
        else if (command == "RIGHT") ++outJ;
        else if (command == "LEFT") --outJ;
        else assert(false);
    }

private:
    vector<vector<int>> mGrid;
};

/*

### 3248. 행렬 속 뱀

**난이도: 쉬움**

#### 문제 설명

n x n 크기의 행렬 `grid`에는 네 가지 가능한 방향으로 이동할 수 있는 뱀이 있습니다. 이 행렬의 각 셀은 위치 `(i * n) + j`로 식별됩니다.

뱀은 셀 0에서 시작하며 일련의 명령을 따릅니다.

크기를 나타내는 정수 `n`과 `commands`라는 문자열 배열이 주어지며, 각 `command[i]`는 "UP" (위), "RIGHT" (오른쪽), "DOWN" (아래), "LEFT" (왼쪽) 중 하나입니다. 뱀이 이동하는 동안 행렬의 경계를 벗어나지 않는 것이 보장됩니다.

모든 명령을 실행한 후 뱀이 끝나는 마지막 셀의 위치를 반환하세요.

#### 예제

**예제 1**:
- **입력**: `n = 2`, `commands = ["RIGHT","DOWN"]`
- **출력**: `3`
- **설명**:

```
0	1
2	3
```

- 뱀은 먼저 오른쪽으로 이동하여 셀 1로 이동하고, 그 다음 아래로 이동하여 셀 3에 도착합니다.

**예제 2**:
- **입력**: `n = 3`, `commands = ["DOWN","RIGHT","UP"]`
- **출력**: `1`
- **설명**:

```
0	1	2
3	4	5
6	7	8
```

- 뱀은 아래로 이동하여 셀 3으로 이동하고, 그 다음 오른쪽으로 이동하여 셀 4로 이동한 후, 다시 위로 이동하여 셀 1에 도착합니다.

#### 제약 조건
- `2 <= n <= 10`
- `1 <= commands.length <= 100`
- `commands`는 오직 "UP", "RIGHT", "DOWN", "LEFT"로만 구성됩니다.
- 입력은 뱀이 경계를 벗어나지 않도록 생성됩니다.

*/
