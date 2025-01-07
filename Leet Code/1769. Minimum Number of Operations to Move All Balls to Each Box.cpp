class Solution 
{
public:
    vector<int> minOperations(const string& boxes) const
    {
        const size_t LENGTH = boxes.size();
        vector<int> result(LENGTH, 0);
        
        for (int i = 0; i < LENGTH; ++i)
        {
            for (int j = 0; j < LENGTH; ++j)
            {
                assert(boxes[i] == '0' || boxes[i] == '1');
                if (i != j)
                {
                    if (boxes[j] == '1')
                    {
                       result[i] += abs(i - j);  
                    }
                }
            }
        }

        assert(MIN_BOXES_SIZE <= LENGTH && LENGTH <= MAX_BOXES_SIZE);
        assert (result.size() == LENGTH);
        return result;
    }

private:
    enum
    {
        MIN_BOXES_SIZE = 1,
        MAX_BOXES_SIZE = 2000,
    };
};

// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06

/*

### **1769. 모든 공을 각 박스로 옮기는 데 필요한 최소 연산 횟수**

**난이도**: Medium  

---

### **문제 설명**

`n`개의 박스가 있습니다.  
길이 `n`의 이진 문자열 `boxes`가 주어지며, `boxes[i]`는 다음을 나타냅니다:
- `'0'`: \(i\)번째 박스가 비어 있음.
- `'1'`: \(i\)번째 박스에 공이 하나 있음.

한 번의 연산에서, 공을 **인접한 박스**로 옮길 수 있습니다.  
- \(i\)번째 박스와 \(j\)번째 박스는 \( |i - j| = 1 \)일 때 인접합니다.
- 공을 옮긴 후, 어떤 박스에는 여러 개의 공이 있을 수 있습니다.

---

### **목표**

크기 `n`의 배열 `answer`를 반환합니다.  
- \(answer[i]\): \(i\)번째 박스로 모든 공을 옮기는 데 필요한 **최소 연산 횟수**.

---

### **예제**

#### **예제 1**
- **입력**:
  ```text
  boxes = "110"
  ```
- **출력**:
  ```text
  [1, 1, 3]
  ```
- **설명**:
  - 첫 번째 박스: 두 번째 박스에서 공 하나를 첫 번째 박스로 옮기면 됨 → 1번 이동 필요.
  - 두 번째 박스: 첫 번째 박스에서 공 하나를 두 번째 박스로 옮기면 됨 → 1번 이동 필요.
  - 세 번째 박스:
    1. 첫 번째 박스에서 공 하나를 세 번째 박스로 옮김 → 2번 이동 필요.
    2. 두 번째 박스에서 공 하나를 세 번째 박스로 옮김 → 1번 이동 필요.
    - 총 3번 이동 필요.

---

#### **예제 2**
- **입력**:
  ```text
  boxes = "001011"
  ```
- **출력**:
  ```text
  [11, 8, 5, 4, 3, 4]
  ```
- **설명**:
  \( answer[i] \)의 계산은 각 박스마다 모든 공을 옮기는 데 필요한 최소 연산 횟수를 계산하여 나옵니다.

---

### **제약 조건**

1. \( n = \text{boxes.length} \)
2. \( 1 \leq n \leq 2000 \)
3. \( \text{boxes[i]} \)는 `'0'` 또는 `'1'`.

---

### **문제 풀이 힌트**

1. **브루트포스 접근법**:
   - 각 박스마다 나머지 모든 박스에서 공을 옮기는 연산을 계산합니다.
   - 시간 복잡도: \(O(n^2)\).

2. **최적화 접근법**:
   - **왼쪽에서 오른쪽으로 누적 연산 횟수**를 계산.
   - **오른쪽에서 왼쪽으로 누적 연산 횟수**를 계산.
   - \(O(n)\)로 최적화 가능.

*/
