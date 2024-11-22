class Solution 
{
public:
    int numMagicSquaresInside(const vector<vector<int>>& grid) 
    {
        const size_t ROW = grid.size();
        const size_t COL = grid[0].size();
        int count = 0;

        if (ROW < SEARCH_LENGTH || COL < SEARCH_LENGTH)
        {
            return 0;
        }

        for (size_t i = 0; i <= ROW - SEARCH_LENGTH; ++i)
        {
            for (size_t j = 0; j <= COL - SEARCH_LENGTH; ++j)
            {
                if (isUniqueElements(i, j, grid) == true && isMagicSquare(i, j, grid) == true)
                {
                    ++count;
                }
            }
        }

        return count;
    }

private:
    bool isUniqueElements(const size_t row, const size_t col, const vector<vector<int>>& grid)
    {
        unordered_set<int> uniqueNumbers;
        
        for (size_t i = row; i < row + SEARCH_LENGTH; ++i) // 숫자는 반드시 1에서 9 사이의 유일한 값이어야 함
        {
            for (size_t j = col; j < col + SEARCH_LENGTH; ++j)
            {
                const int val = grid[i][j];
                if (!(1 <= val && val <= 9))
                {
                    return false;
                }
                uniqueNumbers.insert(val);
            }
        }

        return (uniqueNumbers.size() == 9) ? true : false;
    }

    bool isMagicSquare(const size_t row, const size_t col, const vector<vector<int>>& grid)
    {
        // 대각선의 합 확인
        const int targetSum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];  // 첫 행의 합을 기준으로 설정
        const int diag1Sum = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        const int diag2Sum = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

        if (diag1Sum != targetSum || diag2Sum != targetSum)
        {
            return false;
        }
        
        for (size_t i = 0; i < SEARCH_LENGTH; ++i) // 행의 합 확인
        {
            int rowSum = 0;
            for (size_t j = 0; j < SEARCH_LENGTH; ++j)
            {
                rowSum += grid[row + i][col + j];
            }
            if (rowSum != targetSum)
            {
                return false;
            }
        }

        for (size_t j = 0; j < SEARCH_LENGTH; ++j) // 열의 합 확인
        {
            int colSum = 0;
            for (size_t i = 0; i < SEARCH_LENGTH; ++i)
            {
                colSum += grid[row + i][col + j];
            }
            if (colSum != targetSum)
            {
                return false;
            }
        }

        return true;
    }

private:
    enum
    {
        SEARCH_LENGTH = 3
    };
};

// https://leetcode.com/problems/magic-squares-in-grid/description/
