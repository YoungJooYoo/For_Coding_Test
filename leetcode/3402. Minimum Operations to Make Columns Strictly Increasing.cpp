class Solution 
{
public:
    int minimumOperations(vector<vector<int>>& grid) 
    {
        const size_t ROW_LENGTH = grid.size();
        const size_t COL_LENGTH = grid[0].size();
        int count = 0;
        
        for (size_t j = 0; j < COL_LENGTH; ++j)
        {
            int prev = numeric_limits<int>::min();
            for (size_t i = 0; i < ROW_LENGTH; ++i)
            {
                int& curr = grid[i][j];
                if (prev >= curr)
                {
                    count += prev - curr + 1;
                    curr = prev + 1;
                }
                prev = curr;
            }
        }

        return count;
    }
};
  
// https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/description/
