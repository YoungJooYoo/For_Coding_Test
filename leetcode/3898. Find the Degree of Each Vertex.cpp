class Solution
{
public:
    vector<int> findDegrees(const vector<vector<int>>& matrix) const
    {
        assert(MIN_SIZE <= static_cast<int>(matrix.size()) && static_cast<int>(matrix.size()) <= MAX_SIZE);

        const size_t matrixSize = matrix.size();
        vector<int> degreeResult;
        degreeResult.reserve(matrixSize);

        for (const auto& row : matrix)
        {
            assert(static_cast<int>(row.size()) == static_cast<int>(matrixSize));
            const int degree = accumulate(row.begin(), row.end(), 0);
            degreeResult.push_back(degree);
        }

        assert(static_cast<int>(degreeResult.size()) == static_cast<int>(matrixSize));
        return degreeResult;
    }

private:
    enum
    {
        MIN_SIZE   = 1,
        MAX_SIZE   = 100,
        EDGE_NONE  = 0, 
        EDGE_EXIST = 1,   
    };
};

// https://leetcode.com/problems/find-the-degree-of-each-vertex/description/

/*


**3898. 각 정점의 차수 구하기**

`n x n` 크기의 2D 정수 배열 `matrix`가 주어집니다. 이 행렬은 **0번부터 n-1번**까지 레이블이 붙은 `n`개의 정점을 가진 **무방향 그래프의 인접 행렬**을 나타냅니다.

- `matrix[i][j] = 1` → 정점 `i`와 정점 `j` 사이에 **간선이 존재**
- `matrix[i][j] = 0` → 정점 `i`와 정점 `j` 사이에 **간선이 없음**

정점의 **차수(degree)** 는 해당 정점에 연결된 간선의 수입니다.

크기 `n`인 정수 배열 `ans`를 반환하세요. `ans[i]`는 정점 `i`의 차수를 나타냅니다.

---

**예시 1**
- 입력: `matrix = [[0,1,1],[1,0,1],[1,1,0]]`
- 출력: `[2,2,2]`
- 설명:
  - 정점 0 → 정점 1, 2와 연결 → 차수 2
  - 정점 1 → 정점 0, 2와 연결 → 차수 2
  - 정점 2 → 정점 0, 1과 연결 → 차수 2

**예시 2**
- 입력: `matrix = [[0,1,0],[1,0,0],[0,0,0]]`
- 출력: `[1,1,0]`
- 설명:
  - 정점 0 → 정점 1과 연결 → 차수 1
  - 정점 1 → 정점 0과 연결 → 차수 1
  - 정점 2 → 아무것도 연결 안됨 → 차수 0

**예시 3**
- 입력: `matrix = [[0]]`
- 출력: `[0]`
- 설명: 정점이 1개뿐이고 간선이 없음 → 차수 0

---

**제약 조건**
- `1 <= n == matrix.length == matrix[i].length <= 100`
- `matrix[i][i] == 0` (자기 자신과의 간선 없음)
- `matrix[i][j]`는 0 또는 1
- `matrix[i][j] == matrix[j][i]` (무방향 그래프)

---

## 요약

인접 행렬에서 각 행의 **1의 개수** = 해당 정점의 차수. 이를 배열로 반환.

---

## 풀이 방향

1. 결과 배열 `ans` 를 크기 `n`으로 초기화
2. 각 정점 `i`에 대해 `matrix[i]` 행을 순회
3. `matrix[i][j] == 1` 인 개수를 세어 `ans[i]`에 저장
4. `ans` 반환


*/
