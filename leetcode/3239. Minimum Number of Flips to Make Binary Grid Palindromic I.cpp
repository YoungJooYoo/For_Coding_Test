class Solution
{
public:
    int minFlips(vector<vector<int>>& grid)
    {
        const size_t ROW = grid.size();
        const size_t COL = grid[0].size();

        for (auto& row : grid) // 행 기준 팰린드롬 처리
        {
            swapPalindromic(row, 0, static_cast<int>(COL));
        }
        for (size_t j = 0; j < COL; ++j) // 열 기준 팰린드롬 처리
        {
            int i = 0;
            int k = static_cast<int>(ROW) - 1;
            while (i < k)
            {
                if (grid[i][j] != grid[k][j])
                {
                    ++mResult1;
                }
                ++i;
                --k;
            }
        }

        return min(mResult1, mResult2);
    }

private:
    void swapPalindromic(vector<int>& row, const int start, const int end)
    {
        int left = start;
        int right = end - 1;
        while (left < right)
        {
            if (row[left] != row[right])
            {
                ++mResult2;
            }
            ++left;
            --right;
        }
    }

private:
    int mResult1 = 0;
    int mResult2 = 0;
};

// https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/
