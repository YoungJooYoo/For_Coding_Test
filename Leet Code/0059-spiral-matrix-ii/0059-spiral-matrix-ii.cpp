class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int direction = DIRECTION_EAST;
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = n - 1;
        int num = 1;
        
        while (left <= right && top <= bottom) {
            if (direction == DIRECTION_EAST) {
                for (size_t i = left; i <= right; i++) {
                    result[top][i] = num++;
                }
                direction++;
                top++;
            }
            else if (direction == DIRECTION_WEST) {
                for (size_t i = top; i <= bottom; i++) {
                    result[i][right] = num++;
                }
                direction++;
                right--;
            }
            else if (direction == DIRECTION_SOUTH) {
                for (int i = right; i >= left; i--) {
                    result[bottom][i] = num++;
                }
                direction++;
                bottom--;
            }
            else if (direction == DIRECTION_NORTH) {
                for (int i = bottom; i >= top; i--) {
                    result[i][left] = num++;
                }
                direction = DIRECTION_EAST;
                left++;
            }
        }

        return result;
    }
    
private:
    enum {
        DIRECTION_EAST = 0,
        DIRECTION_WEST = 1,
        DIRECTION_SOUTH = 2,
        DIRECTION_NORTH = 3
    };
};