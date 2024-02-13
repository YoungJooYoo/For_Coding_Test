class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) 
    {
        const size_t ROW = matrix.size();
        const size_t COL = matrix[0].size();

        for (size_t j = 0; j < COL; ++j) {
            int max_val = INT_MIN;
            for (size_t i = 0; i < ROW; ++i) {
                max_val = max(max_val, matrix[i][j]);
            }
            for (size_t i = 0; i < ROW; ++i) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = max_val;
                }
            }
        }

        return matrix;
    }
};

// https://leetcode.com/problems/modify-the-matrix/description/
