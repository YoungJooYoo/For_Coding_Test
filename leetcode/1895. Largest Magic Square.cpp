class Solution 
{
public:
    int largestMagicSquare(const vector<vector<int>>& grid) const
    {
        const int ROW = static_cast<int>(grid.size());
        const int COL = static_cast<int>(grid[0].size());
        const int MAX_SIZE = min(ROW, COL);

        assert(MIN_GRID_LENGTH <= ROW && ROW <= MAX_GRID_LENGTH);
        assert(MIN_GRID_LENGTH <= COL && COL <= MAX_GRID_LENGTH);
        for (int size = MAX_SIZE; size >= MIN_MAGIC_SIZE; --size)
        {
            for (int row = 0; row + size <= ROW; ++row)
            {
                for (int col = 0; col + size <= COL; ++col)
                {
                    assert(MIN_GRID_VALUE <= grid[row][col] && grid[row][col] <= MAX_GRID_VALUE);
                    if (isMagicSquare(grid, row, col, size) == true)
                    {
                        return size;
                    }
                }
            }
        }

        return MIN_MAGIC_SIZE;
    }

private:
    bool isMagicSquare(const vector<vector<int>>& grid, const int startRow, const int startCol, const int size) const
    {
        const int targetSum = calculateRowSum(grid, startRow, startCol, size);

        if (areAllRowSumsEqual(grid, startRow, startCol, size, targetSum )== false || 
            areAllColSumsEqual(grid, startRow, startCol, size, targetSum) == false ||
            areDiagonalSumsEqual(grid, startRow, startCol, size, targetSum) == false)
        {
            return false;
        }


        return true;
    }

    int calculateRowSum(const vector<vector<int>>& grid, const int row, const int col, const int size) const
    {
        int sum = 0;

        for (int offset = 0; offset < size; ++offset)
        {
            sum += grid[row][col + offset];
        }

        return sum;
    }

    bool areAllRowSumsEqual(const vector<vector<int>>& grid, const int startRow, const int startCol, const int size, const int targetSum) const
    {
        for (int row = 0; row < size; ++row)
        {
            int sum = 0;

            for (int col = 0; col < size; ++col)
            {
                sum += grid[startRow + row][startCol + col];
            }

            if (sum != targetSum)
            {
                return false;
            }
        }

        return true;
    }

    bool areAllColSumsEqual(const vector<vector<int>>& grid, const int startRow, const int startCol, const int size, const int targetSum) const
    {
        for (int col = 0; col < size; ++col)
        {
            int sum = 0;

            for (int row = 0; row < size; ++row)
            {
                sum += grid[startRow + row][startCol + col];
            }

            if (sum != targetSum)
            {
                return false;
            }
        }

        return true;
    }

    bool areDiagonalSumsEqual(const vector<vector<int>>& grid, const int startRow, const int startCol, const int size, const int targetSum) const
    {
        int diagonal1 = 0;
        int diagonal2 = 0;

        for (int i = 0; i < size; ++i)
        {
            diagonal1 += grid[startRow + i][startCol + i];
            diagonal2 += grid[startRow + i][startCol + size - 1 - i];
        }

        return (diagonal1 == targetSum && diagonal2 == targetSum) ? true : false;
    }

private:
    enum
    {
        MIN_GRID_LENGTH = 1,
        MAX_GRID_LENGTH = 50,
        MIN_GRID_VALUE = 1,
        MAX_GRID_VALUE = 1000000,
        MIN_MAGIC_SIZE = 1
    };
};

// https://leetcode.com/problems/largest-magic-square/
