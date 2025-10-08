class Solution 
{
public:
    bool doesValidArrayExist(const vector<int>& derived) const
    {
        int total = 0;
        const size_t n = derived.size();
        assert(MIN_N <= n && n <= MAX_N);

        for (const auto num : derived)
        {
            assert(num == 0 or num == 1);
            total ^= num;
        }
        
        assert(total == 0 or total == 1);
        return (total == 0) ? true : false;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 100000,
    };
};


// https://leetcode.com/problems/neighboring-bitwise-xor/description/

/*
### 2683. 인접 비트 XOR

길이가 `n`인 0-인덱스 배열 `derived`는 길이가 `n`인 이진 배열 `original`의 인접한 값들을 비트 XOR (⊕) 연산하여 생성됩니다.

구체적으로, `[0, n - 1]` 범위의 각 인덱스 `i`에 대해:

*   `i = n - 1`인 경우, `derived[i] = original[i] ⊕ original[0]` 입니다.
*   그 외의 경우, `derived[i] = original[i] ⊕ original[i + 1]` 입니다.

배열 `derived`가 주어졌을 때, `derived`를 생성할 수 있는 유효한 이진 배열 `original`이 존재하는지 여부를 판단하는 것이 여러분의 과제입니다.

그러한 배열이 존재하면 `true`를, 그렇지 않으면 `false`를 반환하세요.

이진 배열은 오직 0과 1만을 포함하는 배열입니다.

**예시 1:**

**입력:** `derived = [1,1,0]`
**출력:** `true`
**설명:** `derived`를 생성하는 유효한 `original` 배열은 `[0,1,0]`입니다.
`derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1`
`derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1`
`derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0`

**예시 2:**

**입력:** `derived = [1,1]`
**출력:** `true`
**설명:** `derived`를 생성하는 유효한 `original` 배열은 `[0,1]`입니다.
`derived[0] = original[0] ⊕ original[1] = 1`
`derived[1] = original[1] ⊕ original[0] = 1`

**예시 3:**

**입력:** `derived = [1,0]`
**출력:** `false`
**설명:** `derived`를 생성하는 유효한 `original` 배열은 존재하지 않습니다.

**제약 조건:**

*   `n == derived.length`
*   `1 <= n <= 10^5`
*   `derived`의 값은 0 또는 1입니다.
*/
