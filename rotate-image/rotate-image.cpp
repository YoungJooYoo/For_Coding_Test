class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const size_t matrix_length = matrix.size();
        
        for (size_t i = 0; i < matrix_length; i++) {
            for (size_t j = 0; j < i; j++) {
               swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(size_t i = 0; i < matrix_length; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/* 이해하기 쉬운 방법 :

3 X 3 배열을 그려본 후, 
90도 회전으로 돌린다.
swap 후, reverse해보면 회전된 배열이 나온다.

*/