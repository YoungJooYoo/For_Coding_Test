class Solution 
{
public:
    vector<int> executeInstructions(const int n, const vector<int>& startPos, const string& s) 
    {
        const size_t LENGTH = s.size();
        vector<int> result;
        
        for (size_t i = 0 ; i < LENGTH; ++i)
        {
            int x = startPos[0];
            int y = startPos[1];
            int count = 0;
            for (size_t j = i; j < LENGTH; ++j)
            {
                if (s[j] == 'R')
                {
                    ++y;
                    if (y >= n)
                    {
                        break;
                    }
                    ++count;
                }
                else if (s[j] == 'D')
                {
                    ++x;
                    if (x >= n)
                    {
                        break;
                    }
                    ++count;
                }
                else if (s[j] == 'U')
                {
                    --x;
                    if (x < 0)
                    {
                        break;
                    }
                    ++count;
                }
                else if (s[j] == 'L')
                {
                    --y;
                    if (y < 0)
                    {
                        break;
                    }
                    ++count;
                }
                else
                {
                    assert(false);
                }
            }
            result.push_back(count);
        }

        return result;
    }
};

// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/description/

/*

2120. 그리드 내에서 모든 접미사 명령어 실행
난이도: 중간
주제
힌트
`n x n` 그리드가 있습니다. 그리드는 좌상단 (0, 0)에서 시작하며 우하단 (n - 1, n - 1)에서 끝납니다. 
정수 `n`과 정수 배열 `startPos`가 주어지며, `startPos = [startrow, startcol]`은 로봇이 처음에 위치한 셀을 나타냅니다.

또한, 길이 `m`인 0-인덱스 문자열 `s`가 주어집니다. 여기서 `s[i]`는 로봇에 대한 i번째 명령을 의미하며, 
'L' (왼쪽 이동), 'R' (오른쪽 이동), 'U' (위로 이동), 'D' (아래로 이동) 중 하나입니다.

로봇은 `s`의 어느 i번째 명령어부터 실행을 시작할 수 있습니다. 
로봇은 한 번에 하나씩 명령을 실행하며, 다음 중 하나의 조건이 충족되면 실행을 중지합니다:
1. 다음 명령이 로봇을 그리드 밖으로 이동시킬 경우.
2. 더 이상 실행할 명령이 남지 않은 경우.

배열 `answer`를 반환하세요. `answer[i]`는 로봇이 `s`의 i번째 명령부터 실행을 시작했을 때 실행할 수 있는 명령의 수를 나타냅니다.

### 예시 1:

입력: n = 3, startPos = [0,1], s = "RRDDLU"  
출력: [1, 5, 4, 3, 1, 0]  
설명:  
`startPos`에서 시작해 i번째 명령부터 실행하는 경우:
- 0번째: "RRDDLU". "R" 한 명령만 실행 가능하며, 그 이후엔 그리드 밖으로 이동.
- 1번째: "RDDLU". 5개의 모든 명령을 실행할 수 있으며, (1, 1)에서 종료.
- 2번째: "DDLU". 4개의 명령을 모두 실행할 수 있으며, (1, 0)에서 종료.
- 3번째: "DLU". 3개의 명령을 실행하며, (0, 0)에서 종료.
- 4번째: "LU". "L"만 실행 가능하며, 그리드 밖으로 이동.
- 5번째: "U". "U"를 실행하면 그리드 밖으로 이동.

### 예시 2:

입력: n = 2, startPos = [1,1], s = "LURD"  
출력: [4, 1, 0, 0]  
설명:  
- 0번째: "LURD". 모든 명령을 실행 가능.
- 1번째: "URD". 1개 명령만 실행 가능.
- 2번째: "RD". 실행할 수 없음.
- 3번째: "D". 실행할 수 없음.

### 예시 3:

입력: n = 1, startPos = [0,0], s = "LRUD"  
출력: [0, 0, 0, 0]  
설명:  
명령을 어디서 시작하든 로봇은 그리드 밖으로 이동하므로 명령을 실행할 수 없음.

### 제한 사항:
- `m == s.length`
- 1 <= n, m <= 500
- `startPos.length == 2`
- 0 <= startrow, startcol < n
- `s`는 'L', 'R', 'U', 'D'로만 구성됩니다.
*/
