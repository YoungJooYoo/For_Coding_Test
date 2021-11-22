class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const size_t line_length = matrix[0].size();
        const size_t matrix_length = matrix.size();
        size_t i = 0;
        int j = line_length - 1;
        
        // 배열의 범위 안에서 탐색 시작
        while(i < matrix_length && j >= 0) {
            if(matrix[i][j] == target) { // 타겟 찾은 경우
                return true;
            }
            else if(matrix[i][j] < target) { // 행의 끝값이 타겟보다 작으면
                i++; // 다음줄로 이동해서 탐색 시작
            }
            else { // target보다 크다면, 지금 행에 값이 있으므로 이 행을 탐색 시작
                j--;    
            }
        }
       
        return false;
    }
};