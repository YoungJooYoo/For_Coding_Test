class Solution 
{
public:
    int numSpecialEquivGroups(const vector<string>& words) const
    {
        assert(MIN_WORDS_LENGTH <= words.size() && words.size() <= MAX_WORDS_LENGTH);
        const size_t WORD_LENGTH = words[0].size();
        unordered_map<string, int> freq;
        
        for (const auto word : words)
        {
            assert(MIN_WORD_LENGTH <= word.size() && word.size() <= MAX_WORD_LENGTH);
            assert(word.size() == WORD_LENGTH);
            ++freq[getStringKey(word)];
        }

        return static_cast<int>(freq.size());
    }

private:
    string getStringKey(const string& word) const
    {
        const size_t WORD_LENGTH = word.size();
        string even;
        string odd;
        
        for (size_t i = 0; i < WORD_LENGTH; ++i)
        {
            assert('a' <= word[i] && word[i] <= 'z');
            if (i % 2 == 0)
            {
                even += word[i];
            }
            else
            {
                odd += word[i];
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        return even + "|" + odd;
    }

private:
    enum
    {
        MIN_WORDS_LENGTH = 1,
        MAX_WORDS_LENGTH = 1000,

        MIN_WORD_LENGTH = 1,
        MAX_WORD_LENGTH = 20
    };
};

/*
https://leetcode.com/problems/groups-of-special-equivalent-strings/description/
### 893. 특수 동등 문자열 그룹 (Groups of Special-Equivalent Strings)

**문제 설명**  
모든 문자열의 길이가 동일한 문자열 배열 `words`가 주어집니다.

한 번의 이동에서, 문자열 `words[i]`의 **짝수 인덱스**에 있는 두 문자를 서로 바꾸거나, **홀수 인덱스**에 있는 두 문자를 서로 바꿀 수 있습니다.

임의의 횟수의 이동 후에 `words[i] == words[j]`가 되면, 두 문자열 `words[i]`와 `words[j]`는 **특수 동등(special-equivalent)**하다고 합니다.

예를 들어, `words[i] = "zzxy"`와 `words[j] = "xyzz"`는 `"zzxy" -> "xzzy" -> "xyzz"`와 같은 이동을 할 수 있으므로 특수 동등합니다.

`words`로부터의 **특수 동등 문자열 그룹**은 다음 조건을 만족하는 비어 있지 않은 `words`의 부분집합입니다:
1. 그룹 내의 모든 문자열 쌍은 특수 동등하며,
2. 그룹은 가능한 최대 크기입니다 (즉, 그룹에 속하지 않은 어떤 문자열 `words[i]`도 그룹 내 모든 문자열과 특수 동등하지 않습니다).

`words`로부터의 특수 동등 문자열 그룹의 개수를 반환하세요.

**예시 1:**
*   **입력:** `words = ["abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"]`
*   **출력:** `3`
*   **설명:**
    *   한 그룹은 `["abcd", "cdab", "cbad"]`입니다. 이들은 모두 서로 특수 동등하며, 나머지 문자열들은 이들과 특수 동등하지 않습니다.
    *   다른 두 그룹은 `["xyzz", "zzxy"]`와 `["zzyx"]`입니다.
    *   특히 `"zzxy"`는 `"zzyx"`와 특수 동등하지 않습니다.

**예시 2:**
*   **입력:** `words = ["abc", "acb", "bac", "bca", "cab", "cba"]`
*   **출력:** `3`

**제약 사항:**
*   `1 <= words.length <= 1000`
*   `1 <= words[i].length <= 20`
*   `words[i]`는 소문자 영어 알파벳으로만 구성됩니다.
*   모든 문자열의 길이는 동일합니다.

---

**힌트:**
*   특수 동등 조건은 문자열의 짝수 인덱스 문자들끼리 자유롭게 재배열하고, 홀수 인덱스 문자들끼리 자유롭게 재배열할 수 있다는 의미입니다.
*   따라서 각 문자열을 **짝수 인덱스 문자들의 정렬된 순열**과 **홀수 인덱스 문자들의 정렬된 순열**로 표현할 수 있습니다.
*   두 문자열이 특수 동등하기 위해서는 이 두 순열이 동일해야 합니다.
*   이 표현을 기준으로 그룹화하여 고유한 그룹의 개수를 세면 됩니다.
*/
