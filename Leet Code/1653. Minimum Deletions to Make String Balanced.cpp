class Solution 
{
public:
    int minimumDeletions(const string& s) const
    {
        const size_t STRING_LENGTH = s.size();
        vector<int> deletionsForLeftB(STRING_LENGTH, 0);
        vector<int> deletionsForRightA(STRING_LENGTH, 0);
        int minimumDeletionsRequired = numeric_limits<int>::max();

        for (size_t leftIndex = 0, rightIndex = STRING_LENGTH - 1; leftIndex < STRING_LENGTH - 1; ++leftIndex, --rightIndex)
        {
            assert(s[leftIndex] == 'a' or s[leftIndex] == 'b');
            assert(leftIndex + 1 <= STRING_LENGTH && rightIndex - 1 >= 0);

            if (s[leftIndex] == 'b')
            {
                deletionsForLeftB[leftIndex + 1] = deletionsForLeftB[leftIndex] + 1;
            }
            else
            {
                deletionsForLeftB[leftIndex + 1] = deletionsForLeftB[leftIndex];
            }

            if (s[rightIndex] == 'a')
            {
                deletionsForRightA[rightIndex - 1] = deletionsForRightA[rightIndex] + 1;
            }
            else
            {
                deletionsForRightA[rightIndex - 1] = deletionsForRightA[rightIndex];
            }
        }

        for (size_t index = 0; index < STRING_LENGTH; ++index)
        {
            minimumDeletionsRequired = min(minimumDeletionsRequired, deletionsForLeftB[index] + deletionsForRightA[index]);
        }

        assert(S_MIN_SIZE <= STRING_LENGTH && STRING_LENGTH <= S_MAX_SIZE);
        assert(minimumDeletionsRequired != numeric_limits<int>::max());
        return minimumDeletionsRequired;
    }

private:
    enum
    {
        S_MIN_SIZE = 1,
        S_MAX_SIZE = 100000,
    };
};


/*
### **1653. 문자열을 균형 있게 만들기 위한 최소 삭제 횟수**

**난이도**: Medium

---

### **문제 설명**

문자열 `s`가 주어지며, 문자열은 오직 문자 `'a'`와 `'b'`로만 이루어져 있습니다.  
문자열에서 원하는 만큼 문자를 삭제할 수 있습니다.  
문자열 `s`가 **균형적**이라고 하기 위해서는 다음 조건을 만족해야 합니다:

- **어떠한 인덱스 \(i\), \(j\)도 \(i < j\)이고 \(s[i] = 'b'\), \(s[j] = 'a'\)를 만족하지 않아야 합니다.**

즉, 문자열에서 `'b'`가 `'a'`보다 먼저 나와야 합니다.

문자열 `s`를 균형적이게 만들기 위해 삭제해야 하는 **최소 문자 수**를 반환하세요.

---

### **입출력 예시**

#### **예제 1**
- **입력**:
  ```text
  s = "aababbab"
  ```
- **출력**:
  ```text
  2
  ```
- **설명**:
  - 다음 두 가지 방법 중 하나로 문자열을 균형적으로 만들 수 있습니다:
    1. \(0\)-인덱스의 문자 \(s[2]\)와 \(s[6]\)를 삭제 → `"aaabbb"`.
    2. \(0\)-인덱스의 문자 \(s[3]\)와 \(s[6]\)를 삭제 → `"aabbbb"`.

---

#### **예제 2**
- **입력**:
  ```text
  s = "bbaaaaabb"
  ```
- **출력**:
  ```text
  2
  ```
- **설명**:
  - 문자열을 균형적으로 만들기 위해 처음 두 문자를 삭제해야 합니다 → `"aaaaabb"`.

---

### **제약 조건**
1. \(1 \leq s.\text{length} \leq 10^5\)
2. \(s[i]\)는 항상 `'a'` 또는 `'b'`.

---

### **풀이 힌트**

1. **문자열의 패턴 분석**:
   - 문자열이 균형적이려면, 모든 `'b'`는 모든 `'a'`보다 먼저 나와야 합니다.
   - 즉, 문자열에서 `'b'`와 `'a'`의 위치가 바뀌는 구간을 삭제해야 합니다.

2. **효율적인 접근법**:
   - 문자열을 순회하며, 왼쪽에서의 `'b'`의 개수와 오른쪽에서의 `'a'`의 개수를 추적합니다.
   - \(s[i]\)를 기준으로 왼쪽에서 발생하는 `'b'`의 개수와 오른쪽에서 발생하는 `'a'`의 개수를 합한 값이 삭제해야 할 최소 문자의 수를 나타냅니다.

3. **최적화**:
   - \(O(N)\) 시간 복잡도로 문제를 해결할 수 있습니다. \(N\)은 문자열의 길이입니다.
*/
