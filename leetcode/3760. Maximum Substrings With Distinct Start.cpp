class Solution 
{
public:
    int maxDistinct(const string& s) const 
    {
        assert(MIN_LNEGTH <= s.size() && s.size() <= MAX_LENGTH);
        const  unordered_set<char> st(s.begin(),s.end());
        return st.size();
    }

private:
    enum
    {
        MIN_LNEGTH = 1,
        MAX_LENGTH = 100000
    };
};

/*
https://leetcode.com/problems/maximum-substrings-with-distinct-start/description/

### 3760. 서로 다른 시작 문자를 가진 최대 부분 문자열

**힌트**
소문자 영문자로 구성된 문자열 `s`가 주어집니다.

`s`를 여러 개의 부분 문자열로 분할할 때, **각 부분 문자열이 서로 다른 문자로 시작하도록** (즉, 어떤 두 부분 문자열도 같은 문자로 시작하지 않도록) 만들 수 있는 부분 문자열의 최대 개수를 반환하세요.

**예시 1:**

**입력:** `s = "abab"`
**출력:** `2`
**설명:**
"abab"를 "a"와 "bab"로 분할합니다.
각 부분 문자열은 서로 다른 문자, 즉 'a'와 'b'로 시작합니다. 따라서 답은 2입니다.

**예시 2:**

**입력:** `s = "abcd"`
**출력:** `4`
**설명:**
"abcd"를 "a", "b", "c", "d"로 분할합니다.
각 부분 문자열은 서로 다른 문자로 시작합니다. 따라서 답은 4입니다.

**예시 3:**

**입력:** `s = "aaaa"`
**출력:** `1`
**설명:**
"aaaa"의 모든 문자는 'a'입니다.
'a'로 시작하는 부분 문자열은 오직 하나만 있을 수 있습니다. 따라서 답은 1입니다.

**제약 조건:**

*   `1 <= s.length <= 10^5`
*   `s`는 소문자 영문자로만 구성됩니다.
*/
