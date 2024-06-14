class Solution 
{
public:
    bool checkXMatrix(vector<vector<int>>& grid) 
    {
        const size_t LENGTH = grid.size();

        for (size_t i = 0; i < LENGTH; ++i)
        {
            for (size_t j = 0; j < LENGTH; ++j)
            {
                // 주대각선과 부대각선의 요소는 0이 아니어야 함
                if (i == j || i + j == LENGTH - 1)
                {
                    if (grid[i][j] == 0)
                    {
                        return false;
                    }
                }
                // 나머지 요소는 0이어야 함
                else
                {
                    if (grid[i][j] != 0)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/check-if-matrix-is-x-matrix/description/
