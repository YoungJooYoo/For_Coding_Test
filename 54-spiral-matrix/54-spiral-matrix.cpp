class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> result;
        int left = 0;
        int right =  matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        
        while (left <= right and top <= bottom) {
            for (int i = left; i <= right; i++) { // 오른쪽 방향
                result.push_back(matrix[top][i]);
            }
            top++;
            
            for (int i = top; i <= bottom; i++) { // 아래방향
                result.push_back(matrix[i][right]);
            }
            right--;
            
            if(left > right || top > bottom) { // 경계점 체크
                break;
            }
            
            for (int i = right; i >= left; i--) { // 왼쪽방향
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
            
            for (int i = bottom; i >= top; i--) { // 위방향
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return result;
    }
};