class Solution 
{
public:
    int minimumCost(const string& target, const vector<string>& words, const vector<int>& costs) const
    {
        const int targetLength = target.size();
        const int wordsLength = words.size();
        vector<int> dp(targetLength + 1, INT_MAX);
        dp[0] = 0; // 초기 상태에서 빈 문자열을 만드는 비용은 0입니다.

        for (int i = 0; i < targetLength; ++i) // target의 각 위치에서 시작하여 word를 추가할 수 있는지 확인합니다.
        {
            if (dp[i] != INT_MAX)
            {
                for (size_t j = 0; j < wordsLength; ++j)
                {
                    const string& word = words[j];
                    const int wordCost = costs[j];
                    const int wordLength = word.size();
                    if (i + wordLength <= targetLength && target.substr(i, wordLength) == word)
                    {
                        dp[i + wordLength] = min(dp[i + wordLength], dp[i] + wordCost);
                    }
                }
            }
        }

        return (dp[targetLength] == INT_MAX) ? FAIL : dp[targetLength];
    }

private:
    enum { FAIL = -1 };
};

// https://leetcode.com/problems/construct-string-with-minimum-cost-easy/description/

/*


**3253. 최소 비용으로 문자열 만들기**  
난이도: 중간

---

문자열 `target`, 문자열 배열 `words`, 그리고 정수 배열 `costs`가 주어집니다. 배열 `words`와 `costs`는 같은 길이를 갖습니다.

빈 문자열 `s`가 있다고 가정합시다.

다음의 연산을 임의의 횟수(0번 포함)로 수행할 수 있습니다:

1. `[0, words.length - 1]` 범위에서 인덱스 `i`를 선택합니다.
2. `words[i]`를 문자열 `s`에 추가합니다.
3. 이 연산의 비용은 `costs[i]`입니다.

문자열 `s`가 `target`과 같아지기 위한 최소 비용을 반환하세요. 만약 문자열 `s`를 `target`과 같게 만들 수 없는 경우, `-1`을 반환하세요.

---

### 예제 1:

입력: 
```
target = "abcdef"
words = ["abdef","abc","d","def","ef"]
costs = [100, 1, 1, 10, 5]
```
출력: 
```
7
```
설명:

최소 비용은 다음과 같은 연산을 통해 얻을 수 있습니다:

1. 인덱스 1을 선택하여 `"abc"`를 `s`에 추가합니다 (비용 1). 결과 `s = "abc"`.
2. 인덱스 2를 선택하여 `"d"`를 `s`에 추가합니다 (비용 1). 결과 `s = "abcd"`.
3. 인덱스 4를 선택하여 `"ef"`를 `s`에 추가합니다 (비용 5). 결과 `s = "abcdef"`.

총 비용은 `1 + 1 + 5 = 7`입니다.

### 예제 2:

입력: 
```
target = "aaaa"
words = ["z", "zz", "zzz"]
costs = [1, 10, 100]
```
출력: 
```
-1
```
설명:

`target`과 동일한 문자열을 만들 수 없기 때문에 `-1`을 반환합니다.

---

### 제약 사항:

- `1 <= target.length <= 2000`
- `1 <= words.length == costs.length <= 50`
- `1 <= words[i].length <= target.length`
- `target`과 `words[i]`는 모두 소문자 영어 알파벳으로 구성됩니다.
- `1 <= costs[i] <= 10^5`

이 문제는 문자열 `target`을 만들기 위해 문자열 배열 `words`를 사용하고, 이를 가장 저렴한 비용으로 구성해야 하는 문제입니다. 만약 목표 문자열을 만들 수 없는 경우, `-1`을 반환해야 합니다.
*/
