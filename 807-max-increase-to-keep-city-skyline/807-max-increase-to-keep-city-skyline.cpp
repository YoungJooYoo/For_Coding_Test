class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        const size_t n = grid.size();
        int res = 0;
        vector<int> rows(n);
        vector<int> cols(n);
         
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
        
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                res += min(rows[i], cols[j]) - grid[i][j];
            }
        }
        
        return res;
    }
};