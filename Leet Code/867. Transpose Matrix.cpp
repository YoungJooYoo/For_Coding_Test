class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> result;
        const size_t ROW = matrix.size();
        const size_t COL = matrix[0].size();

        for (size_t j = 0; j < COL; ++j) {
            vector<int> temp;
            for (size_t i = 0; i < ROW; ++i) {
                temp.push_back(matrix[i][j]);
            }
            result.push_back(temp);
        }

        return result;
    }
};

// https://leetcode.com/problems/transpose-matrix/description/?envType=daily-question&envId=2023-12-10
