class Solution
{
public:
    vector<int> sumAndMultiply(const string& s, const vector<vector<int>>& queries)
    {
        const int length = static_cast<int>(s.size());
        vector<long long> digits(length);
        vector<long long> prefixSum(length);
        vector<long long> px(length);
        vector<int> cnt(length);
        vector<long long> pow10(length + 1);

        assert(length > 0);
        for (int i = 0; i < length; ++i)    // digits
        {
            digits[i] = static_cast<long long>(s[i] - '0');
        }

        prefixSum[0] = digits[0];           // sum prefix
        for (int i = 1; i < length; ++i)
        {
            prefixSum[i] = prefixSum[i - 1] + digits[i];
        }

        px[0] = (digits[0] == 0 ? 0 : digits[0]); // X prefix
        cnt[0] = (digits[0] == 0 ? 0 : 1);
        for (int i = 1; i < length; ++i)
        {
            if (digits[i] != 0)
            {
                px[i] = (px[i - 1] * 10 + digits[i]) % MODULO;
                cnt[i] = cnt[i - 1] + 1;
            }
            else
            {
                px[i] = px[i - 1];
                cnt[i] = cnt[i - 1];
            }
        }

        pow10[0] = 1;                       // pow10
        for (int i = 1; i <= length; ++i)
        {
            pow10[i] = (pow10[i - 1] * 10) % MODULO;
        }

        vector<int> result;
        result.reserve(queries.size());

        for (const vector<int>& q : queries)
        {
            const int l = q[0];
            const int r = q[1];
            assert(q.size() == 2);
            assert(l >= 0);
            assert(r >= l && r < length);

            const long long sum = (l == 0)
                ? prefixSum[r]
                : prefixSum[r] - prefixSum[l - 1];

            long long x = px[r];
            if (l > 0)
            {
                const int c = cnt[r] - cnt[l - 1];
                if (c > 0)
                {
                    x = (x - (px[l - 1] * pow10[c]) % MODULO + MODULO) % MODULO;
                }
                else
                {
                    x = 0;
                }
            }

            const long long finalValue = (x * (sum % MODULO)) % MODULO;
            result.push_back(static_cast<int>(finalValue));
        }

        return result;
    }

private:
    enum
    {
        MODULO = 1000000007
    };
};

// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/description/
/*
### 3756. 0이 아닌 숫자 연결 및 합으로 곱하기 II

**힌트**  
문자열 `s`가 주어집니다. `s`의 길이는 `m`이며, 숫자만으로 구성됩니다. 또한 2차원 정수 배열 `queries`가 주어지며, `queries[i] = [li, ri]`입니다.

각 `queries[i]`에 대해, `s[li..ri]` 서브스트링을 추출합니다. 다음 작업을 수행하세요:

1. 서브스트링에서 **0이 아닌 모든 숫자를 원래 순서대로 연결**하여 새로운 정수 `x`를 만듭니다. 0이 아닌 숫자가 없다면 `x = 0`입니다.
2. `sum`은 `x`의 각 자릿수의 합입니다. 답은 `x * sum`입니다.

`answer[i]`가 `i`번째 쿼리에 대한 답인 정수 배열 `answer`을 반환하세요.

답이 매우 클 수 있으므로, **10^9 + 7로 나눈 나머지**를 반환하세요.

---

**예시 1:**

**입력:** `s = "10203004", queries = [[0,7],[1,3],[4,6]]`  
**출력:** `[12340, 4, 9]`  
**설명:**  
- `s[0..7] = "10203004"` → 0이 아닌 숫자: `1,2,3,4` → `x = 1234`, `sum = 1+2+3+4 = 10` → `1234 * 10 = 12340`  
- `s[1..3] = "020"` → 0이 아닌 숫자: `2` → `x = 2`, `sum = 2` → `2 * 2 = 4`  
- `s[4..6] = "300"` → 0이 아닌 숫자: `3` → `x = 3`, `sum = 3` → `3 * 3 = 9`  

**예시 2:**

**입력:** `s = "1000", queries = [[0,3],[1,1]]`  
**출력:** `[1, 0]`  
**설명:**  
- `s[0..3] = "1000"` → 0이 아닌 숫자: `1` → `x = 1`, `sum = 1` → `1 * 1 = 1`  
- `s[1..1] = "0"` → 0이 아닌 숫자 없음 → `x = 0`, `sum = 0` → `0 * 0 = 0`  

**예시 3:**

**입력:** `s = "9876543210", queries = [[0,9]]`  
**출력:** `[444444137]`  
**설명:**  
- `s[0..9] = "9876543210"` → 0이 아닌 숫자: `9,8,7,6,5,4,3,2,1` → `x = 987654321`, `sum = 45` → `987654321 * 45 = 44444444445`  
- `44444444445 % (10^9 + 7) = 444444137`  

---

**제약 조건:**  
- `1 <= m == s.length <= 10^5`  
- `s`는 숫자만으로 구성됩니다.  
- `1 <= queries.length <= 10^5`  
- `queries[i] = [li, ri]`  
- `0 <= li <= ri < m`
*/
