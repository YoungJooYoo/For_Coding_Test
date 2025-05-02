class Solution 
{
public:
    int maxEqualRowsAfterFlips(const vector<vector<int>>& matrix) const
    {
        assert(matrix.size() >= MIN_M && matrix.size() <= MAX_M);
        assert(!matrix.empty());

        int m = matrix.size();
        int n = matrix[0].size();
        int answer = 0;
        unordered_map<string,int> count;

        assert(n >= MIN_N && n <= MAX_N);
        for (int i = 0; i < m; ++i) // 각 행을 "키"로 정규화: 첫 비트를 0으로 맞추기 위해 XOR
        { 
            assert(matrix[i].size() == n);
            const auto& row = matrix[i];
            const char flip = row[0] ? '1' : '0'; // row[0]이 1이면 뒤집어, 0이면 그대로
            string key;
            key.reserve(n);
            for (int j = 0; j < n; ++j) 
            {
                assert(matrix[i][j] == 0 || matrix[i][j] == 1);
                const int normalized = row[j] ^ row[0]; // XOR row[j] with row[0]:  if row[0]==1, then we invert
                key.push_back(char('0' + normalized));
            }
            const int cnt = ++count[key];
            answer = max(answer, cnt);
        }
        
        return answer;
    }

private:
    enum {
        MIN_M = 1,
        MAX_M = 300,
        MIN_N = 1,
        MAX_N = 300
    };
};


// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/

/*
**1072. 같은 행의 수를 최대로 만드는 열 뒤집기**

**난이도:** 중간

**문제 설명:**  
크기가 \(m \times n\)인 이진 행렬 **matrix**가 주어집니다.

원하는 만큼 열을 골라서 뒤집을 수 있습니다.  
- 열을 뒤집는다는 것은 그 열의 모든 셀을 0 ↔ 1로 바꾸는 것을 의미합니다.

여러 번의 열 뒤집기 연산 후에, **모든 원소가 같은 값을 가지는 행**(전부 0이거나 전부 1인 행)을 최대 몇 개 만들 수 있는지 반환하세요.

---

**예제 1:**

```
Input: matrix = [[0,1],
                 [1,1]]
Output: 1
```
설명:  
아무 열도 뒤집지 않으면 두 번째 행 \([1,1]\)이 모두 같으므로 1개입니다.

---

**예제 2:**

```
Input: matrix = [[0,1],
                 [1,0]]
Output: 2
```
설명:  
첫 번째 열을 뒤집으면  
\([
 (0→1),1
],
[
 (1→0),0
]
\)  
즉 \([1,1]\)과 \([0,0]\) 두 개의 같은 행이 됩니다.

---

**예제 3:**

```
Input: matrix = [[0,0,0],
                 [0,0,1],
                 [1,1,0]]
Output: 2
```
설명:  
첫 번째, 두 번째 열을 뒤집으면  
```
[1,1,0]
[1,1,1]
[0,0,0]
```  
이 되고, 두 번째와 세 번째 행이 모두 같은 값(전부 1, 전부 0)으로 이루어집니다.

---

**제약 조건:**

- \(m = \text{matrix.length}\), \(n = \text{matrix}[i].\text{length}\)  
- \(1 \le m, n \le 300\)  
- \(\text{matrix}[i][j]\)는 0 또는 1입니다.

---

**힌트 1:**  
열을 뒤집는 것은 각 행에 어떤 이진 **키 \(K\)**를 XOR 연산하는 것과 같습니다.  
최종에 전부 0이거나 전부 1이 되려면, 원래 행 \(X\)가 \(X \oplus K = \mathbf{0…0}\) 또는 \(\mathbf{1…1}\) 이어야 하므로,  
\(X\) 자체가 \(\mathbf{0…0}\oplus K\) 또는 \(\mathbf{1…1}\oplus K\) 중 하나여야 합니다.  
즉, 서로 비트 반전된 두 패턴만 센 뒤 최빈도를 구하면 됩니다.
*/
