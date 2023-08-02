class Solution {
public:
    int maxSum(vector<vector<int>>& grid) 
    { 
        const size_t M = grid.size() - 2;
        const size_t N = grid[0].size() - 2;
        int result = INT_MIN;

        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0 ; j < N; ++j) {
                // 모래 시계 모양으로 전부 더하기
                int curr_sum  = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                result = max(result, curr_sum);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/
