class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) const
    {
        assert(grid.empty() == false);
        assert(grid.size() == grid[0].size());
        assert(MIN_LENGTH <= static_cast<int>(grid.size()) && static_cast<int>(grid.size()) <= MAX_LENGTH);

        const int n = static_cast<int>(grid.size());

        for (int diagOffset = -n + 1; diagOffset < n; ++diagOffset) // diagOffset = r - c :  -(n-1) .. (n-1)
        {
            vector<int> temp;
            if (diagOffset >= 0) // 왼쪽 위 삼각형
            {
                const int len = n - diagOffset;
                for (int k = 0; k < len; ++k)  // lower-left triangle (including main diagonal): (r, c) = (diagOffset + k, 0 + k)
                {
                    const int r = diagOffset + k;
                    const int c = k;
                    temp.push_back(grid[r][c]);
                    assert(MIN_GRID <= grid[r][c] && grid[r][c] <= MAX_GRID);
                }

                sort(temp.begin(), temp.end(), greater<int>());
                for (int k = 0; k < len; ++k) // write-back
                {
                    const int r = diagOffset + k;
                    const int c = k;
                    grid[r][c] = temp[k];
                    assert(MIN_GRID <= grid[r][c] && grid[r][c] <= MAX_GRID);
                }
            }
            else // 오른쪽 위 삼각형
            {
                const int startC = -diagOffset; // upper-right triangle: (r, c) = (0 + k, -diagOffset + k)
                const int len = n - startC;
                for (int k = 0; k < len; ++k)
                {
                    const int r = k;
                    const int c = startC + k;
                    temp.push_back(grid[r][c]);
                    assert(MIN_GRID <= grid[r][c] && grid[r][c] <= MAX_GRID);
                }

                sort(temp.begin(), temp.end());
                for (int k = 0; k < len; ++k)
                {
                    const int r = k;
                    const int c = startC + k;
                    grid[r][c] = temp[k];
                    assert(MIN_GRID <= grid[r][c] && grid[r][c] <= MAX_GRID);
                }
            }
        }

        return grid;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 10,
        MIN_GRID = -100000,  // 문제 설명의 -10^5
        MAX_GRID =  100000
    };
};

// https://leetcode.com/problems/sort-matrix-by-diagonals/description/
