class Solution {
private:
    int max_count = 0;
    int count = 0;
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return; // 배열의 범위를 넘어가면 종료
        }
        
        count++;
        grid[i][j] = 0; // 방문표시 의미로 0으로 바꿈 (재방문 안되게)
        
        // 동서남북으로 방문
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    count = 0;
                    dfs(grid, i, j);
                }
                max_count = max(max_count, count);
            }
        }
        
        return max_count;
    }
};