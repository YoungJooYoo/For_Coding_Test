class Solution 
{
public:
    int isWinner(const vector<int>& player1, const vector<int>& player2) 
    {
        const int PLAYER_1_SCORE = calculateScore(player1);
        const int PLAYER_2_SCORE = calculateScore(player2);

        if (PLAYER_1_SCORE == PLAYER_2_SCORE)
        {
            return SAME_SCORE;
        }
        else if (PLAYER_1_SCORE > PLAYER_2_SCORE)
        {
            return WIN_PLAYER_1;
        }
        else if (PLAYER_1_SCORE < PLAYER_2_SCORE)
        {
            return WIN_PLAYER_2;
        }
        else
        {
            assert(false);
        }
    }

private:
    int calculateScore(const vector<int>& player) 
    {
        const int n = player.size();
        int score = 0;

        for (size_t i = 0; i < n; ++i) 
        {
            if ((i >= 1 && player[i - 1] == 10) or (i >= 2 && player[i - 2] == 10)) 
            {
                score += 2 * player[i];
            } 
            else 
            {
                score += player[i];
            }
    }

    return score;
}

private:
    enum
    {
        SAME_SCORE = 0,
        WIN_PLAYER_1 = 1,
        WIN_PLAYER_2 = 2
    };
};


//  https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/

/*

### 2660. 볼링 게임의 승자를 결정하기

**난이도: 쉬움**

당신은 두 개의 0-인덱스 정수 배열 `player1`과 `player2`를 받았습니다. 이 배열들은 각각 플레이어 1과 플레이어 2가 볼링 게임에서 맞춘 핀의 수를 나타냅니다.

볼링 게임은 n 턴으로 구성되어 있으며, 각 턴에서 핀의 수는 정확히 10개입니다.

플레이어가 `i`번째 턴에서 `xi`개의 핀을 맞추었다고 가정합니다. 해당 턴의 가치는 다음과 같이 계산됩니다:

- 플레이어가 `(i - 1)`번째 또는 `(i - 2)`번째 턴에서 10개의 핀을 맞췄다면 `2 * xi`입니다.
- 그렇지 않으면 `xi`입니다.

플레이어의 점수는 n 턴의 가치 합계입니다.

다음과 같은 결과를 반환하세요:

- 만약 플레이어 1의 점수가 플레이어 2의 점수보다 많다면 `1`을 반환합니다.
- 만약 플레이어 2의 점수가 플레이어 1의 점수보다 많다면 `2`를 반환합니다.
- 점수가 동점이라면 `0`을 반환합니다.

### 예제

**예제 1**:

- 입력: `player1 = [5,10,3,2]`, `player2 = [6,5,7,3]`
- 출력: `1`
- 설명:
  - 플레이어 1의 점수는 `5 + 10 + 2 * 3 + 2 * 2 = 25`입니다.
  - 플레이어 2의 점수는 `6 + 5 + 7 + 3 = 21`입니다.

**예제 2**:

- 입력: `player1 = [3,5,7,6]`, `player2 = [8,10,10,2]`
- 출력: `2`
- 설명:
  - 플레이어 1의 점수는 `3 + 5 + 7 + 6 = 21`입니다.
  - 플레이어 2의 점수는 `8 + 10 + 2 * 10 + 2 * 2 = 42`입니다.

**예제 3**:

- 입력: `player1 = [2,3]`, `player2 = [4,1]`
- 출력: `0`
- 설명:
  - 플레이어 1의 점수는 `2 + 3 = 5`입니다.
  - 플레이어 2의 점수는 `4 + 1 = 5`입니다.

**예제 4**:

- 입력: `player1 = [1,1,1,10,10,10,10]`, `player2 = [10,10,10,10,1,1,1]`
- 출력: `2`
- 설명:
  - 플레이어 1의 점수는 `1 + 1 + 1 + 10 + 2 * 10 + 2 * 10 + 2 * 10 = 73`입니다.
  - 플레이어 2의 점수는 `10 + 2 * 10 + 2 * 10 + 2 * 10 + 2 * 1 + 2 * 1 + 1 = 75`입니다.

### 제약 조건

- `n == player1.length == player2.length`
- `1 <= n <= 1000`
- `0 <= player1[i], player2[i] <= 10`
*/
