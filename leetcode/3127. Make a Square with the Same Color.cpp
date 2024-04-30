class Solution {
public:
    bool canMakeSquare(const vector<vector<char>>& grid) 
    {
        const size_t ROW = grid.size();
        const size_t COL = grid[0].size();

        for (size_t i = 0; i < ROW - 1; ++i) {
            size_t count_black = 0;
            size_t count_white = 0;
            for (size_t j = 0; j < COL - 1; ++j) {
                if (grid[i][j] == 'W') ++count_white;
                else ++count_black;

                if (grid[i][j + 1] == 'W') ++count_white;
                else ++count_black;

                if (grid[i + 1][j] == 'W') ++count_white;
                else ++count_black;

                if (grid[i + 1][j + 1] == 'W') ++count_white;
                else ++count_black;

                if (count_black >= 3 || count_white >= 3) {
                    return true;
                }
                else {
                    count_black = 0;
                    count_white = 0;
                }
            }
            
        }

        return false;
    }
};

// https://leetcode.com/problems/make-a-square-with-the-same-color/description/
