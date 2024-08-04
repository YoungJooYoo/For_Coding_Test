class Solution 
{
public:
    int winningPlayerCount(const int n, const vector<vector<int>>& pick) 
    {
        vector<unordered_map<int, int>> playerPicks(n);

        // 플레이어가 선택한 공을 기록
        for (const auto& p : pick)
        {
            const int player = p[0];
            const int color = p[1];
            ++playerPicks[player][color];
        }

        int winningCount = 0;

        // 각 플레이어의 승리 조건을 체크
        for (int i = 0; i < n; ++i)
        {
            // 각 플레이어가 선택한 공의 색상별 개수를 순회
            for (const auto& entry : playerPicks[i])
            {
                if (entry.second > i)
                {
                    // 승리 조건 만족 시 승리 카운트 증가
                    winningCount++;
                    break; // 하나의 색상에서 승리 조건을 만족하면 다른 색상은 볼 필요 없음
                }
            }
        }

        return winningCount;
    }
};

// https://leetcode.com/problems/find-the-number-of-winning-players/description/

/*

## 문제 설명

주어진 문제는 n명의 플레이어가 참가하는 게임을 다룹니다. `pick`이라는 2차원 배열이 주어지며, `pick[i] = [xi, yi]`는 플레이어 `xi`가 색상 `yi`의 공을 선택했음을 나타냅니다.

플레이어 `i`가 이기려면 다음 조건을 만족해야 합니다:
- 플레이어 0은 공을 아무거나 선택하면 이깁니다.
- 플레이어 1은 동일한 색상 공을 최소 2개 선택하면 이깁니다.
- 플레이어 `i`는 동일한 색상 공을 최소 `i + 1`개 선택하면 이깁니다.

게임에서 이기는 플레이어의 수를 반환해야 합니다.

## 예제

### 예제 1
**입력:**  
n = 4, pick = [[0,0],[1,0],[1,0],[2,1],[2,1],[2,0]]

**출력:**  
2

**설명:**  
플레이어 0과 1이 게임에서 이기고, 플레이어 2와 3은 이기지 못합니다.

### 예제 2
**입력:**  
n = 5, pick = [[1,1],[1,2],[1,3],[1,4]]

**출력:**  
0

**설명:**  
아무도 이기지 못합니다.

### 예제 3
**입력:**  
n = 5, pick = [[1,1],[2,4],[2,4],[2,4]]

**출력:**  
1

**설명:**  
플레이어 2가 색상 4의 공을 3개 선택하여 게임에서 이깁니다.

## 제약 사항
- 2 <= n <= 10
- 1 <= pick.length <= 100
- pick[i].length == 2
- 0 <= xi <= n - 1
- 0 <= yi <= 10
*/
