
class Solution 
{
public:
    int maxBottlesDrunk(const int numBottles, const int numExchange) const
    {
        
        assert(numBottles >= MIN && numBottles <= MAX);
        assert(numExchange >= MIN && numExchange <= MAX);

        int totalDrunk = numBottles;
        int emptyBottles = numBottles;
        int exchange = numExchange;

        while (emptyBottles >= exchange) 
        {
            const int newFull = 1;                    // 한 번 교환할 때마다 1병만 가능
            const int usedEmpty = exchange;           // 사용한 빈 병 개수
            const int newEmpty = newFull;             // 새 병을 마신 뒤 생기는 빈 병

            emptyBottles = emptyBottles - usedEmpty + newEmpty;
            totalDrunk += newFull;
            ++exchange;                               // 교환 비용 증가
        }

        return totalDrunk;
    }

private:
    enum 
    { 
        MIN = 1, 
        MAX = 100 
    };
};

// https://leetcode.com/problems/water-bottles-ii/

/*
## 3100. 물병 II

두 정수 `numBottles`와 `numExchange`가 주어집니다.

`numBottles`는 처음에 가지고 있는 가득 찬 물병의 수를 나타냅니다. 한 번의 연산에서 다음 중 하나의 작업을 수행할 수 있습니다:

- 원하는 만큼의 가득 찬 물병을 마셔서 빈 병으로 만듭니다.
- `numExchange`개의 빈 병을 1개의 가득 찬 물병으로 교환합니다. 그런 다음 `numExchange`의 값을 1 증가시킵니다.

**참고:** 동일한 `numExchange` 값으로 여러 번에 걸쳐 빈 병을 교환할 수 없습니다. 예를 들어, `numBottles == 3`이고 `numExchange == 1`인 경우, 빈 물병 3개를 가득 찬 병 3개로 한 번에 교환할 수 없습니다.

마실 수 있는 물병의 최대 개수를 반환하세요.

**예제 1:**

**입력:** `numBottles = 13`, `numExchange = 6`  
**출력:** 15  
**설명:** 위 표는 가득 찬 물병 수, 빈 물병 수, `numExchange` 값, 마신 병 수를 보여줍니다.

**예제 2:**

**입력:** `numBottles = 10`, `numExchange = 3`  
**출력:** 13  
**설명:** 위 표는 가득 찬 물병 수, 빈 물병 수, `numExchange` 값, 마신 병 수를 보여줍니다.

**제약 조건:**

- `1 <= numBottles <= 100`
- `1 <= numExchange <= 100`
*/
