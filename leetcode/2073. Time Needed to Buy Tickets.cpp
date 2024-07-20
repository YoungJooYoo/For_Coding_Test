class Solution 
{
public:
    int timeRequiredToBuy(vector<int>& tickets, const int k) 
    {
        const size_t LENGTH = tickets.size();
        int result = 0;

        size_t i = 0;
        while (true)
        {
            if (i == k)
            {
                if (tickets[i] == 0)
                {
                    return result;
                }
                else
                {
                    --tickets[i];
                    ++result;
                    if (tickets[k] == 0)
                    {
                        return result;
                    }
                }
            }
            else
            {
                if (tickets[i] == 0)
                {
                    ++i;
                    i %= LENGTH;
                    continue;
                }
                else
                {
                    --tickets[i];
                    ++result;
                }
                
            }
            ++i;
            i %= LENGTH;
        }

        return result;
    }
};

// https://leetcode.com/problems/time-needed-to-buy-tickets/description/

/*
### 2073. 티켓을 사는 데 필요한 시간

**난이도: 쉬움**

#### 문제 설명

티켓을 사기 위해 줄을 서 있는 n명의 사람이 있습니다. 0번째 사람은 줄의 맨 앞에 있고, (n - 1)번째 사람은 줄의 맨 뒤에 있습니다.

길이 n인 0-인덱스 정수 배열 `tickets`가 주어집니다. 여기서 `tickets[i]`는 i번째 사람이 사고자 하는 티켓의 수를 나타냅니다.

각 사람은 티켓을 사는 데 정확히 1초가 걸립니다. 사람은 한 번에 티켓 1장씩만 살 수 있으며, 더 많은 티켓을 사기 위해 줄의 끝으로 돌아가야 합니다(즉시 일어납니다). 만약 사람이 더 이상 살 티켓이 없다면, 그 사람은 줄을 떠납니다.

0-인덱스 위치 k에 있는 사람이 티켓을 다 살 때까지 걸리는 시간을 반환하세요.

#### 예제

**예제 1**:

- 입력: `tickets = [2,3,2]`, `k = 2`
- 출력: `6`
- 설명:
  - 첫 번째 패스에서, 줄에 있는 모든 사람이 티켓을 1장씩 사고 줄은 `[1, 2, 1]`이 됩니다.
  - 두 번째 패스에서, 줄에 있는 모든 사람이 티켓을 1장씩 사고 줄은 `[0, 1, 0]`이 됩니다.
  - 2번째 위치에 있는 사람이 2장의 티켓을 모두 샀고, 3 + 3 = 6초가 걸렸습니다.

**예제 2**:

- 입력: `tickets = [5,1,1,1]`, `k = 0`
- 출력: `8`
- 설명:
  - 첫 번째 패스에서, 줄에 있는 모든 사람이 티켓을 1장씩 사고 줄은 `[4, 0, 0, 0]`이 됩니다.
  - 다음 4개의 패스에서, 0번째 위치에 있는 사람만 티켓을 삽니다.
  - 0번째 위치에 있는 사람이 5장의 티켓을 모두 샀고, 4 + 1 + 1 + 1 + 1 = 8초가 걸렸습니다.

#### 제약 조건

- `n == tickets.length`
- `1 <= n <= 100`
- `1 <= tickets[i] <= 100`
- `0 <= k < n`
*/
