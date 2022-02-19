class Solution {
public:
    vector<vector<int>>& flip(vector<vector<int>>& mat, int y, int x) 
    {
        mat[y][x] ^= 1;
        
        if (y - 1 >= 0) mat[y - 1][x] ^= 1;
        if (y + 1 <  n) mat[y + 1][x] ^= 1;
        if (x - 1 >= 0) mat[y][x - 1] ^= 1;
        if (x + 1 <  m) mat[y][x + 1] ^= 1;
        
        return mat;
    }

    bool isZeroMat(vector<vector<int>>& mat) 
    {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j){ 
                if (mat[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }

    int FlipOrNotFlip(vector<vector<int>> mat, int y, int x) 
    {
        if (x == m) { // 행의 끝값에 도착
            y++; 
            x = 0;
        }
        if (y == n) { // 열의 끝값에 도착한 경우
            return isZeroMat(mat) ? 0 : 10000;
        }

        int ret1 = FlipOrNotFlip(mat, y, x + 1);
        int ret2 = FlipOrNotFlip(flip(mat, y, x), y, x + 1) + 1;
        
        return min(ret1, ret2);
    }

    int minFlips(vector<vector<int>>& mat) 
    {
        n = mat.size();
        m = mat[0].size();
        int ret = FlipOrNotFlip(mat, 0, 0);
        
        return ret >= 10000 ? -1 : ret;
    }
private: 
    int n, m;
};