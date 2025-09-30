class Solution
{
public:
    vector<int> decimalRepresentation(int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);

        vector<int> result;
        long long weight = 1;

        while (n > 0)
        {
            const int remainder = n % MAX_DIGITS;
            n /= MAX_DIGITS;
            if (remainder > 0)
            {
                result.push_back(remainder * weight);
            }
            weight *= MAX_DIGITS;
        }

        assert(result.size() <= MAX_DIGITS);
        ranges::reverse(result);
        return result;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 1000000000,
        MAX_DIGITS = 10
    };
};

// https://leetcode.com/problems/compute-decimal-representation/description/

/*


### 3697. 십진수 표현 계산

**힌트**
양의 정수 `n`이 주어집니다.

어떤 양의 정수가 1부터 9까지의 한 자리 숫자와 10의 음이 아닌 거듭제곱의 곱으로 이루어져 있을 때, 이를 **10진수 구성 요소(base-10 component)**라고 합니다. 예를 들어, 500, 30, 7은 10진수 구성 요소이지만, 537, 102, 11은 그렇지 않습니다.

`n`을 10진수 구성 요소만의 합으로 표현하되, **가능한 한 가장 적은 수의 구성 요소를 사용**해야 합니다.

이 10진수 구성 요소들을 **내림차순**으로 담은 배열을 반환하세요.

**예시 1:**

**입력:** `n = 537`
**출력:** `[500, 30, 7]`
**설명:**
537은 `500 + 30 + 7`로 표현할 수 있습니다. 3개보다 적은 수의 10진수 구성 요소 합으로 537을 표현하는 것은 불가능합니다.

**예시 2:**

**입력:** `n = 102`
**출력:** `[100, 2]`
**설명:**
102는 `100 + 2`로 표현할 수 있습니다. 102는 10진수 구성 요소가 아니므로, 2개의 10진수 구성 요소가 필요합니다.

**예시 3:**

**입력:** `n = 6`
**출력:** `[6]`
**설명:**
6은 그 자체가 10진수 구성 요소입니다.

**제약 조건:**

*   `1 <= n <= 10^9`
*/
