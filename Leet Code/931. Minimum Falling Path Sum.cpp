class Solution {
public:
    int minFallingPathSum(const vector<vector<int>>& matrix) 
    {
        const size_t ROW = matrix.size();
        const size_t COL = matrix[0].size();
        vector<vector<int>> dp(ROW, vector<int>(COL, 0));
        
        // 첫줄 카피
        for (size_t i = 0; i < COL; ++i) {
            dp[0][i] = matrix[0][i];
        }

        // dp에 계산값 넣기
        for (int i = 1; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                const int above = matrix[i][j] + dp[i - 1][j];
                int left_diagonal = INT_MAX; 
                int right_diagonal = INT_MAX;
                if (j + 1 < COL) right_diagonal = dp[i - 1][j + 1] + matrix[i][j]; // 오른쪽 안넘어가면
                if (j - 1 >= 0) left_diagonal = dp[i - 1][j - 1] + matrix[i][j];// 왼쪽 안넘어가면 
                dp[i][j] = min (above, min(left_diagonal, right_diagonal));
            }
        }

        int min_sum = INT_MAX;
        for (size_t j = 0; j < COL; ++j) {
            min_sum = min(min_sum, dp[ROW - 1][j]);
        }

        return min_sum;
    }
};

// https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19

/*

한국어 번역
정수 행렬 matrix가 주어졌을 때, matrix를 통과하는 어떤 낙하 경로의 최소 합을 반환하세요.

낙하 경로는 첫 번째 행의 어느 원소에서 시작하여, 다음 행에서 바로 아래에 있는 원소 혹은 대각선 방향의 좌/우 원소를 선택합니다. 구체적으로, 위치 (row, col)에서 다음 원소는 (row + 1, col - 1), (row + 1, col), (row + 1, col + 1) 중 하나가 됩니다.

요약
matrix는 n x n 크기의 정수 배열입니다.
낙하 경로는 첫 번째 행에서 시작하여, 매 행에서 세 가지 선택 중 하나를 합니다: 바로 아래 원소, 대각선 방향의 왼쪽 혹은 오른쪽 원소.
목표는 가능한 모든 낙하 경로 중에서 최소 합을 가지는 경로의 합을 찾는 것입니다.
문제 풀이 방향
이 문제는 동적 프로그래밍(Dynamic Programming)을 사용하여 효율적으로 해결할 수 있습니다.
각 위치에서의 최소 낙하 경로 합을 저장하는 새로운 행렬을 생성합니다.
첫 번째 행은 그대로 복사하고, 그 다음 행부터는 해당 위치에서 가능한 세 선택(바로 위, 왼쪽 대각선 위, 오른쪽 대각선 위) 중 최소값을 선택하여 현재 위치의 값과 더합니다.
마지막 행까지 이 과정을 반복한 후, 마지막 행에서 최소값을 찾으면 해당 값이 최소 낙하 경로 합이 됩니다.

*/
