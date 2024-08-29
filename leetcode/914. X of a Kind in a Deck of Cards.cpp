class Solution 
{
public:
    bool hasGroupsSizeX(const vector<int>& deck) 
    {
        unordered_map<int, int> freq;

        for (const auto& card : deck)
        {
            ++freq[card];
        }

        // 빈도 값들 중 첫 번째 값으로 GCD 초기화
        int gcd_value = 0;
        for (const auto& elem : freq)
        {
            gcd_value = gcd(gcd_value, elem.second);
            if (gcd_value == 1) // 만약 GCD가 1이라면 그룹 분할이 불가능함
            {
                return false;
            }
        }

        // 모든 카드 그룹이 GCD로 나누어지는 경우, true 반환
        return gcd_value >= 2;
    }
};

// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/

/*


### 문제 설명

당신은 `deck`이라는 정수 배열을 받았습니다. 이 배열에서 `deck[i]`는 `i`번째 카드에 적힌 숫자를 나타냅니다.

이제 다음 조건을 만족하도록 카드를 하나 이상의 그룹으로 나누고자 합니다:

1. 각 그룹에는 정확히 `x`장의 카드가 있어야 하며, 여기서 `x > 1`이어야 합니다.
2. 하나의 그룹 내 모든 카드는 동일한 숫자가 적혀 있어야 합니다.

위 조건을 만족하는 카드 그룹으로 나누는 것이 가능하다면 `true`를 반환하고, 불가능하다면 `false`를 반환하세요.

### 예제

**예제 1**:
- 입력: `deck = [1,2,3,4,4,3,2,1]`
- 출력: `true`
- 설명: 가능한 그룹 분할은 `[1,1]`, `[2,2]`, `[3,3]`, `[4,4]`입니다.

**예제 2**:
- 입력: `deck = [1,1,1,2,2,2,3,3]`
- 출력: `false`
- 설명: 가능한 그룹 분할이 없습니다.

### 제약 조건
- `1 <= deck.length <= 10^4`
- `0 <= deck[i] < 10^4`

이 문제는 주어진 카드 배열을 조건에 맞게 그룹화할 수 있는지 판단하는 문제입니다.

*/
