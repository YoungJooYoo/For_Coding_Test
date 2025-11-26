class Solution
{
public:
    long long sumAndMultiply(int n) const
    {
        assert(n >= MIN_N && n <= MAX_N);

        const string s = to_string(n);
        string xStr;
        long long sum = 0;
 
        for (const char ch : s)
        {
            if (ch != '0')
            {
                xStr.push_back(ch);;
            }
            sum += ch - '0';
        }

        return (xStr.empty() == true) ? 0 : stoll(xStr) * sum;
    }

private:
    enum
    {
        MIN_N = 0,
        MAX_N = 1000000000
    };
};

// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/

/*
네, 해당 문제를 한국어로 번역해 드리겠습니다.

### 3754. 0이 아닌 숫자 연결 및 합으로 곱하기 I

**힌트**
정수 `n`이 주어집니다.

`n`의 모든 0이 아닌 숫자들을 원래 순서대로 연결하여 새로운 정수 `x`를 만드세요. 만약 0이 아닌 숫자가 없다면, `x = 0`입니다.

`sum`은 `x`의 각 자리 숫자의 합이라고 합시다.

`x * sum`의 값을 나타내는 정수를 반환하세요.

**예시 1:**

**입력:** `n = 10203004`
**출력:** `12340`
**설명:**
0이 아닌 숫자들은 1, 2, 3, 4입니다. 따라서 `x = 1234`입니다.
`x`의 각 자리 숫자의 합은 `sum = 1 + 2 + 3 + 4 = 10`입니다.
그러므로 답은 `x * sum = 1234 * 10 = 12340`입니다.

**예시 2:**

**입력:** `n = 1000`
**출력:** `1`
**설명:**
0이 아닌 숫자는 1입니다. 따라서 `x = 1`이고 `sum = 1`입니다.
그러므로 답은 `x * sum = 1 * 1 = 1`입니다.

**제약 조건:**

*   `0 <= n <= 10^9`
*/
