class Solution 
{
public:
    int beautySum(const string& s) 
    {
        const size_t LENGTH = s.size();
        int totalBeauty = 0;

        assert(MIN_LENGTH <= LENGTH && LENGTH <= MAX_LENGTH);

        for (size_t i = 0; i < LENGTH; ++i)
        {
            unordered_map<char, int> freq;
            for (size_t j = i; j < LENGTH; ++j)
            {
                assert('a' <= s[i] && s[i] <= 'z');
                ++freq[s[j]];
                int minCount = numeric_limits<int>::max();
                int maxCount = numeric_limits<int>::min();
                for (const auto& [ch, frequency] : freq)
                {
                    minCount = min(minCount, frequency);
                    maxCount = max(maxCount, frequency);
                }
                assert(maxCount - minCount >= 0);
                totalBeauty += (maxCount - minCount);
            }
        }

        assert(totalBeauty >= 0);
        return totalBeauty;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 500,
    };
};

// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

/*
### **1781. 모든 부분 문자열의 아름다움의 합**

**난이도**: Medium

---

### **문제 설명**

문자열의 **아름다움(beauty)**은 가장 빈도가 높은 문자와 가장 빈도가 낮은 문자의 빈도 차이로 정의됩니다.

- 예를 들어, 문자열 `"abaacc"`의 아름다움은 \( 3 - 1 = 2 \)입니다. 
  - 'a'의 빈도: 3
  - 'b'의 빈도: 1
  - 'c'의 빈도: 2

문자열 \( s \)가 주어졌을 때, 모든 부분 문자열의 아름다움의 합을 반환하세요.

---

### **입출력 예시**

#### **예제 1**
- **입력**:
  ```text
  s = "aabcb"
  ```
- **출력**:
  ```text
  5
  ```
- **설명**:
  - 아름다움이 0이 아닌 부분 문자열과 각각의 아름다움:
    - `"aab"`: \( 2 - 1 = 1 \)
    - `"aabc"`: \( 2 - 1 = 1 \)
    - `"aabcb"`: \( 2 - 1 = 1 \)
    - `"abcb"`: \( 2 - 1 = 1 \)
    - `"bcb"`: \( 2 - 1 = 1 \)
  - 총 합: \( 1 + 1 + 1 + 1 + 1 = 5 \).

---

#### **예제 2**
- **입력**:
  ```text
  s = "aabcbaa"
  ```
- **출력**:
  ```text
  17
  ```

---

### **제약 조건**
1. \( 1 \leq \text{s.length} \leq 500 \)
2. \( s \)는 오직 소문자 영어 알파벳으로만 구성됩니다.

---

### **풀이 힌트**
1. 부분 문자열을 효율적으로 생성하고 각 부분 문자열의 빈도를 계산해야 합니다.
2. 각 부분 문자열에서 가장 빈도가 높은 문자와 가장 빈도가 낮은 문자를 찾습니다.
3. 총 시간 복잡도를 줄이기 위해 부분 문자열 생성과 빈도 계산을 최적화하는 방식이 필요합니다.
*/
