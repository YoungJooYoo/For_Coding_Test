class Solution 
{
public:
    string findValidPair(const string &s) 
    {
        const size_t S_LENGTH = s.size();
        unordered_map<int, int> frequency;

        assert(S_LENGTH <= s.size() && S_LENGTH <= MAX_LENGTH);
        for (const char ch : s) 
        {
            assert(MIN_DIGIT <= ch && ch <= MAX_DIGIT);
            ++frequency[ch - '0'];
        }
        
        for (size_t i = 0; i < S_LENGTH - 1; ++i) 
        {
            const int firstDigit  = s[i] - '0';
            const int secondDigit = s[i + 1] - '0';
            
            if (s[i] != s[i + 1] && firstDigit == frequency[firstDigit] && secondDigit == frequency[secondDigit]) 
            {
                string result;
                result.push_back(s[i]);
                result.push_back(s[i + 1]);

                assert(result.size() == MIN_LENGTH);
                return result;
            }
        }
        
        return "";
    }

private:
    enum
    {
        MIN_LENGTH = 2,  // s의 최소 길이
        MAX_LENGTH = 100, // s의 최대 길이
        MIN_DIGIT  = '1',// s에 포함될 수 있는 최소 문자
        MAX_DIGIT  = '9' // s에 포함될 수 있는 최대 문자
    };
};


// https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/

/*


**3438. 문자열에서 인접한 유효한 숫자 쌍 찾기**  
Easy  
Hint

숫자로만 구성된 문자열 **s**가 주어집니다. 유효한 쌍(valid pair)은 **s**에서 인접한 두 숫자로 정의되며, 다음 조건을 만족해야 합니다:

- 첫 번째 숫자가 두 번째 숫자와 같지 않아야 합니다.
- 쌍에 포함된 각 숫자는 **s**에서 해당 숫자의 값과 정확히 같은 횟수만큼 나타나야 합니다.

왼쪽에서 오른쪽으로 문자열 **s**를 순회할 때, 처음으로 발견되는 유효한 쌍을 반환하세요. 만약 유효한 쌍이 존재하지 않으면, 빈 문자열을 반환합니다.

 

**Example 1:**

Input: s = "2523533"

Output: "23"

Explanation:

숫자 '2'는 2번 나타나고, 숫자 '3'은 3번 나타납니다. 쌍 "23"에 포함된 각 숫자는 **s**에서 해당 숫자의 값과 정확히 같은 횟수만큼 나타나므로, 출력은 "23"입니다.

---

**Example 2:**

Input: s = "221"

Output: "21"

Explanation:

숫자 '2'는 2번 나타나고, 숫자 '1'은 1번 나타납니다. 따라서 출력은 "21"입니다.

---

**Example 3:**

Input: s = "22"

Output: ""

Explanation:

유효한 인접 쌍이 존재하지 않습니다.

 

**Constraints:**

- 2 <= s.length <= 100  
- s는 '1'부터 '9'까지의 숫자로만 구성되어 있습니다.

*/
