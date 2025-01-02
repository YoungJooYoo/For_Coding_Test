class Solution 
{
public:
    vector<int> vowelStrings(const vector<string>& words, const vector<vector<int>>& queries) 
    {
        // Step 1: 모음으로 시작하고 끝나는 문자열을 계산하여 누적 합(prefix sum) 생성
        const int WORDS_LENGTH = words.size();
        vector<int> prefixSum(WORDS_LENGTH + 1, 0);

        for (int i = 0; i < WORDS_LENGTH; ++i)
        {
            if (isVowelString(words[i]) == true)
            {
                prefixSum[i + 1] = prefixSum[i] + 1;
            }
            else
            {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        // Step 2: 각 쿼리를 처리하여 결과 계산
        vector<int> result;
        for (const auto& query : queries)
        {
            const int start = query[0];
            const int end = query[1];
            assert(start < WORDS_LENGTH && end < WORDS_LENGTH);

            // 누적 합을 활용해 범위의 값 계산
            result.push_back(prefixSum[end + 1] - prefixSum[start]);
        }

        return result;
    }

private:
    bool isVowelString(const string& word)
    {
        static const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return (vowels.count(word.front()) && vowels.count(word.back())) ? true : false;
    }
};

// https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02

/*
**2559. 범위 내 모음으로 시작하고 끝나는 문자열의 개수 세기**  
**난이도**: Medium  

---

### 문제 설명

0-인덱스 배열 `words`(문자열 배열)와 2D 정수 배열 `queries`가 주어집니다.  

각 쿼리 `queries[i] = [li, ri]`는 `words` 배열에서 인덱스 `li`부터 `ri`(둘 다 포함)까지의 범위에 있는 문자열 중 **모음으로 시작하고 끝나는 문자열**의 개수를 묻습니다.  

**모음**은 `'a', 'e', 'i', 'o', 'u'`로 정의됩니다.  

`queries.length` 크기의 배열 `ans`를 반환하며, `ans[i]`는 `i`번째 쿼리의 답을 나타냅니다.  

---

### 예제

**예제 1**:
- **입력**:  
  ```text
  words = ["aba", "bcb", "ece", "aa", "e"], queries = [[0,2],[1,4],[1,1]]
  ```
- **출력**:  
  ```text
  [2, 3, 0]
  ```
- **설명**:
  - 모음으로 시작하고 끝나는 문자열: `"aba"`, `"ece"`, `"aa"`, `"e"`.
  - 쿼리 `[0,2]`: `"aba"`, `"ece"` → 2개.
  - 쿼리 `[1,4]`: `"ece"`, `"aa"`, `"e"` → 3개.
  - 쿼리 `[1,1]`: 해당 범위에 조건을 만족하는 문자열 없음 → 0개.  

---

**예제 2**:
- **입력**:  
  ```text
  words = ["a", "e", "i"], queries = [[0,2],[0,1],[2,2]]
  ```
- **출력**:  
  ```text
  [3, 2, 1]
  ```
- **설명**:
  - 모든 문자열이 조건을 만족.
  - 쿼리 `[0,2]`: `"a"`, `"e"`, `"i"` → 3개.
  - 쿼리 `[0,1]`: `"a"`, `"e"` → 2개.
  - 쿼리 `[2,2]`: `"i"` → 1개.  

---

### 제약 조건
1. \(1 \leq \text{words.length} \leq 10^5\)
2. \(1 \leq \text{words}[i].length \leq 40\)
3. `words[i]`는 소문자 영어 알파벳으로만 이루어져 있습니다.
4. \(\sum(\text{words}[i].length) \leq 3 \times 10^5\)
5. \(1 \leq \text{queries.length} \leq 10^5\)
6. \(0 \leq l_i \leq r_i < \text{words.length}\)  

---

### 문제 풀이 힌트
1. **모음 판단**:
   - 시작과 끝 문자가 모두 `'a', 'e', 'i', 'o', 'u'`에 포함되는지 확인.

2. **사전 처리**:
   - 각 문자열이 조건을 만족하는지를 기록하는 배열을 생성.
   - 누적 합(prefix sum)을 이용하여 범위 쿼리를 효율적으로 계산.

3. **쿼리 처리**:
   - 누적 합 배열을 사용하여 쿼리 범위의 문자열 개수를 빠르게 계산 (\(O(1)\) 시간 복잡도).  
*/
