class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        const int ROW = mat.size();
        const int COL = mat[0].size();
        int sum = 0;

        for (int i = 0; i < ROW; ++i) { // 좌측 대각선 합 구하기
            sum += mat[i][i];
        }
        for (int i = 0, j = COL - 1; i < ROW && j >= 0; ++i, --j) { // 우측 대각선 합 구하기
            sum += mat[i][j];
        }
        
        if (ROW % 2 != 0) { // 홀수라면 중복된 중앙 값 하나 빼주기
            int index = ROW / 2;
            return sum - mat[index][index];
        }
        
        return sum;
    }
};

// https://leetcode.com/problems/matrix-diagonal-sum/description/
