class Solution 
{
public:
    int minDeletion(const string& s, const int k) const
    {
        assert(MIN_LEN <= s.size() && s.size() <= MAX_LEN);
        assert(MIN_K <= k && k <= MAX_K);

        unordered_map<char,int> freq;
        vector<pair<int,char>> counts;
        
        for (const char ch : s) 
        {
            ++freq[ch];
        }

        for (const auto [ch, cnt] : freq) 
        {
            counts.push_back({cnt, ch});
        }
        ranges::sort(counts);
        assert(counts.size() == freq.size());

        int deletions = 0;
        const int D = counts.size();   // 서로 다른 문자 개수
        const int d = D - k; // 삭제해야 할 서로 다른 문자 개수

        if (D <= k) 
        {
            return deletions;
        }
        for (int i = 0; i < d; ++i) 
        {
            deletions += counts[i].first;
        }

        assert(deletions >= 0);
        return deletions;
    }

private:
    enum 
    {
        MIN_LEN = 1,
        MAX_LEN = 16,
        MIN_K   = 1,
        MAX_K   = 16
    };
};

// https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/description/

/*

**3545. 최대 K개의 서로 다른 문자로 만들기 위한 최소 삭제 횟수**

**난이도:** 쉬움

**문제 설명:**  
소문자 영어로만 이루어진 문자열 **s**와 정수 **k**가 주어집니다.  
문자열에서 몇몇(또는 아무 것도) 문자를 삭제하여, 결과 문자열에 포함된 **서로 다른 문자**의 개수가 **최대 k**가 되도록 하고자 합니다.  
이때, 필요한 **최소 삭제 횟수**를 반환하세요.

---

**예제 1:**

- **입력:** s = "abc", k = 2  
- **출력:** 1  
- **설명:**  
  원래 서로 다른 문자가 3개('a','b','c')이므로, 그 중 하나의 모든 등장 횟수를 삭제하면(예: 'c' 삭제→"ab") 서로 다른 문자는 2개가 되어 조건을 만족합니다.  

---

**예제 2:**

- **입력:** s = "aabb", k = 2  
- **출력:** 0  
- **설명:**  
  이미 서로 다른 문자가 'a','b' 2개로 k=2 이하이므로, 삭제가 필요 없습니다.

---

**예제 3:**

- **입력:** s = "yyyzz", k = 1  
- **출력:** 2  
- **설명:**  
  서로 다른 문자가 'y','z' 2개이므로, k=1을 맞추려면 둘 중 하나(예: 'z')를 모두 삭제해야 합니다. 'z'가 2번 등장하므로 최소 2번 삭제가 필요합니다.

---

**제약 조건:**

- 1 ≤ s.length ≤ 16  
- 1 ≤ k ≤ 16  
- s는 소문자 영어 알파벳만으로 이루어져 있습니다.

---

**힌트:**

1. 문자열에 등장하는 각 문자의 빈도(frequency)를 계산하여 리스트에 모읍니다.  
2. 그 빈도 리스트를 오름차순 정렬합니다.  
3. 서로 다른 문자 개수에서 k를 뺀 값 \(d\)를 구합니다.  
   - \(d \le 0\)이면 이미 조건을 만족하므로 0을 반환합니다.  
4. 그렇지 않으면, 가장 등장 빈도가 작은 \(d\)개의 문자를 모두 삭제해야 하므로, 정렬된 빈도 리스트의 처음 \(d\)개 합이 최소 삭제 횟수입니다.
*/
