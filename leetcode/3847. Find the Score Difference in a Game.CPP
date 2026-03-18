class Solution
{
public:
    int scoreDifference(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);

        const size_t LENGTH = nums.size();
        bool bIsPlayer1Active = true;
        int player1Score = 0;
        int player2Score = 0;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            const int num = nums[i];
            assert(MIN_VALUE <= num && num <= MAX_VALUE);
            if (num % 2 != 0) // 규칙 1: 홀수이면 역할 교체
            {
                bIsPlayer1Active = (bIsPlayer1Active == true) ? false : true;
            }
            if (i % SWAP_CYCLE == SWAP_OFFSET) // 규칙 2: 6번째 게임(인덱스 5, 11, 17...)마다 역할 교체
            {
                bIsPlayer1Active = (bIsPlayer1Active == true) ? false : true;
            }
            if (bIsPlayer1Active == true) // 규칙 3: 활성 플레이어가 점수 획득
            {
                player1Score += num;
            }
            else
            {
                player2Score += num;
            }
        }

        return (player1Score - player2Score);
    }

private:
    enum
    {
        MIN_LENGTH  = 1,
        MAX_LENGTH  = 1000,
        MIN_VALUE   = 1,
        MAX_VALUE   = 1000,
        SWAP_CYCLE  = 6,   // 6번째 게임마다 교체
        SWAP_OFFSET = 5,   // 인덱스 5, 11, 17... (0-based)
    };
};

/*
https://leetcode.com/problems/find-the-score-difference-in-a-game/

## 문제 번역

**3847. 게임에서 점수 차이 구하기**

정수 배열 `nums`가 주어지며, `nums[i]`는 `i`번째 게임에서 획득한 점수를 나타냅니다.

플레이어는 정확히 두 명입니다. 초기에는 **첫 번째 플레이어가 활성**, **두 번째 플레이어가 비활성** 상태입니다.

각 게임 `i`마다 아래 규칙이 **순서대로** 적용됩니다:

1. `nums[i]`가 **홀수**이면, 활성/비활성 플레이어가 **역할을 교체**합니다.
2. **매 6번째 게임**(즉, 게임 인덱스 `5, 11, 17, ...`)마다, 활성/비활성 플레이어가 **역할을 교체**합니다.
3. **활성 플레이어**가 `i`번째 게임을 플레이하여 `nums[i]` 점수를 획득합니다.

**첫 번째 플레이어의 총점 - 두 번째 플레이어의 총점** 을 반환하세요.

---

**예시 1**
- 입력: `nums = [1,2,3]`
- 출력: `0`
- 설명:
  - 게임 0: 점수가 홀수 → 두 번째 플레이어가 활성이 되어 1점 획득
  - 게임 1: 교체 없음 → 두 번째 플레이어가 2점 획득
  - 게임 2: 점수가 홀수 → 첫 번째 플레이어가 활성이 되어 3점 획득
  - 점수 차이: `3 - 3 = 0`

**예시 2**
- 입력: `nums = [2,4,2,1,2,1]`
- 출력: `4`
- 설명:
  - 게임 0~2: 첫 번째 플레이어가 `2+4+2 = 8`점 획득
  - 게임 3: 홀수 → 두 번째 플레이어 활성, 1점 획득
  - 게임 4: 교체 없음 → 두 번째 플레이어 2점 획득
  - 게임 5: 홀수로 교체 + 6번째 게임이라 교체 → 두 번째 플레이어 1점 획득
  - 점수 차이: `8 - 4 = 4`

**예시 3**
- 입력: `nums = [1]`
- 출력: `-1`
- 설명:
  - 게임 0: 홀수 → 두 번째 플레이어 활성, 1점 획득
  - 점수 차이: `0 - 1 = -1`

---

**제약 조건**
- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 1000`

---

## 요약

매 게임마다 **홀수 여부**와 **6번째 게임 여부** 두 조건으로 활성 플레이어가 바뀌고, 활성 플레이어가 점수를 가져감. 최종적으로 **1P 점수 - 2P 점수** 반환.

---

## 풀이 방향

1. `bool`로 현재 활성 플레이어 추적 (`true` = 1P, `false` = 2P)
2. 각 게임마다 순서대로:
   - 홀수면 swap
   - 6번째 게임(`i % 6 == 5`)이면 swap
   - 활성 플레이어 점수에 누적
3. 두 점수의 차이 반환


*/
