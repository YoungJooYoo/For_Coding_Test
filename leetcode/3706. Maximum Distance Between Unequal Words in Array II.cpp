class Solution 
{
public:
    int maxDistance(const vector<string>& words) const
    {
        const size_t LENGTH = words.size();
        const string& FIRST_WORD = words[0];
        const string& LAST_WORD = words[LENGTH - 1];
        int maxDistance = 0;

        for (int i = 0; i < LENGTH; ++i)
        {
            const auto& WORD = words[i];
            assert(MIN_LENGTH <=  WORD.size() && WORD.size() <= MAX_WORD_LENGTH);
            if (WORD != LAST_WORD)
            {
                const int DISTANCE = LENGTH - 1 - i + 1;
                assert(DISTANCE > 0);
                maxDistance = max(maxDistance, DISTANCE);
                break;
            }
        }

        for (int i = LENGTH - 1; i >= 0; --i)
        {
            const auto& WORD = words[i];
            assert(MIN_LENGTH <=  WORD.size() && WORD.size() <= MAX_WORD_LENGTH);
            if (WORD != FIRST_WORD)
            {
                const int DISTANCE = i + 1;
                assert(DISTANCE > 0);
                maxDistance = max(maxDistance, DISTANCE);
                break;
            }
        }

        assert(MIN_LENGTH <= LENGTH && LENGTH <= MAX_LENGTH);
        assert(maxDistance >= 0);

        return maxDistance;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MAX_WORD_LENGTH = 10
    };
};

// https://leetcode.com/problems/maximum-distance-between-unequal-words-in-array-ii/description/

/*


### 3706. 배열에서 서로 다른 단어 간의 최대 거리 II

**힌트**
문자열 배열 `words`가 주어집니다.

다음 조건을 만족하는 두 개의 서로 다른 인덱스 `i`와 `j` 사이의 최대 거리를 찾으세요:

*   `words[i] != words[j]`
*   거리는 `j - i + 1`로 정의됩니다.

이러한 모든 쌍 중에서 최대 거리를 반환하세요. 만약 유효한 쌍이 없다면 0을 반환합니다.

**예시 1:**

**입력:** `words = ["leetcode","leetcode","codeforces"]`
**출력:** `3`
**설명:**
이 예시에서, `words[0]`과 `words[2]`는 같지 않으며, 최대 거리는 2 - 0 + 1 = 3입니다.

**예시 2:**

**입력:** `words = ["a","b","c","a","a"]`
**출력:** `4`
**설명:**
이 예시에서 `words[1]`과 `words[4]`가 4 - 1 + 1 = 4로 가장 큰 거리를 가집니다.

**예시 3:**

**입력:** `words = ["z","z","z"]`
**출력:** `0`
**설명:**
이 예시에서는 모든 단어가 같으므로, 답은 0입니다.

**제약 조건:**

*   `1 <= words.length <= 10^5`
*   `1 <= words[i].length <= 10`
*   `words[i]`는 영문 소문자로만 구성됩니다.
*/
