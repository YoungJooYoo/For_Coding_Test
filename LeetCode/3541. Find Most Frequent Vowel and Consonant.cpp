class Solution 
{
public:
    int maxFreqSum(const string& s) 
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        unordered_map<char, int> freqVowel;
        unordered_map<char, int> freqNonVowel;
        int maxVowelCount = 0;
        int maxNonVowelCount = 0;

        for (const auto ch : s)
        {
            assert('a' <= ch && ch <= 'z');
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                ++freqVowel[ch];
                maxVowelCount = max(maxVowelCount, freqVowel[ch]);
            }
            else
            {
                ++freqNonVowel[ch];
                maxNonVowelCount = max(maxNonVowelCount, freqNonVowel[ch]);
            }
        }

  
        return maxVowelCount + maxNonVowelCount;    
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
    };
};

// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/
/*
**3545. 최대 K개의 서로 다른 문자로 만들기 위한 최소 삭제 횟수**

**난이도:** 쉬움

**문제 설명:**
소문자 영어로만 이루어진 문자열 **s**와 정수 **k**가 주어집니다.
문자열에서 문자를 몇 개 삭제(0개도 가능)하여, 최종 문자열에 등장하는 **서로 다른 문자**의 개수가 **최대 k**가 되도록 하려고 합니다.
이때, 이를 위해 삭제해야 하는 **최소 문자 수**를 구하세요.

---

**예제 1:**

* **입력:** s = `"abc"`, k = 2
* **출력:** 1
* **설명:**
  원본 문자열에는 `a, b, c` 세 가지 문자가 있습니다.
  서로 다른 문자를 최대 2개만 남겨야 하므로, 세 문자 중 하나(예: 모두 `c` 삭제)를 통째로 삭제하면 됩니다.
  따라서 최소 삭제 횟수는 1입니다.

---

**예제 2:**

* **입력:** s = `"aabb"`, k = 2
* **출력:** 0
* **설명:**
  이미 `a`와 `b` 두 가지 문자만 등장하므로, 삭제가 필요 없습니다.

---

**예제 3:**

* **입력:** s = `"yyyzz"`, k = 1
* **출력:** 2
* **설명:**
  `y`와 `z` 두 가지 문자가 등장하며, 각각 3번, 2번 씩 나옵니다.
  서로 다른 문자를 1개만 남겨야 하므로, `z`를 모두 삭제(2회)하거나 `y`를 모두 삭제(3회)해야 합니다.
  최소 삭제 횟수는 2입니다.

---

**제약 조건:**

* $1 \le s.\text{length} \le 16$
* $1 \le k \le 16$
* $s$는 소문자 영어 알파벳만으로 구성됩니다.

*/
