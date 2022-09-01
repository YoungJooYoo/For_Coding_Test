class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
               result[i][j] = matrix[j][i];
                //cout << matrix[j][i] << " ";
            }
        }
        
        return result;
    }
};

/*
00 01 02
10 11 12
20 21 22
*/