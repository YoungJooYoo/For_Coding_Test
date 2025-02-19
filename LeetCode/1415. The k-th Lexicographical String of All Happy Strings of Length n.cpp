class Solution 
{
public:
    string getHappyString(const int stringLength, const int kth)
    {
        assert(stringLength >= MIN_STRING_LENGTH && stringLength <= MAX_STRING_LENGTH);
        assert(kth >= MIN_K && kth <= MAX_K);
        
        generateHappyStringsRecursive(stringLength);
        
        if (mHappyStrings.size() < static_cast<size_t>(kth))
        {
            return "";
        }
        
        auto itr = mHappyStrings.begin();
        for (int count = 1; count < kth; ++count)
        {
            ++itr;
        }
        
        return *itr;
    }

private:
    void generateHappyStringsRecursive(const int targetLength)
    {
        if (mCurrentString.size() == static_cast<size_t>(targetLength))
        {
            mHappyStrings.insert(mCurrentString);
            return;
        }
        
        for (int i = 0; i < LENGTH; ++i)
        {
            const char nextChar = 'a' + i;
            if (mCurrentString.empty() == true || mCurrentString.back() != nextChar)
            {
                mCurrentString.push_back(nextChar);
                generateHappyStringsRecursive(targetLength);
                mCurrentString.pop_back();
            }
        }
    }

private:
    set<string> mHappyStrings;
    string mCurrentString = "";
    
    enum
    {
        MIN_STRING_LENGTH = 1,
        MAX_STRING_LENGTH = 10,
        MIN_K = 1,
        MAX_K = 100,
        LENGTH = 3,
    };
};

// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19

/*

---

**1415. 길이 n인 모든 행복한 문자열 중 사전 순 k번째 문자열**  
*Medium*  
*Topics*  
*Companies*  
*Hint*

**행복한 문자열 (Happy String)** 은 다음 조건을 만족하는 문자열입니다:

- 문자열은 오직 ['a', 'b', 'c'] 집합에 속하는 문자들로만 구성됩니다.
- 문자열의 1-indexed 표기에서, 모든 i (1 ≤ i ≤ 문자열 길이 - 1)에 대해 s[i] ≠ s[i + 1] 입니다.

예를 들어, "abc", "ac", "b", "abcbabcbcb"는 모두 행복한 문자열이며, "aa", "baa", "ababbc"는 행복한 문자열이 아닙니다.

두 정수 **n**과 **k**가 주어질 때, 길이 n인 모든 행복한 문자열을 사전 순(lexicographical order)으로 정렬한 리스트를 생각해보세요.

이 리스트에서 k번째 문자열을 반환하거나, 길이 n인 행복한 문자열의 개수가 k개 미만이면 빈 문자열을 반환하세요.

---

**예제 1:**

```
입력: n = 1, k = 3
출력: "c"
```

*설명:*  
길이가 1인 행복한 문자열의 리스트는 ["a", "b", "c"]이며, 세 번째 문자열은 "c"입니다.

---

**예제 2:**

```
입력: n = 1, k = 4
출력: ""
```

*설명:*  
길이가 1인 행복한 문자열은 3개뿐이므로, 4번째 문자열은 존재하지 않습니다.

---

**예제 3:**

```
입력: n = 3, k = 9
출력: "cab"
```

*설명:*  
길이가 3인 행복한 문자열은 총 12개가 있으며, 그 리스트는 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]입니다. 이 중 9번째 문자열은 "cab"입니다.

---

**제약 조건:**

- 1 <= n <= 10  
- 1 <= k <= 100
*/
