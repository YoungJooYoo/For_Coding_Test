class UnionFind 
{
public:
    UnionFind(const int size) 
    : parent(size)
    , rank(size, 0) 
    {
        for (int i = 0; i < size; ++i) 
        {
            parent[i] = i;
        }
    }

    int find(const int x) 
    {
        if (parent[x] != x) 
        {
            parent[x] = find(parent[x]); // Path compression
        }

        return parent[x];
    }

    void unite(const int x, const int y) 
    {
        const int rootX = find(x);
        const int rootY = find(y);
        if (rootX != rootY) 
        {
            if (rank[rootX] > rank[rootY]) 
            {
                parent[rootY] = rootX;
            } 
            else if (rank[rootX] < rank[rootY]) 
            {
                parent[rootX] = rootY;
            } 
            else 
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int regionsBySlashes(const vector<string>& grid) 
    {
        const int n = grid.size();
        UnionFind uf(4 * n * n); // 4 triangles per grid cell

        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                const int index = 4 * (i * n + j);

                if (grid[i][j] == '/') 
                {
                    uf.unite(index + 0, index + 3); // Connect top and left
                    uf.unite(index + 1, index + 2); // Connect right and bottom
                } 
                else if (grid[i][j] == '\\') 
                {
                    uf.unite(index + 0, index + 1); // Connect top and right
                    uf.unite(index + 2, index + 3); // Connect bottom and left
                } 
                else 
                { // ' '
                    uf.unite(index + 0, index + 1);
                    uf.unite(index + 1, index + 2);
                    uf.unite(index + 2, index + 3);
                }

                // Connect the current cell with the neighboring cells
                if (i > 0) 
                {
                    uf.unite(index + 0, index - 4 * n + 2); // Connect with the cell above
                }
                if (j > 0) 
                {
                    uf.unite(index + 3, index - 4 + 1); // Connect with the cell on the left
                }
            }
        }

        // Count the number of unique regions
        int regions = 0;
        for (int i = 0; i < 4 * n * n; ++i) 
        {
            if (uf.find(i) == i) 
            {
                regions++;
            }
        }

        return regions;
    }
};


// https://leetcode.com/problems/regions-cut-by-slashes/description/?envType=daily-question&envId=2024-08-10

/*

LeetCode 문제 959번, "Regions Cut By Slashes"

### 문제 설명:

n x n 격자는 1 x 1 크기의 정사각형으로 구성되어 있으며, 각 1 x 1 정사각형은 '/', '\', 또는 공백 ' ' 문자를 포함합니다. 이러한 문자는 정사각형을 연속된 영역으로 나누게 됩니다.

문자열 배열로 표현된 `grid`가 주어질 때, 나눠진 영역의 수를 반환하세요.

참고로 백슬래시 문자는 이스케이프되어 '\\'로 표현됩니다.

### 예시:

**예시 1:**

- 입력: `grid = [" /","/ "]`
- 출력: `2`

**예시 2:**

- 입력: `grid = [" /","  "]`
- 출력: `1`

**예시 3:**

- 입력: `grid = ["/\\","\\/"]`
- 출력: `5`
- 설명: 백슬래시 문자는 이스케이프되어 있기 때문에, "\\/"는 \/, "/\\"는 /\를 나타냅니다.

### 제약 조건:

- n == `grid.length == grid[i].length`
- 1 <= n <= 30
- `grid[i][j]`는 '/', '\', 또는 ' ' 중 하나입니다.












문제 959번 "Regions Cut By Slashes"를 해결하는 데 도움이 될 수 있는 힌트는 다음과 같습니다:

### 힌트 1: 작은 조각으로 나누기
이 문제를 해결하기 위해서는 각 정사각형을 더 작은 삼각형 또는 부분으로 나누는 것이 중요합니다. 각 1x1 정사각형을 2x2의 그리드로 나눌 수 있습니다. 예를 들어:

- '/' 문자는 정사각형을 왼쪽 위와 오른쪽 아래로 나누는 대각선으로, 각각의 작은 정사각형을 두 개의 삼각형으로 나눕니다.
- '\' 문자는 정사각형을 오른쪽 위와 왼쪽 아래로 나누는 대각선으로, 각각의 작은 정사각형을 두 개의 삼각형으로 나눕니다.
- ' ' 문자는 정사각형 전체를 하나의 단위로 둡니다.

### 힌트 2: 연결된 구성 요소 찾기
문제를 그래프 탐색 문제로 변환할 수 있습니다. 각 작은 삼각형이나 부분을 노드로 생각하고, 이웃한 삼각형 또는 부분이 같은 영역에 속하는지 확인하세요. DFS(깊이 우선 탐색) 또는 BFS(너비 우선 탐색)를 사용하여 이웃 노드를 탐색하고 연결된 구성 요소의 수를 계산할 수 있습니다. 이 연결된 구성 요소의 수가 곧 구하고자 하는 "영역의 수"가 됩니다.

### 힌트 3: Union-Find 알고리즘 사용하기
Union-Find(또는 Disjoint Set) 알고리즘을 사용하여 각 삼각형이나 부분을 서로 연결된 구성 요소로 묶을 수 있습니다. 동일한 영역에 속하는 삼각형들을 하나로 묶어 최종적으로 영역의 수를 계산합니다.

이 문제를 해결하기 위해서는 그리드의 각 위치를 작은 단위로 나눈 후, 이 단위들 사이의 연결성을 판단해 전체 영역의 수를 구하는 방식으로 접근하는 것이 핵심입니다.



*/
