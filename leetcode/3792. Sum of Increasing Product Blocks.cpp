class Solution
{
public:
    int sumOfBlocks(const int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);
        int totalSum = 0;
        int currentValue = START_VALUE;

        for (int blockIndex = 1; blockIndex <= n; ++blockIndex)
        {
            long long blockProduct = 1;
            for (int count = 0; count < blockIndex; ++count)
            {
                blockProduct = (blockProduct * (currentValue % MODULO)) % MODULO;
                ++currentValue;
            }
            totalSum = (totalSum + static_cast<int>(blockProduct)) % MODULO;
        }

        return totalSum;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 1000,
        START_VALUE = 1,
        MODULO = 1000000000 + 7
    };
};

// https://leetcode.com/problems/sum-of-increasing-product-blocks/

/*
요청하신 문제에 대한 국문 번역입니다.

---

### **92. 증가하는 곱 블록의 합 (Sum of Increasing Product Blocks)**

정수 `n`이 주어집니다.

수열이 다음과 같이 형성됩니다:

*   **1번째 블록**은 1을 포함합니다.
*   **2번째 블록**은 2 * 3을 포함합니다.
*   **i번째 블록**은 (이전 블록에 이어지는) 다음 `i`개의 연속된 정수들의 곱입니다.

`F(n)`을 처음 `n`개 블록의 합이라고 합시다.

`F(n)`을 $10^9 + 7$로 나눈 나머지를 반환하십시오.

**예제 1:**

*   **입력:** `n = 3`
*   **출력:** `127`
*   **설명:**
    *   블록 1: 1
    *   블록 2: 2 * 3 = 6
    *   블록 3: 4 * 5 * 6 = 120
    *   `F(3)` = 1 + 6 + 120 = 127

**예제 2:**

*   **입력:** `n = 7`
*   **출력:** `6997165`
*   **설명:**
    *   블록 1: 1
    *   블록 2: 2 * 3 = 6
    *   블록 3: 4 * 5 * 6 = 120
    *   블록 4: 7 * 8 * 9 * 10 = 5040
    *   블록 5: 11 * 12 * 13 * 14 * 15 = 360360
    *   블록 6: 16 * 17 * 18 * 19 * 20 * 21 = 39070080
    *   블록 7: 22 * 23 * 24 * 25 * 26 * 27 * 28 = 5967561600
    *   `F(7)` = 6006997207 % ($10^9 + 7$) = 6997165
*/
