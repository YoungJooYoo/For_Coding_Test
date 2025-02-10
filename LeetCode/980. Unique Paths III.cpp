class Solution 
{
public:
    int uniquePathsIII(const vector<vector<int>>& grid) 
    {
        const size_t m = grid.size();
        const size_t n = grid[0].size();
        size_t remainingEmptyCells = START; // count + 1 
        size_t row;
        size_t col;

        assert(m >= MIN_ROWS && m <= MAX_ROWS);
        assert(n >= MIN_COLS && n <= MAX_COLS);
        assert(m * n >= MIN_CELLS && m * n <= MAX_CELLS);

        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                assert(OBSTACLE <= grid[i][j] && grid[i][j] <= END);
                if (grid[i][j] == START)
                {
                    row = i;
                    col = j;
                }
                else if (grid[i][j] == EMPTY)
                {
                    ++remainingEmptyCells;
                }
            }
        }

        uniquePathsHelperRecirsive(grid, row , col, remainingEmptyCells);
        return mValidPaths; 
    }

private:
    void uniquePathsHelperRecirsive(vector<vector<int>> grid, const int row, const int col, const size_t remainingEmptyCells) 
    {
        const size_t m = grid.size();
        const size_t n = grid[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == OBSTACLE || grid[row][col] == VISITED)
        {
            return;
        }
        else if (grid[row][col] == END)
        {
            if (remainingEmptyCells == 0)
            {
                ++mValidPaths;
            }

            return;
        }

        grid[row][col] = VISITED;
        uniquePathsHelperRecirsive(grid, row, col -1, remainingEmptyCells - 1);
        uniquePathsHelperRecirsive(grid, row, col + 1, remainingEmptyCells - 1);
        uniquePathsHelperRecirsive(grid, row - 1, col, remainingEmptyCells- 1);
        uniquePathsHelperRecirsive(grid, row + 1, col, remainingEmptyCells - 1);
    }

private:
    int mValidPaths = 0;

    enum GridConstants 
    {
        MIN_ROWS  = 1,
        MAX_ROWS  = 20,
        MIN_COLS  = 1,
        MAX_COLS  = 20,
        MIN_CELLS = 1,
        MAX_CELLS = 20
    };
    
    enum CellState 
    {
        VISITED = -2,
        OBSTACLE = -1,  // 이동 불가능한 장애물
        EMPTY = 0,   // 이동 가능한 빈 칸
        START = 1,   // 시작 칸 (정확히 1개 존재)
        END = 2    // 종료 칸 (정확히 1개 존재)
    };
};

// https://leetcode.com/problems/unique-paths-iii/description/
