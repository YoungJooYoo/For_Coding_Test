class Solution 
{
public:
    string mapWordWeights(const vector<string>& words, const vector<int>& weights) const
    {
        assert(MIN_LENGTH <= words.size() && words.size() <= MAX_LENGTH);
        assert(weights.size() == WEIGHTS_LENGTH);

        string result; 

        for (const auto& word : words)
        {
            assert(MIN_WORD_LENGTH <= word.size() && word.size() <= MAX_WORD_LENGTH);
            int sum = 0;
            for (const auto ch : word)
            {
                assert('a' <= ch && ch <= 'z');
                const size_t idx = ch - 'a';
                sum += weights[idx];
            }
            sum %= WEIGHTS_LENGTH;
            result.push_back(mReversedAlphabet[sum]);
        }

        return result;
    }

private:
    static const vector<char> mReversedAlphabet;

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_WORD_LENGTH = 1,
        MAX_WORD_LENGTH = 10,
        WEIGHTS_LENGTH = 26,
        MIN_WEIGHT = 1,
        MAX_WEIGHT = 100
    };
};

const vector<char> Solution::mReversedAlphabet = 
{
    'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n',
    'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'
};
/*
### 3838. 가중치 단어 매핑 (Weighted Word Mapping)

**문제 설명**  
소문자 영어 알파벳으로 이루어진 단어들을 담은 문자열 배열 `words`가 주어집니다.

또한 길이가 26인 정수 배열 `weights`가 주어지는데, `weights[i]`는 i번째 소문자 영어 알파벳의 가중치를 나타냅니다. (예: `weights[0]`은 'a'의 가중치, `weights[1]`은 'b'의 가중치, ..., `weights[25]`는 'z'의 가중치)

단어의 가중치는 그 단어에 포함된 각 문자들의 가중치를 모두 더한 값으로 정의됩니다.

각 단어에 대해, 그 가중치를 26으로 나눈 나머지를 구한 후, 그 결과를 **역순 알파벳 매핑**을 사용하여 소문자 영어 알파벳으로 변환합니다. (0 -> 'z', 1 -> 'y', ..., 25 -> 'a')

모든 단어에 대해 변환된 문자들을 순서대로 이어붙여 하나의 문자열을 만들어 반환하세요.

**예시 1:**
*   **입력:** `words = ["abcd","def","xyz"]`, `weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]`
*   **출력:** `"rij"`
*   **설명:**
    *   "abcd"의 가중치는 `5 + 3 + 12 + 14 = 34`입니다. 이를 26으로 나눈 나머지는 `34 % 26 = 8`이고, 8은 'r'로 매핑됩니다.
    *   "def"의 가중치는 `14 + 1 + 2 = 17`입니다. 나머지는 `17 % 26 = 17`이고, 17은 'i'로 매핑됩니다.
    *   "xyz"의 가중치는 `7 + 7 + 2 = 16`입니다. 나머지는 `16 % 26 = 16`이고, 16은 'j'로 매핑됩니다.
    *   따라서 변환된 문자들을 이어붙인 문자열은 `"rij"`입니다.

**예시 2:**
*   **입력:** `words = ["a","b","c"]`, `weights = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]`
*   **출력:** `"yyy"`
*   **설명:**
    *   각 단어의 가중치는 모두 1입니다. 나머지는 `1 % 26 = 1`이고, 1은 'y'로 매핑됩니다.
    *   따라서 결과 문자열은 `"yyy"`입니다.

**예시 3:**
*   **입력:** `words = ["abcd"]`, `weights = [7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5]`
*   **출력:** `"g"`
*   **설명:**
    *   "abcd"의 가중치는 `7 + 5 + 3 + 4 = 19`입니다. 나머지는 `19 % 26 = 19`이고, 19는 'g'로 매핑됩니다.
    *   따라서 결과 문자열은 `"g"`입니다.

**제약 사항:**
*   `1 <= words.length <= 100`
*   `1 <= words[i].length <= 10`
*   `weights.length == 26`
*   `1 <= weights[i] <= 100`
*   `words[i]`는 소문자 영어 알파벳으로만 구성됩니다.

---

**생각해 볼 점:**
1.  주어진 `weights` 배열의 인덱스와 알파벳의 매핑 관계를 어떻게 설정할지 명확히 해야 합니다. (인덱스 0 → 'a', 인덱스 1 → 'b', ...)
2.  역순 매핑은 `'z' - (가중치 % 26)`과 같은 방식으로 구현할 수 있습니다. 직접 변환 공식을 생각해 보세요.
3.  배열의 범위가 크지 않으므로, 각 단어에 대해 문자별 가중치를 순회하며 합을 구하는 방식으로 해결할 수 있습니다.
*/
