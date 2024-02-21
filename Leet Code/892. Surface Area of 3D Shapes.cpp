class Solution {
public:
    int surfaceArea(const vector<vector<int>>& grid) {
        const int n = grid.size();
        int area = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    // 각 타워의 기본 표면적 추가
                    area += grid[i][j] * 4 + 2;
                    // 상하좌우 인접 타워와의 겹치는 면적 처리
                    if (i > 0) area -= min(grid[i][j], grid[i - 1][j]) * 2;
                    if (j > 0) area -= min(grid[i][j], grid[i][j - 1]) * 2;
                }
            }
        }
        
        return area;
    }
};

// https://leetcode.com/problems/surface-area-of-3d-shapes/
