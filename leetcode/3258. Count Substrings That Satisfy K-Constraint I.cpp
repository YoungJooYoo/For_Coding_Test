class Solution 
{
public:
    int countKConstraintSubstrings(const string& s, const int k) 
    {
        const size_t LENGTH = s.size();
        int count = 0;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            string subStr;
            for (size_t j = i; j < LENGTH; ++j)
            {
                subStr.push_back(s[j]);
                const size_t zeroCount = countZero(subStr);
                const size_t oneCount = subStr.size() - zeroCount;
                if (!(zeroCount > k && oneCount > k)) ++count;
            }
        }

        return count;
    }

private:
    size_t countZero(const string& subStr)
    {
        size_t count = 0;

        for (const auto& ch : subStr)
        {
            if (ch == '0') ++count;
        }

        return count;
    }
};

// https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/description/

/*

### 문제 번역:

**3258. K-제약 조건을 만족하는 부분 문자열의 개수**

**난이도:** 쉬움

**힌트:**  
이진 문자열 `s`와 정수 `k`가 주어집니다.

이진 문자열이 `k-제약 조건`을 만족하려면 다음 조건 중 하나를 충족해야 합니다:
- 문자열에 포함된 '0'의 개수가 최대 `k`여야 합니다.
- 문자열에 포함된 '1'의 개수가 최대 `k`여야 합니다.

`k-제약 조건`을 만족하는 `s`의 부분 문자열의 수를 나타내는 정수를 반환하세요.

### 예제 1:

**입력:**
- `s = "10101"`
- `k = 1`

**출력:** `12`

**설명:**  
`"1010"`, `"10101"`, `"0101"`을 제외한 모든 `s`의 부분 문자열이 `k-제약 조건`을 만족합니다.

### 예제 2:

**입력:**
- `s = "1010101"`
- `k = 2`

**출력:** `25`

**설명:**  
길이가 5보다 큰 부분 문자열을 제외한 모든 부분 문자열이 `k-제약 조건`을 만족합니다.

### 예제 3:

**입력:**
- `s = "11111"`
- `k = 1`

**출력:** `15`

**설명:**  
`s`의 모든 부분 문자열이 `k-제약 조건`을 만족합니다.

### 제약 조건:
- `1 <= s.length <= 50`
- `1 <= k <= s.length`
- `s[i]`는 '0' 또는 '1'입니다.

### 문제 설명:

주어진 이진 문자열에서 부분 문자열 중 '0'의 개수 또는 '1'의 개수가 최대 `k`를 넘지 않는 부분 문자열의 개수를 세는 문제입니다. 각 부분 문자열을 검사하여 이 조건을 만족하는지 확인한 후, 그 수를 계산해야 합니다. 이 문제에서는 주어진 문자열에서 모든 가능한 부분 문자열을 생성하고, 각 부분 문자열이 `k-제약 조건`을 만족하는지 확인하는 방식으로 접근할 수 있습니다.
*/
