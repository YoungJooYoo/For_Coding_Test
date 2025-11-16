class Solution
{
public:
    int largestSubmatrix(vector<vector<int>>& matrix) const
    {
        // assert(MIN_ROWS <= matrix.size() && matrix.size() <= MAX_ROWS);
        // assert(!matrix.empty() && MIN_COLS <= matrix[0].size() && matrix[0].size() <= MAX_COLS);

        const size_t ROWS = matrix.size();
        const size_t COLS = matrix[0].size();
        int maxArea = 0;

        for (size_t row = 0; row < ROWS; ++row)
        {
            for (size_t col = 0; col < COLS; ++col) // 세로 누적
            {
                if (matrix[row][col] == 1 && row > 0)
                {
                    matrix[row][col] += matrix[row - 1][col];
                }
            }
            vector<int> heights = matrix[row];
            ranges::sort(heights, greater<int>());
            for (size_t i = 0; i < COLS; ++i) // 최대 면적 계산
            {
                const int base = static_cast<int>(i) + 1;
                const int height = heights[i];
                maxArea = max(maxArea, base * height);
            }
        }

        return maxArea;
    }

private:
    enum
    {
        MIN_ROWS = 1,
        MAX_ROWS = 100,
        MIN_COLS = 1,
        MAX_COLS = 100
    };
};


// https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/

/*
## 1727. 열 재배열로 얻을 수 있는 가장 큰 부분 행렬

이진 행렬 `matrix`(크기 m x n)가 주어집니다. 
이때 행렬의 각 열을 원하는 순서로 재배열(열 단위로 위치를 바꿈)할 수 있습니다.

열을 최적으로 재배열한 뒤, 
모든 원소가 1인 부분 행렬(submatrix)의 최대 넓이(면적)를 반환하세요.

예시 1:

입력: matrix = [[0,0,1],[1,1,1],[1,0,1]]  
출력: 4  
설명: 열들을 재배열하면 위 그림처럼 되고, 굵게 표시된 모든 원소가 1인 부분 행렬의 넓이는 4입니다.

예시 2:

입력: matrix = [[1,0,1,0,1]]  
출력: 3  
설명: 열을 재배열하여 얻을 수 있는 모든 1로 채워진 부분 행렬 중 최대 넓이는 3입니다.

예시 3:

입력: matrix = [[1,1,0],[1,0,1]]  
출력: 2  
설명: 열은 통째로 재배열해야 하므로, 1로만 채워진 부분 행렬의 최대 넓이는 2를 넘을 수 없습니다.

제약 조건:

- m == matrix.length  
- n == matrix[i].length  
- 1 <= m * n <= 10^5  
- matrix[i][j]는 0 또는 1입니다.
*/
