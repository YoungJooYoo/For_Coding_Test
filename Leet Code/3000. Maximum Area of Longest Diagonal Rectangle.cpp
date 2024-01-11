class Solution {
public:
    int areaOfMaxDiagonal(const vector<vector<int>>& dimensions) 
    {
        double max_diagonal = 0;
        int max_area = 0;
        
        for (const auto& dimension : dimensions) {
            const int LENGTH = dimension[0];
            const int WIDTH = dimension[1];
            const int NEW_AREA = LENGTH * WIDTH;
            const double DIAGONAL_LENGTH = sqrt(pow(LENGTH, 2) + pow(WIDTH, 2));

            if (max_diagonal < DIAGONAL_LENGTH ||(DIAGONAL_LENGTH == max_diagonal && NEW_AREA > max_area)) {
                max_diagonal = DIAGONAL_LENGTH;
                max_area = NEW_AREA;
            }
         }

        return max_area;
    }
};

/*

1. **번역**: 
2D 0부터 시작하는 인덱스를 가진 정수 배열 `dimensions`가 주어집니다. 모든 인덱스 `i`에 대해, `0 <= i < dimensions.length`일 때, `dimensions[i][0]`은 직사각형 `i`의 길이를 나타내고, `dimensions[i][1]`은 너비를 나타냅니다. 가장 긴 대각선을 가진 직사각형의 면적을 반환합니다. 가장 긴 대각선을 가진 여러 직사각형이 있을 경우, 가장 큰 면적을 가진 직사각형의 면적을 반환합니다.

   예시 1: 입력: 
   dimensions = [[9,3],[8,6]], 출력: 48 (설명: 인덱스 0에서 길이 = 9, 너비 = 3. 대각선 길이 = sqrt(90) ≈ 9.487. 인덱스 1에서 길이 = 8, 너비 = 6. 대각선 길이 = sqrt(100) = 10. 따라서 인덱스 1의 직사각형이 더 긴 대각선 길이를 가지므로 면적 = 8 * 6 = 48을 반환합니다.)

   예시 2: 입력: 
   dimensions = [[3,4],[4,3]], 출력: 12 (설명: 두 직사각형 모두 대각선 길이가 5로 동일하므로, 최대 면적 = 12.)


2. **요약**: 
이 문제는 주어진 직사각형들 중 가장 긴 대각선을 가진 직사각형의 면적을 찾는 것입니다. 가장 긴 대각선을 가진 여러 직사각형이 있을 경우, 가장 큰 면적을 가진 직사각형의 면적을 찾아야 합니다.


3. **문제 풀이 방향**: 
각 직사각형의 대각선 길이를 계산하고 가장 긴 대각선을 찾습니다. 이를 위해 피타고라스 정리를 사용하여 대각선 길이를 계산합니다. 가장 긴 대각선을 가진 직사각형들 중에서 가장 큰 면적을 가진 직사각형의 면적을 반환합니다.

*/

// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/
