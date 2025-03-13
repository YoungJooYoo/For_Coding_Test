class Solution 
{
public:
    long long countOfSubstrings(const string& word, const int k) const
    {
        assert(word.size() >= MIN_LENGTH && word.size() <= MAX_LENGTH);

        const size_t LENGTH = word.size();
        long long totalCount = 0;
        int consonantCount = 0; // 현재 윈도우 내 자음의 개수
        size_t left = 0;
        size_t right = 0;

        vector<int> freq(ALPHABET_LENGTH, 0); // 알파벳 빈도수 배열 (인덱스 0 -> 'a', 1 -> 'b', …)
        vector<size_t> nextConsonant(LENGTH, LENGTH);

        int lastConsonant = LENGTH;  // 뒤쪽에서부터 찾은 마지막 자음의 인덱스
        for (int i = LENGTH - 1; i >= 0; --i)
        {
            if (!isVowel(word[i]))
            {
                lastConsonant = i;
            }
            nextConsonant[i] = lastConsonant;
        }
        
        
        const auto vowelsSatisfied = [&]() -> bool 
        {
            return freq['a' - 'a'] > 0 && freq['e' - 'a'] > 0 &&
                   freq['i' - 'a'] > 0 && freq['o' - 'a'] > 0 &&
                   freq['u' - 'a'] > 0;
        }; // 현재 윈도우에 모든 모음('a','e','i','o','u')가 최소 한 번씩 등장하는지 확인하는 람다 함수
        
        // 슬라이딩 윈도우: left부터 시작하는 윈도우를 확장하며 조건(모든 모음 포함, 자음 개수 == k)을 만족하는 최소 right를 찾음.
        while (left < LENGTH)
        {
            while (right < LENGTH && (consonantCount < k || !vowelsSatisfied()))
            {
                const char c = word[right];
                ++freq[c - 'a'];
                if (!isVowel(c))
                {
                    ++consonantCount;
                }
                ++right;
            }
            
            if (consonantCount == k && vowelsSatisfied())
            {
                size_t rExtend = right;
                if (rExtend < LENGTH && isVowel(word[rExtend]))
                {
                    rExtend = nextConsonant[right];
                }
                totalCount += (rExtend - right + 1);
            }
            
            const char leftChar = word[left];          // 윈도우 축소: left 포인터를 오른쪽으로 이동하며 현재 윈도우에서 제거되는 문자 반영
            --freq[leftChar - 'a'];
            if (!isVowel(leftChar))
            {
                --consonantCount;
            }
            ++left;
            if (right < left)
            {
                right = left;
            }
        }
        
        return totalCount;
    }
    
private:
    bool isVowel(const char c) const 
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
private:
    enum
    {
        MIN_LENGTH      = 5,
        MAX_LENGTH      = 200000,
        ALPHABET_LENGTH = 26
    };
};


// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10

/*


---

**3306. 모든 모음과 k개의 자음을 포함하는 부분 문자열의 개수 II**

**난이도:** 중간

**문제 설명:**  
문자열 **word**와 음이 아닌 정수 **k**가 주어집니다.

**word**의 부분 문자열 중에서 다음 두 조건을 모두 만족하는 부분 문자열의 총 개수를 반환하세요:
1. 모든 모음 ('a', 'e', 'i', 'o', 'u')이 적어도 한 번씩 등장한다.
2. 자음의 개수가 정확히 **k**개이다.

---

**예제 1:**

- **입력:** word = "aeioqq", k = 1  
- **출력:** 0  
- **설명:** 모든 모음이 포함된 부분 문자열이 존재하지 않습니다.

---

**예제 2:**

- **입력:** word = "aeiou", k = 0  
- **출력:** 1  
- **설명:** 모든 모음이 포함되고 자음이 0개인 유일한 부분 문자열은 word[0..4] ("aeiou")입니다.

---

**예제 3:**

- **입력:** word = "ieaouqqieaouqq", k = 1  
- **출력:** 3  
- **설명:** 모든 모음과 1개의 자음을 포함하는 부분 문자열은 다음과 같습니다:
  - word[0..5] ("ieaouq")
  - word[6..11] ("qieaou")
  - word[7..12] ("ieaouq")

---

**제약 조건:**

- 5 <= word.length <= 2 * 10^5  
- **word**는 오직 소문자 영어 알파벳으로 구성됩니다.  
- 0 <= k <= word.length - 5

---

**힌트:**

1. 슬라이딩 윈도우와 이진 탐색을 사용할 수 있습니다.  
2. 각 인덱스 r에 대해, 두 조건(모든 모음 포함, 자음 개수 k)이 모두 만족되는 최대 l을 이진 탐색으로 찾으세요.
*/
