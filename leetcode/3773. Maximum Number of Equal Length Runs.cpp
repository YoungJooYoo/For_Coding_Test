class Solution
{
public:
    int maxSameLengthRuns(const string& s) const
    {
        assert(s.size() >= MIN_LEN &&  s.size() <= MAX_LEN);

        const size_t LENGTH = s.size();
        unordered_map<int, int> freq;
        int result = 0;

        for (int i = 1, j = 0; i <= LENGTH; ++i)
        {
            // assert('a' <= s[i] && s[i] <= 'z');
            if (i == LENGTH || s[i] != s[j])
            {
                const int runLen = i - j;
                const int newCount = ++freq[runLen];
                result = max(result, newCount);
                j = i; // next run starts at i
                assert(runLen >= 0 && newCount >= 0);
            }
        }

        assert(result >= 0);
        return result;
    }
private:
    enum 
    { 
        MIN_LEN = 1, 
        MAX_LEN = 1000000 
    };
};


// https://leetcode.com/problems/maximum-number-of-equal-length-runs/description/

/*

### 3773. 길이가 같은 런(Run)의 최대 개수

**힌트**
소문자 영문자로 구성된 문자열 `s`가 주어집니다.

`s`에서의 **'런(run)'**은 더 이상 확장할 수 없는, 동일한 문자들로 이루어진 부분 문자열을 의미합니다. 예를 들어, "hello"의 런들은 "h", "e", "ll", "o"입니다.

당신은 `s`에서 **길이가 같은** 런들을 선택할 수 있습니다.

`s`에서 선택할 수 있는 런의 최대 개수를 나타내는 정수를 반환하세요.

**예시 1:**

**입력:** `s = "hello"`
**출력:** `3`
**설명:**
`s`의 런들은 "h", "e", "ll", "o"입니다. 길이가 1로 동일한 "h", "e", "o"를 선택할 수 있습니다.

**예시 2:**

**입력:** `s = "aaabaaa"`
**출력:** `2`
**설명:**
`s`의 런들은 "aaa", "b", "aaa"입니다. 길이가 3으로 동일한 "aaa"와 "aaa"를 선택할 수 있습니다.

**제약 조건:**

*   `1 <= s.length <= 10^5`
*   `s`는 소문자 영문자로만 구성됩니다.
*/
