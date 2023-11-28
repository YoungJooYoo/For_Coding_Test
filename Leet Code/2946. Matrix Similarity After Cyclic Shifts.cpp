class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) 
    {
        const size_t ROW = mat.size();
        const size_t COL = mat[0].size();

        for (size_t i = 0; i < ROW; ++i) {
            for (size_t j = 0; j < COL; ++j) {
                const size_t idx = (j + k) % COL;
                if (mat[i][j] != mat[i][idx]) return false;
            }  
        }
        
        return true;
    }
};

// https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/
