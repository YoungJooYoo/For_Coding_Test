class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {   
        const int row = mat.size();
        const int col = mat[0].size();

        // sort and replace for ROW
        for (int r = 0; r < row; ++r) {
            vector<int> temp;
            for (int i = r, j = 0; i < row && j < col; ++i, ++j) {
                temp.push_back(mat[i][j]);
            }
            sort(temp.begin(), temp.end());
            for (int i = r, j = 0; i < row && j < col; ++i, ++j) {
                mat[i][j] = temp[j];
            }
        }

        //sort and replace for COL
        for (int c = 0; c < col; ++c) {
            vector<int> temp;
            for (int i = 0, j = c; i < row && j < col; ++i, ++j) {
                temp.push_back(mat[i][j]);
            }
            sort(temp.begin(), temp.end());
            for (int i = 0, j = c; i < row && j < col; ++i, ++j) {
                mat[i][j] = temp[i];
            }
        }
         
        return mat;
    }
};

// https://leetcode.com/problems/sort-the-matrix-diagonally/description/
