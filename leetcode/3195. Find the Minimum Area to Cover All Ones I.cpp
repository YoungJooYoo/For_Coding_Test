class Solution 
{
public:
    int minimumArea(const vector<vector<int>>& grid) 
    {
        int minRow = grid.size();
        int minCol = grid[0].size();
        int maxCol = -1;
        int maxRow = -1;

        for (int r = 0; r < grid.size(); ++r) 
        {
            for (int c = 0; c < grid[0].size(); ++c) 
            {
                if (grid[r][c] == 1) {
                    minRow = min(minRow, r);
                    maxRow = max(maxRow, r);
                    minCol = min(minCol, c);
                    maxCol = max(maxCol, c);
                }
            }
        }

        if (maxRow == -1) 
        {
            // 만약 grid에 1이 없는 경우 (제약 조건에 따르면 이 경우는 없음)
            return 0;
        }

        const int height = maxRow - minRow + 1;
        const int width = maxCol - minCol + 1;

        return height * width;
    }
};

// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
