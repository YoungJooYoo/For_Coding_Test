class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        // manage base case of when matrix is empty
        if (matrix.size() == 0) {
            return {};
        }
        
        int row = matrix.size();  // variables for storing the last index for rows and columns
        int col = matrix[0].size();
        int i = 0; // variables for storing the current index while traversing the matrix
        int j = 0;
        bool isMovingUpRight = true; // // variable to check which direction we are moving
        int result_index = 1; // variable for keep track of which elements in the result vector are populated
        vector<int> result(row * col); // // declare vector we will return at the end
        result[0] = matrix[i][j]; // assign the first element in the result vector
        
        // while we have not reach the end of the row and column (last index for both row and column)
        while (i != row - 1 || j != col - 1) {
            if (isMovingUpRight == true) { // if we are moving in the up-right direction...
                if (j == col - 1) { // ...and we have hit the right end of the matrix, we will move down one position and switch direction
                    i++;
                    isMovingUpRight = false;
                } else if (i == 0) { // ...and we have hit the top the matrix, we will move right one position and switch direction
                    j++;
                    isMovingUpRight = false;
                } else { // ...else we have not hit the end of either side so we will move up and right one position
                    i--;
                    j++;
                }
            } else { // else we are moving in the bottom-left direction...
                if (i == row - 1) { // ...and we have hit the bottom of the matrix, we will move right one position and switch direction
                    j++;
                    isMovingUpRight = true;
                } else if (j == 0) { // ...and we have hit the left end of the matrix, we will move down and switch direction
                    i++;
                    isMovingUpRight = true;
                } else { // ...else we have not hit the end of either side so we will move down and left one position
                    i++;
                    j--;
                }
            }
            
            result[result_index] = matrix[i][j]; // after moving, we will assign the current element into the result vector
            result_index++;
        }
        
        return result; // return final result after traversing the matrix
    }
};


/*
풀이법 해설 :
첫번쨰 원소는, 결과 배열에 0번째에 반드시 들어가므로 

1. 오른쪽 방향으로 올라가는 경우
2. 왼쪽 아래방향으로 내려가는 경우

크게 2가지 경우를 나누어서 탐색을 시작한다.


*/