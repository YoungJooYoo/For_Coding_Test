class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        const int ROW = mat.size();
        const int COL = mat[0].size();
        vector<vector<int>> directions{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        queue<pair<int, int>> job_queue;
        
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (mat[i][j] == 0) {
                    job_queue.push({i, j});
                }
                else {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        
        while (!job_queue.empty()) {
            auto curr_location = job_queue.front(); job_queue.pop();
            
            for (const auto& direction : directions) {
                int m = curr_location.first;
                int n = curr_location.second;
                int x = m + direction[0];
                int y = n + direction[1];
                // If it steps out of the matrix, or the adjacent cell already records a smaller distance (for instance, the adjacent cell is also 0). 
                if (x < 0 || x >= ROW || y < 0 || y >= COL || mat[x][y] <= mat[m][n] + 1) {
                    continue;
                }
                mat[x][y] = mat[m][n] + 1; // Adds one distance to the adjacent cell.
                job_queue.push({x, y});
            }
        }
        
        return mat;
    }
};