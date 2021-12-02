class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        size_t row_length = grid.size();
        size_t col_length = grid[0].size();
        int count = 0;
        
        for (size_t i = 0; i < row_length; i++) {
            for (size_t j = 0; j < col_length; j++) {
                if (grid[i][j] < 0) {
                    count++;
                }
            } 
        }
        
        return count;
    }
};