class Solution
{
public:
    vector<string> findAndReplacePattern(const vector<string>& words, const string& pattern) const
    {
        assert(MIN_PATTERN_LENGTH <= pattern.length() && pattern.length() <= MAX_PATTERN_LENGTH);
        assert(MIN_WORDS_COUNT <= words.size() && words.size() <= MAX_WORDS_COUNT);

        const string normalizedPattern = normalize(pattern);
        vector<string> result;

        for (const string& word : words)
        {
            if (normalize(word) == normalizedPattern)
            {
                result.push_back(word);
            }
        }

        return result;
    }

private:
    string normalize(string input) const
    {
        unordered_map<char, char> mapping;
        char nextChar = 'a';

        for (const char ch : input)
        {
            assert('a' <= ch && ch <= 'z');
            if (mapping.find(ch) == mapping.end())
            {
                mapping[ch] = nextChar++;
            }
        }
        for (char& ch : input)
        {
            ch = mapping[ch];
        }

        assert(mapping.size() <= input.size());
        return input;
    }

private:
    enum
    {
        MIN_PATTERN_LENGTH = 1,
        MAX_PATTERN_LENGTH = 20,
        MIN_WORDS_COUNT = 1,
        MAX_WORDS_COUNT = 50
    };
};

/*
https://leetcode.com/problems/find-and-replace-pattern/

### **890. 패턴 찾기 및 교체 (Find and Replace Pattern)**

문자열 리스트 `words`와 문자열 `pattern`이 주어집니다. `pattern`과 일치하는 `words[i]`의 리스트를 반환하십시오. 정답의 순서는 상관없습니다.

만약 패턴의 모든 문자 `x`를 `p(x)`로 교체했을 때 해당 단어를 얻을 수 있는 문자 순열(permutation) `p`가 존재한다면, 그 단어는 패턴과 **일치**한다고 합니다.

여기서 문자의 순열이란 문자 간의 **일대일 대응(bijection)**을 의미합니다. 즉, 모든 문자는 다른 문자에 매핑되며, **서로 다른 두 문자가 동일한 문자에 매핑되어서는 안 됩니다.**

---

**예제 1:**

*   **입력:** `words = ["abc","deq","mee","aqq","dkd","ccc"]`, `pattern = "abb"`
*   **출력:** `["mee","aqq"]`
*   **설명:**
    *   "mee"는 패턴과 일치합니다. {a $\to$ m, b $\to$ e, ...}와 같은 순열이 존재하기 때문입니다.
    *   "ccc"는 패턴과 일치하지 않습니다. {a $\to$ c, b $\to$ c, ...}는 순열이 아닙니다. a와 b가 동일한 문자 c에 매핑되기 때문입니다.

**예제 2:**

*   **입력:** `words = ["a","b","c"]`, `pattern = "a"`
*   **출력:** `["a","b","c"]`

---

**제약 조건:**

*   $1 \le pattern.length \le 20$
*   $1 \le words.length \le 50$
*   `words[i].length == pattern.length`
*   `pattern`과 `words[i]`는 소문자 영문자로만 구성됩니다.
*/
