class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();
        int row_sum[row];
        int col_sum[col];

        for (size_t i = 0; i < row; ++i)
        {
            row_sum[i] = 0; 
            for (size_t j = 0; j < col; ++j) {
                row_sum[i] += mat[i][j];
            }
        }

        for (int i = 0; i < col; ++i)
        {
            col_sum[i] = 0; // 각 열마다 합을 구함
            for (size_t j = 0; j < row; ++j) {
                col_sum[i] += mat[j][i];
            }
        }
        
        int count = 0;
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < col; ++j) {
                if (mat[i][j] == 1 && row_sum[i] == 1 && col_sum[j] == 1) { // 더했던 행 혹은 열의 값이 딱 1이라면, 스페셜 포지션이므로 카운트 한다.
                    ++count; 
                }
            }
        }
        
        return count;
    }
};
// https://blog.naver.com/yyj9301/222955112958
