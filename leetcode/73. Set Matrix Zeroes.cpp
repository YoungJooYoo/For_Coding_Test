class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> position;

        // 0을 가진 인덱스를 저장
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    position.push_back({i, j});
                }
            }
        }
        
        // 해당 인덱스의 행과 열읠 0으로 전부 변경
        for (auto& pos : position) {
            int i = pos[0];
            int j = pos[1];
            for (int k = 0; k < m; ++k) matrix[k][j] = 0;
            for (int l = 0; l < n; ++l) matrix[i][l] = 0;
        }
    }
};

https://leetcode.com/problems/set-matrix-zeroes/description/
