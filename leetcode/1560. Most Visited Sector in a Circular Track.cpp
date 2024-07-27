class Solution 
{
public:
    vector<int> mostVisited(const int n, const vector<int>& rounds) 
    {
        vector<int> visits(n + 1, 0);
        vector<int> result;
        int start = rounds[0];
        int end = rounds[rounds.size() - 1];

        if (start <= end)
        {
            for (int i = start; i <= end; ++i)
            {
                ++visits[i];
            }
        }
        else
        {
            for (int i = start; i <= n; ++i)
            {
                ++visits[i];
            }
            for (int i = 1; i <= end; ++i)
            {
                ++visits[i];
            }
        }

        const int maxVisits = *max_element(visits.begin(), visits.end());
        for (int i = 1; i <= n; ++i) 
        {
            if (visits[i] == maxVisits) 
            {
                result.push_back(i);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/most-visited-sector-in-a-circular-track/description/

/*

### 1560. 원형 트랙에서 가장 많이 방문한 구역

**난이도: 쉬움**

#### 문제 설명
정수 n과 정수 배열 `rounds`가 주어집니다. 우리는 1부터 n까지 레이블이 붙은 n개의 구역으로 구성된 원형 트랙을 가지고 있습니다. 마라톤은 이 트랙에서 열리며, m 라운드로 구성됩니다. i번째 라운드는 구역 `rounds[i - 1]`에서 시작하여 구역 `rounds[i]`에서 끝납니다. 예를 들어, 라운드 1은 구역 `rounds[0]`에서 시작하여 구역 `rounds[1]`에서 끝납니다.

가장 많이 방문한 구역을 오름차순으로 정렬하여 배열로 반환하세요.

구역 번호의 오름차순으로 반시계 방향으로 트랙을 순회한다는 점에 유의하세요 (첫 번째 예제를 참고하세요).

#### 예제

**예제 1**:

- 입력: `n = 4, rounds = [1,3,1,2]`
- 출력: `[1,2]`
- 설명: 마라톤은 구역 1에서 시작합니다. 방문한 구역의 순서는 다음과 같습니다:
  1 --> 2 --> 3 (라운드 1의 끝) --> 4 --> 1 (라운드 2의 끝) --> 2 (라운드 3의 끝이자 마라톤의 끝)
  구역 1과 2가 각각 두 번 방문되어 가장 많이 방문한 구역입니다. 구역 3과 4는 한 번만 방문됩니다.

**예제 2**:

- 입력: `n = 2, rounds = [2,1,2,1,2,1,2,1,2]`
- 출력: `[2]`

**예제 3**:

- 입력: `n = 7, rounds = [1,3,5,7]`
- 출력: `[1,2,3,4,5,6,7]`

#### 제약 조건

- 2 <= n <= 100
- 1 <= rounds.length <= 100
- 1 <= rounds[i] <= n
- `rounds[i] != rounds[i - 1]` (i > 0)
*/
