class Solution
{
public:
    int maxDistance(const vector<string>& words) const
    {
        assert(MIN_LENGTH <= words.size() && words.size() <=MAX_LENGTH);

        const size_t LENGTH = words.size();
        int maxDistance = 0;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            const string& WORD1 = words[i];
            assert(MIN_LENGTH <= WORD1.size() && WORD1.size() <= MAX_LENGTH);
            for (size_t j = i + 1; j < LENGTH; ++j)
            {
                const string& WORD2 = words[j];
                assert(MIN_LENGTH <= WORD2.size() && WORD2.size() <= MAX_LENGTH);
                if (WORD1 != WORD2)
                {
                    const int currentDistance = static_cast<int>((j - i) + DIST_OFFSET);
                    maxDistance = max(maxDistance, currentDistance);
                }
            }
        }

        assert(maxDistance >= 0);
        return maxDistance;
    }

private:
    enum
    {
        DIST_OFFSET = 1,      // (j - i) 에 더하는 고정 오프셋
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MAX_WORD_LENGTH = 10,
    };
};

// https://leetcode.com/problems/maximum-distance-between-unequal-words-in-array-i/description/

/*
## 3696. 배열에서 서로 다른 단어 사이의 최대 거리 I

문자열 배열 `words`가 주어집니다.

다음 조건을 만족하는 서로 다른 두 인덱스 `i`와 `j` 사이의 최대 거리를 찾으세요.

*   `words[i] != words[j]`
*   거리는 `j - i + 1`로 정의됩니다.

이러한 모든 쌍 중에서 최대 거리를 반환하세요. 유효한 쌍이 없으면 0을 반환하세요.

**예제 1:**

**입력:** `words = ["leetcode","leetcode","codeforces"]`
**출력:** 3
**설명:**
이 예제에서 `words[0]`과 `words[2]`는 같지 않으며, 최대 거리는 2 - 0 + 1 = 3입니다.

**예제 2:**

**입력:** `words = ["a","b","c","a","a"]`
**출력:** 4
**설명:**
이 예제에서 `words[1]`과 `words[4]`는 가장 큰 거리인 4 - 1 + 1 = 4를 가집니다.

**예제 3:**

**입력:** `words = ["z","z","z"]`
**출력:** 0
**설명:**
이 예제에서는 모든 단어가 같으므로 정답은 0입니다.

**제약 조건:**

*   `1 <= words.length <= 100`
*   `1 <= words[i].length <= 10`
*   `words[i]`는 영문 소문자로 구성됩니다.
*/
