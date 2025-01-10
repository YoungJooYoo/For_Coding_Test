class Solution 
{
public:
    vector<string> wordSubsets(const vector<string>& words1, const vector<string>& words2) 
    {
        assert(words1.size() >= WORD_MIN_LENGTH && words1.size() <= WORD_MAX_LENGTH); // 문제 조건 검증
        assert(words2.size() >= WORD_MIN_LENGTH && words2.size() <= WORD_MAX_LENGTH);

        vector<int> maxFreq(ALPHABET_LENGTH, 0); // words2에서 최대 빈도 조건 생성
        vector<string> result;

        for (const auto& word : words2) 
        {
            assert(word.length() >= WORD_MIN_LENGTH && word.length() <= WORD_MAX_LENGTH);
            assert(isLowercaseEnglish(word) == true);

            const vector<int> freq = getAlphabetCount(word);
            for (size_t i = 0; i < ALPHABET_LENGTH; ++i) 
            {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        for (const auto& word : words1) // words1과 maxFreq 비교
        {
            assert(word.length() >= WORD_MIN_LENGTH && word.length() <= WORD_MAX_LENGTH);
            assert(isLowercaseEnglish(word) == true);

            const vector<int> wordFreq = getAlphabetCount(word);
            if (isSubset(maxFreq, wordFreq) == true) 
            {
                result.push_back(word);
            }
        }

        return result;
    }

private:
    enum
    {
        WORD_MIN_LENGTH = 1,
        WORD_MAX_LENGTH = 10000,
        ALPHABET_LENGTH = 26,
    };

    bool isLowercaseEnglish(const string& word) const // 모든 문자가 소문자 영어인지 확인하는 헬퍼 함수
    {
        for (const char ch : word) 
        {
            if (ch < 'a' || ch > 'z') 
            {
                return false;
            }
        }
        return true;
    }

    vector<int> getAlphabetCount(const string& word) const // 문자열에서 각 알파벳의 빈도를 계산
    {
        vector<int> charCount(ALPHABET_LENGTH, 0);
        for (const char ch : word) 
        {
            ++charCount[ch - 'a'];
        }

        return charCount;
    }

    bool isSubset(const vector<int>& condition, const vector<int>& wordFreq) const // 조건 빈도가 단어의 빈도에 포함되는지 확인
    {
        for (size_t i = 0; i < ALPHABET_LENGTH; ++i) 
        {
            if (condition[i] > wordFreq[i]) 
            {
                return false;
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10
/*
### **916. 단어 부분집합**

**난이도**: Medium

---

### **문제 설명**

두 개의 문자열 배열 `words1`과 `words2`가 주어집니다.

#### **부분집합의 정의**
문자열 \(b\)가 문자열 \(a\)의 부분집합이 되기 위해서는 \(b\)에 있는 모든 문자가 \(a\)에도 포함되어 있어야 하며, 문자 개수도 같거나 많아야 합니다.

- 예:
  - `"wrr"`은 `"warrior"`의 부분집합입니다. (문자 `r`이 두 번 포함되어 있음)
  - `"wrr"`은 `"world"`의 부분집합이 아닙니다. (문자 `r`이 한 번만 포함되어 있음)

---

#### **유니버설 문자열의 정의**
문자열 \(a\)가 **유니버설**하려면 \(words2\)의 모든 문자열 \(b\)가 \(a\)의 부분집합이어야 합니다.

---

### **목표**
배열 `words1`에서 유니버설 문자열을 모두 찾아 배열로 반환합니다. 반환 순서는 상관없습니다.

---

### **입출력 예시**

#### **예제 1**
- **입력**:
  ```text
  words1 = ["amazon","apple","facebook","google","leetcode"]
  words2 = ["e","o"]
  ```
- **출력**:
  ```text
  ["facebook","google","leetcode"]
  ```
- **설명**:
  - `"e"`와 `"o"`는 `"facebook"`, `"google"`, `"leetcode"`에 모두 포함됩니다.

---

#### **예제 2**
- **입력**:
  ```text
  words1 = ["amazon","apple","facebook","google","leetcode"]
  words2 = ["l","e"]
  ```
- **출력**:
  ```text
  ["apple","google","leetcode"]
  ```
- **설명**:
  - `"l"`과 `"e"`는 `"apple"`, `"google"`, `"leetcode"`에 모두 포함됩니다.

---

### **제약 조건**
1. \( 1 \leq \text{words1.length}, \text{words2.length} \leq 10^4 \)
2. \( 1 \leq \text{words1[i].length}, \text{words2[i].length} \leq 10 \)
3. \( \text{words1[i]}\)와 \( \text{words2[i]} \)는 모두 소문자 영어 알파벳으로만 구성됩니다.
4. \( \text{words1}\)의 모든 문자열은 유일합니다.

---

### **풀이 힌트**

1. **최적화 접근**:
   - \(words2\)의 각 문자열에서 필요한 문자의 최대 빈도를 기록.
   - \(words1\)의 각 문자열을 순회하며, 이 최대 빈도를 만족하는지 확인.

2. **효율적인 구현**:
   - 각 문자열에서 문자의 빈도를 효율적으로 계산하기 위해 26 크기의 배열(알파벳)을 사용.
   - \(O(N)\) 시간 복잡도로 모든 비교를 처리 가능. \(N\)은 `words1`의 길이입니다.

*/
