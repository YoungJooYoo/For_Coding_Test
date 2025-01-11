class Solution 
{
public:
    bool canConstruct(const string& s, const int k) 
    {
        assert(s.length() >= MIN_STRING_LENGTH && s.length() <= MAX_STRING_LENGTH);
        assert(k >= MIN_K && k <= MAX_K);

        if (k > s.length()) 
        {
            return false;
        }

        vector<int> alphabetFreq(ALPHABET_LENGTH, 0);
        int oddCount = 0;

        for (const auto ch : s)
        {
            assert('a' <= ch && ch <= 'z');
            ++alphabetFreq[ch - 'a'];
        }

        for (const int freq : alphabetFreq)
        {
            if (freq % 2 == 1)
            {
                ++oddCount;
            }
        }

        return (oddCount > k) ? false : true; 
    }

private:
    enum 
    {
        MIN_STRING_LENGTH = 1,
        MAX_STRING_LENGTH = 100000,

        MIN_K = 1,
        MAX_K = 100000,

        ALPHABET_LENGTH = 26,
    };
};


// https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11

/*
### **1400. K개의 팰린드롬 문자열 구성**

**난이도**: Medium

---

### **문제 설명**

문자열 \( s \)와 정수 \( k \)가 주어졌을 때, \( s \)의 모든 문자를 사용하여 \( k \)개의 **팰린드롬** 문자열을 구성할 수 있는지 여부를 반환하세요.

- **팰린드롬**: 앞에서 읽든 뒤에서 읽든 동일한 문자열을 말합니다.

---

### **입출력 예시**

#### **예제 1**
- **입력**:
  ```text
  s = "annabelle", k = 2
  ```
- **출력**:
  ```text
  true
  ```
- **설명**:
  - \( s \)의 모든 문자를 사용하여 두 개의 팰린드롬 문자열을 구성할 수 있습니다.
  - 가능한 구성 예시:
    - "anna" + "elble"
    - "anbna" + "elle"
    - "anellena" + "b"

---

#### **예제 2**
- **입력**:
  ```text
  s = "leetcode", k = 3
  ```
- **출력**:
  ```text
  false
  ```
- **설명**:
  - \( s \)의 모든 문자를 사용하여 세 개의 팰린드롬 문자열을 구성하는 것은 불가능합니다.

---

#### **예제 3**
- **입력**:
  ```text
  s = "true", k = 4
  ```
- **출력**:
  ```text
  true
  ```
- **설명**:
  - 각 문자를 각각 하나의 문자열로 사용하여 네 개의 팰린드롬을 구성할 수 있습니다.

---

### **제약 조건**
1. \( 1 \leq s.\text{length} \leq 10^5 \)
2. \( s \)는 소문자 영어 알파벳으로만 이루어져 있습니다.
3. \( 1 \leq k \leq 10^5 \)

---

### **힌트**
1. \( k \)가 \( s \)의 길이보다 크면, \( k \)개의 팰린드롬을 구성할 수 없습니다. 각 팰린드롬은 적어도 하나의 문자를 필요로 하기 때문입니다.
2. 각 팰린드롬에서, 홀수 개의 문자는 중심에만 올 수 있습니다.
3. 문자열에서 홀수 개의 문자의 수가 \( k \)보다 크면 구성할 수 없습니다.

### **힌트**

#### **힌트 1**
만약 \( \text{s.length} < k \)라면, 문자열 \( s \)로 \( k \)개의 문자열을 구성할 수 없습니다. 
이 경우 정답은 **false**입니다.

---

#### **힌트 2**
문자열에서 **홀수 개의 빈도를 가진 문자**의 수가 \( k \)보다 크다면, \( k \)개의 팰린드롬 문자열을 구성할 수 없습니다.  
왜냐하면, 각 홀수 개의 문자는 하나의 팰린드롬에서 중심에만 배치될 수 있기 때문입니다. 따라서 이 경우 정답은 **false**입니다.

---

#### **힌트 3**
위 조건을 모두 만족하지 않는 경우에는 정확히 \( k \)개의 팰린드롬 문자열을 구성할 수 있습니다.  
정답은 **true**입니다. (왜냐하면 남은 문자들로 충분히 팰린드롬을 구성할 수 있기 때문입니다.)
*/
