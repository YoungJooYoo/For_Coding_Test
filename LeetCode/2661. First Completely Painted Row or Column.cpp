class Solution 
{
public:
    int firstCompleteIndex(const vector<int>& arr, const vector<std::vector<int>>& mat) 
    {
        const size_t rows = mat.size();
        const size_t cols = mat[0].size();
        const size_t ARRAY_LENGTH = arr.size();
        vector<size_t> rowPaintedCount(rows, 0);
        vector<size_t> colPaintedCount(cols, 0);
        unordered_map<int, pair<size_t, size_t>> valueToPosition;

        assert(ARRAY_LENGTH == rows * cols && MIN_SIZE <= rows && rows <= MAX_SIZE && MIN_SIZE <= cols && cols <= MAX_SIZE);

        for (size_t r = 0; r < rows; ++r) 
        {
            for (size_t c = 0; c < cols; ++c) 
            {
                const int value = mat[r][c];
                const pair<int, int> position(r, c);
                valueToPosition[value] = position;
            }
        }

        for (size_t i = 0; i < ARRAY_LENGTH; ++i) 
        {
            const int value = arr[i];
            const auto& [r, c] = valueToPosition[value]; // get position
            if ((++rowPaintedCount[r] == cols) || (++colPaintedCount[c] == rows))  // 어느 한 행이나 열이 완전히 칠해졌는지 확인
            {
                return i;
            }
        }

        assert(false);
        return FAIL;
    }

private:
    enum 
    {
        FAIL = -1,
        MIN_SIZE = 1,        // 최소 행/열 크기
        MAX_SIZE = 100000,   // 최대 행/열 크기
        MIN_VAL = 1,         // arr 및 mat의 최소 값
        MAX_VAL = 100000     // arr 및 mat의 최대 값
    };
};

// https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20

/*

### **2661. 처음으로 완전히 칠해지는 행 또는 열**  

---

#### **문제 설명**  
다음과 같은 입력이 주어집니다:  
- 0-인덱스 정수 배열 `arr`  
- `m x n` 크기의 정수 행렬 `mat`  

`arr`와 `mat`에는 `[1, m * n]` 범위의 모든 정수가 각각 포함되어 있으며, 모든 숫자는 **유일**합니다.

다음 과정을 따릅니다:
1. 배열 `arr`의 각 인덱스 `i`를 0부터 순서대로 순회하며, **`arr[i]`와 같은 값이 포함된 `mat`의 셀을 칠합니다.**
2. `mat`에서 **한 행(row)** 또는 **한 열(column)** 이 **완전히 칠해지는 순간의 가장 작은 인덱스 `i`를 반환**합니다.

---

#### **입력 및 출력 예시**

##### **예제 1**
**입력**:
```plaintext
arr = [1,3,4,2]
mat = [[1,4],
       [2,3]]
```

**출력**:
```plaintext
2
```

**설명**:
- `arr`의 요소를 순서대로 처리하며 `mat`을 칠합니다:
  1. `arr[0] = 1` → `mat`의 첫 번째 행, 첫 번째 셀이 칠해짐.
  2. `arr[1] = 3` → 두 번째 행, 두 번째 셀이 칠해짐.
  3. `arr[2] = 4` → 첫 번째 행, 두 번째 셀이 칠해짐 → **첫 번째 행이 완전히 칠해짐**.
- **결과적으로 인덱스 `2`에서 첫 번째 행이 완전히 칠해졌으므로** 출력은 `2`입니다.

---

##### **예제 2**
**입력**:
```plaintext
arr = [2,8,7,4,1,3,5,6,9]
mat = [[3,2,5],
       [1,4,6],
       [8,7,9]]
```

**출력**:
```plaintext
3
```

**설명**:
- `arr`의 요소를 순서대로 처리하며 `mat`을 칠합니다:
  1. `arr[0] = 2` → 첫 번째 행, 두 번째 셀이 칠해짐.
  2. `arr[1] = 8` → 세 번째 행, 첫 번째 셀이 칠해짐.
  3. `arr[2] = 7` → 세 번째 행, 두 번째 셀이 칠해짐.
  4. `arr[3] = 4` → 두 번째 행, 두 번째 셀이 칠해짐 → **두 번째 열이 완전히 칠해짐**.
- **결과적으로 인덱스 `3`에서 두 번째 열이 완전히 칠해졌으므로** 출력은 `3`입니다.

---

#### **제약 조건**
1. `m == mat.length` (행의 수)
2. `n == mat[i].length` (열의 수)
3. `arr.length == m * n` (배열 길이는 행렬의 전체 원소 수와 같음)
4. `1 <= m, n <= 10^5`
5. `1 <= m * n <= 10^5`
6. `1 <= arr[i], mat[r][c] <= m * n`
7. 배열 `arr`와 행렬 `mat`의 모든 정수는 **유일**합니다.

---

#### **문제 풀이 아이디어**
1. 배열 `arr`를 순회하면서 각 숫자가 `mat`의 어느 행, 어느 열에 위치하는지 추적.
2. 각 행과 열이 칠해진 셀의 개수를 카운팅.
3. 어느 한 행 또는 열의 카운트가 `n` 또는 `m`이 되는 순간, 해당 `arr`의 인덱스를 반환.
*/
