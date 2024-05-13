#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        const int n = grid.size();
        const int m = grid[0].size();

        // 첫 번째 열을 모두 1로 토글
        for (size_t i = 0; i < n; ++i) 
        {
            if (grid[i][0] == 0) 
            {
                toggleRow(grid, i);
            }
        }

        int ans = 0;
        int k = 1;
        
        // 각 열을 탐색하면서 점수 계산
        for (int i = m - 1; i >= 0; --i) {
            int numZeros = 0;
            // 현재 열에서 0의 개수 계산
            for (int j = 0; j < n; ++j) 
            {
                if (grid[j][i] == 0) 
                {
                    numZeros++;
                }
            }
            // 0의 개수와 1의 개수 중 더 큰 값을 선택하여 점수에 추가
            ans += max(numZeros, n - numZeros) * k;
            k *= 2;
        }
        return ans;
    }
    
private:
    // 특정 행의 모든 요소를 토글하는 함수
    void toggleRow(vector<vector<int>>& grid, int row) 
    {
        const int m = grid[row].size();

        for (size_t j = 0; j < m; ++j) 
        {
            grid[row][j] = !grid[row][j];
        }
    }
};

// https://leetcode.com/problems/score-after-flipping-matrix/?envType=daily-question&envId=2024-05-13
