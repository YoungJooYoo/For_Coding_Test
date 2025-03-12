class Solution 
{
public:
    int numberOfSubstrings(const string& s) 
    {
        assert(s.size() >= MIN_LENGTH && s.size() <= MAX_LENGTH);
        
        vector<int> freq(3, 0);
        const int n = s.size();
        int result = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right)  // 오른쪽 포인터를 이동하며 창에 문자를 추가합니다.
        {
            assert(s[right] == 'a' || s[right] == 'b' || s[right] == 'c');
            ++freq[s[right] - 'a']; // count a, b, c
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)  // 현재 창에 'a', 'b', 'c' 모두 포함되어 있으면
            {
                result += (n - right);
                --freq[s[left] - 'a']; // 왼쪽 포인터를 이동하며 창을 축소합니다.
                ++left;
                assert(freq[s[left] - 'a'] >= 0);
            }
        }
        
        assert(result >= 0);
        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 3,
        MAX_LENGTH = 50000  // 5 x 10^4
    };
};


// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2025-03-11

/*


**1358. 모든 세 문자를 포함하는 부분 문자열의 개수**

**난이도:** 중간

**문제 설명:**  
문자열 **s**가 주어지며, 이 문자열은 오직 문자 a, b, c로만 구성되어 있습니다.  
문자 a, b, c가 각각 최소 한 번 이상 등장하는 모든 부분 문자열의 개수를 반환하세요.

---

**예제 1:**

- **입력:** s = "abcabc"  
- **출력:** 10  
- **설명:**  
  문자 a, b, c가 모두 최소 한 번씩 등장하는 부분 문자열은 다음과 같습니다:  
  "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" 그리고 "abc"(다시 등장)

---

**예제 2:**

- **입력:** s = "aaacb"  
- **출력:** 3  
- **설명:**  
  문자 a, b, c가 모두 최소 한 번씩 등장하는 부분 문자열은 "aaacb", "aacb", "acb"입니다.

---

**예제 3:**

- **입력:** s = "abc"  
- **출력:** 1

---

**제약 조건:**

- 3 <= s.length <= 5 x 10^4  
- s는 오직 문자 a, b, c로만 구성됩니다.
*/
