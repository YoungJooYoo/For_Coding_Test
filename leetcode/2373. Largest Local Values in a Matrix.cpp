class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {   
        const size_t GRID_SIZE = grid.size();
        vector<vector<int>> result(GRID_SIZE - 2, vector<int>(GRID_SIZE - 2, 0));
        const size_t RES_SIZE = result.size();

        for (size_t i = 0; i < RES_SIZE; ++i) {
            for (size_t j = 0; j < RES_SIZE; ++j) {
                int largest = INT_MIN;
                for (int row = i; row < i + 3; ++row) {
                    for (int column = j; column < j + 3; ++column) {
                        largest = max(largest, grid[row][column]);
                    }
                }
                result[i][j] = largest;
            }
        }

        return result;
    }

};

// https://leetcode.com/problems/largest-local-values-in-a-matrix/description/
