class Solution 
{
public:
    bool hasMatch(const string& s, const string& p) 
    {
        assert(1 <= s.length() && s.length() <= 50 && 1 <= p.length() && p.length() <= 50);

        const size_t starPos = p.find("*"); // 패턴에서 '*'의 위치 찾기
        if (starPos == string::npos) 
        {
            return false; // '*'가 없는 경우 (문제 조건 위반)
        }

        const string leftPart = p.substr(0, starPos);       // 패턴의 왼쪽과 오른쪽 부분 추출
        const string rightPart = p.substr(starPos + 1);
        const size_t leftPos = s.find(leftPart);
        const size_t rightPos = s.find(rightPart, leftPos + leftPart.size());

        if (leftPos == string::npos || rightPos == string::npos) 
        {
            return false; // 왼쪽 부분이 없으면 패턴 불일치
        }

        // 왼쪽 부분이 오른쪽 부분보다 앞에 위치해야 함
        return (leftPos + leftPart.size() <= rightPos) ? true : false;
    }
};

// https://leetcode.com/problems/substring-matching-pattern/description/

/*

### 문제 설명 (3407. Substring Matching Pattern)

주어진 문자열 `s`와 패턴 문자열 `p`에서 `p`는 반드시 하나의 `'*'` 문자를 포함합니다.  

- 패턴 문자열 `p`에서 `'*'`는 **0개 이상의 문자**로 대체될 수 있습니다.  
- 패턴 `p`가 문자열 `s`의 **부분 문자열(substring)**이 될 수 있다면 `true`를 반환하고, 그렇지 않으면 `false`를 반환하세요.  

**부분 문자열(substring)**은 문자열 내에서 **연속적이고 비어 있지 않은 문자들의 나열**을 의미합니다.

---

### 예제

**예제 1**  
- **입력**:  
  ```text
  s = "leetcode", p = "ee*e"
  ```
- **출력**:  
  ```text
  true
  ```
- **설명**:  
  `'*'`를 `"tcod"`로 대체하면, `"eetcode"`가 `s`의 부분 문자열이 됩니다.

---

**예제 2**  
- **입력**:  
  ```text
  s = "car", p = "c*v"
  ```
- **출력**:  
  ```text
  false
  ```
- **설명**:  
  `s`에는 `p`와 일치하는 부분 문자열이 없습니다.

---

**예제 3**  
- **입력**:  
  ```text
  s = "luck", p = "u*"
  ```
- **출력**:  
  ```text
  true
  ```
- **설명**:  
  `'*'`를 `""`, `"c"`, 또는 `"ck"`로 대체하면, `"u"`, `"uc"`, `"uck"`가 모두 `s`의 부분 문자열이 됩니다.

---

### 제약 조건
1. \( 1 \leq s.length \leq 50 \)
2. \( 1 \leq p.length \leq 50 \)
3. \( s \)는 소문자 영어 알파벳으로만 구성됩니다.
4. \( p \)는 소문자 영어 알파벳과 정확히 하나의 `'*'`를 포함합니다.

---

### 해결 방법

1. **패턴 분할**:
   - `p`를 `'*'` 기준으로 **왼쪽 부분(`left`)**과 **오른쪽 부분(`right`)**으로 나눕니다.

2. **부분 문자열 확인**:
   - `s`에 대해 다음을 확인:
     1. `left`가 `s`의 접두사(prefix)인지 확인.
     2. `right`가 `s`의 접미사(suffix)인지 확인.
     3. `left`와 `right` 사이의 모든 문자들이 `'*'`로 대체된 부분.

3. **결과 반환**:
   - `left`와 `right`가 `s`에 적합하게 맞아 떨어지면 `true`, 그렇지 않으면 `false`를 반환.

---

### 최적화된 구현 코드

```cpp
class Solution 
{
public:
    bool isPatternSubstring(const string& s, const string& p) 
    {
        // 패턴에서 '*'의 위치를 찾음
        size_t starIndex = p.find('*');

        // '*'의 왼쪽과 오른쪽 부분 추출
        const string leftPart = p.substr(0, starIndex);
        const string rightPart = p.substr(starIndex + 1);

        // 왼쪽 부분이 s의 접두사인지 확인
        if (s.substr(0, leftPart.size()) != leftPart) 
        {
            return false;
        }

        // 오른쪽 부분이 s의 접미사인지 확인
        if (s.substr(s.size() - rightPart.size()) != rightPart) 
        {
            return false;
        }

        return true;
    }
};
```

---

### 코드 설명

1. **`p.find('*')`**:
   - 패턴 문자열 `p`에서 `'*'`의 위치를 찾습니다.

2. **`p.substr`**:
   - `'*'`의 왼쪽 부분과 오른쪽 부분을 나눕니다:
     - `leftPart = p.substr(0, starIndex)` → `'*'` 왼쪽 문자열.
     - `rightPart = p.substr(starIndex + 1)` → `'*'` 오른쪽 문자열.

3. **부분 문자열 확인**:
   - `leftPart`가 `s`의 접두사인지 확인:
     ```cpp
     s.substr(0, leftPart.size()) != leftPart
     ```
   - `rightPart`가 `s`의 접미사인지 확인:
     ```cpp
     s.substr(s.size() - rightPart.size()) != rightPart
     ```

4. **최종 반환**:
   - `leftPart`와 `rightPart`가 모두 일치하면 `true`, 그렇지 않으면 `false`.

---

### 시간 복잡도
1. **`p.find('*')`**: \(O(M)\), \(M\)은 `p`의 길이.
2. **`substr` 및 비교**: \(O(M + N)\), \(N\)은 `s`의 길이.
3. **총 시간 복잡도**: \(O(M + N)\).

---

### 입력/출력 예시

**예제 1**:
```cpp
string s = "leetcode";
string p = "ee*e";
Solution sol;
bool result = sol.isPatternSubstring(s, p); // true
```

**예제 2**:
```cpp
string s = "car";
string p = "c*v";
Solution sol;
bool result = sol.isPatternSubstring(s, p); // false
```

**예제 3**:
```cpp
string s = "luck";
string p = "u*";
Solution sol;
bool result = sol.isPatternSubstring(s, p); // true
```

*/
