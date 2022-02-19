class Solution {
public:
    vector<vector<int>>& flip(vector<vector<int>>& mat, int y, int x) 
    {
        mat[y][x] ^= 1; // 현재위치 비트 반전
        
        // 동서남북으로 비트반전, 배열의 범위를 넘지 않는지 체크
        if (y - 1 >= 0) mat[y - 1][x] ^= 1;
        if (y + 1 <  n) mat[y + 1][x] ^= 1;
        if (x - 1 >= 0) mat[y][x - 1] ^= 1;
        if (x + 1 <  m) mat[y][x + 1] ^= 1;
        
        return mat;
    }

    bool isZeroMat(vector<vector<int>>& mat) 
    {   // 주어진 행렬이 전부 0인지 확인하는 함수
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {  
                if (mat[i][j] == 1) {
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
            return isZeroMat(mat) ? 0 : 100; // 왜?? 100000
        }

        int ret1 = FlipOrNotFlip(mat, y, x + 1); // flip전에 flip할 범위를 
        int ret2 = FlipOrNotFlip(flip(mat, y, x), y, x + 1) + 1; //플립 후 +1씩 플립 횟수를 누적
        
        return min(ret1, ret2);
    }

    int minFlips(vector<vector<int>>& mat) 
    {
        n = mat.size(); // y에 대응
        m = mat[0].size(); // x에 대응
        int ret = FlipOrNotFlip(mat, 0, 0);
        
        return ret >= 100 ? -1 : ret;
    }
    
private: 
    int n;
    int m;
};