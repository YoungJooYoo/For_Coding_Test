class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) 
    {
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] ^ grid[i][0] ^ grid[0][j] ^ grid[0][0]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};