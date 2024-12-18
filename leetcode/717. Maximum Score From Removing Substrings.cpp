class Solution 
{
public:
    int maximumGain(string& s, int x, int y) 
    {
        if (x < y) 
        {
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        
        // 우선순위 높은 것 제거 후, 남은 문자열 이어서 제거
        return calculatePoints(s, 'a', 'b', x) + calculatePoints(s, 'b', 'a', y); // "ab" 제거, "ba" 제거
    }
    
private:
    int calculatePoints(string& s, const char first, const char second, const int points) const
    {
        stack<char> st;
        int score = 0;

        for (const char ch : s) 
        {
            if (!st.empty() && st.top() == first && ch == second) 
            {
                st.pop();  // "ab" 또는 "ba" 제거
                score += points;
            } 
            else 
            {
                st.push(ch);
            }
        }

        // 스택에 남은 문자를 기준으로 문자열을 갱신
        s = "";
        while (!st.empty()) 
        {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end()); // 원래 순서로 복원

        return score;
    }
};

// https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

/*
**1717. 문자열에서 부분 문자열을 제거하여 얻을 수 있는 최대 점수**

**난이도: 중간**

---

### **문제 설명**
문자열 `s`와 두 정수 `x`, `y`가 주어집니다. 아래 두 가지 유형의 작업을 원하는 만큼 수행할 수 있습니다:

1. **"ab"** 부분 문자열을 제거하고 **`x` 점수**를 얻습니다.
   - 예: 문자열 `"cabxbae"`에서 `"ab"`를 제거하면 `"cxbae"`가 됩니다.
2. **"ba"** 부분 문자열을 제거하고 **`y` 점수**를 얻습니다.
   - 예: 문자열 `"cabxbae"`에서 `"ba"`를 제거하면 `"cabxe"`가 됩니다.

위 작업을 문자열 `s`에 적용하여 얻을 수 있는 **최대 점수**를 반환하세요.

---

### **예제**

#### **예제 1**
- 입력: `s = "cdbcbbaaabab", x = 4, y = 5`
- 출력: `19`
- 설명:
  1. 문자열 `"cdbcbbaaabab"`에서 `"ba"`를 제거하면 `"cdbcbbaaab"`가 되고, **5점**을 얻습니다.
  2. 문자열 `"cdbcbbaaab"`에서 `"ab"`를 제거하면 `"cdbcbbaa"`가 되고, **4점**을 얻습니다.
  3. 문자열 `"cdbcbbaa"`에서 `"ba"`를 제거하면 `"cdbcba"`가 되고, **5점**을 얻습니다.
  4. 문자열 `"cdbcba"`에서 `"ba"`를 제거하면 `"cdbc"`가 되고, **5점**을 얻습니다.
  - 총 점수: `5 + 4 + 5 + 5 = 19`

---

#### **예제 2**
- 입력: `s = "aabbaaxybbaabb", x = 5, y = 4`
- 출력: `20`
- 설명:
  1. `"ab"`를 제거하고 **5점**을 얻는 작업을 여러 번 반복하면 총 **20점**을 얻을 수 있습니다.

---

### **제약 사항**
1. `1 <= s.length <= 10^5`
2. `1 <= x, y <= 10^4`
3. `s`는 소문자로 이루어진 문자열입니다.

---

### **문제를 푸는 전략**
1. **큰 점수를 먼저 처리**:
   - `x`와 `y` 중 더 큰 값에 해당하는 부분 문자열 (`"ab"` 또는 `"ba"`)을 먼저 제거합니다.
   - 더 큰 점수를 우선적으로 얻은 후, 나머지 문자열에서 다른 작업을 수행합니다.
2. **스택을 활용하여 문자열 처리**:
   - 문자열을 순회하며 스택을 사용해 현재 문자와 비교하여 `"ab"` 또는 `"ba"`를 제거합니다.
   - 각 제거 시 해당 점수를 추가합니다.
   - 두 번 순회하여 각각 `"ab"`와 `"ba"` 제거를 처리합니다.
*/
