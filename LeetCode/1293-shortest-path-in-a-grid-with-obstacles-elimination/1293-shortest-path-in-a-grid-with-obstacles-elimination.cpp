class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(); // 사각형의 세로, 행
        int n = grid[0].size(); // 사각형의 가로, 열
        vector<vector<int>> visited(m, vector<int>(n, -1)); // This vector stores the number of obstacles that we can still remove after walking through that cell
        queue<vector<int>> q;
        
        q.push({0, 0, 0, k}); // x, y, currentLength, remaining k
        
        while (!q.empty())
        {    
            vector<int> t = q.front();
            q.pop();
            
            int x = t[0];
            int y = t[1];
            
            if (x < 0 || x >= m || y < 0 || y >= n) { // Invalid cases being dealt here since it's easier to write one condition instead of 4 while pushing.
                continue;
            }
            if (x == m - 1 && y == n - 1) {// If you've reached the end, great, return the currentLength!
                return t[2]; //currentLength of the path
            }
            if (grid[x][y] == 1) { // If we hit an obstacle & we don't have any Ks remaining, continue
                if (t[3] > 0) {
                    t[3]--; // If we still have Ks to spend, we spend 1.
                }
                else {
                    continue;
                }
            }
            
            // If this cell is already visited with a K value lesser than this one, we would want to save Ks for future use, so we continue
            // This is the most important condition and part of the solution!
            if (visited[x][y] != -1 && visited[x][y] >= t[3]) {
                continue;
            }
            
            // We store the currentRemaining K after spending K (if required) into the visited matrix.
            visited[x][y] = t[3];
                
            // Push the adjacent nodes in the queue.
            q.push({x + 1, y, t[2] + 1, t[3]});
            q.push({x - 1, y, t[2] + 1, t[3]});
            q.push({x, y + 1, t[2] + 1, t[3]});
            q.push({x, y - 1, t[2] + 1, t[3]});
        }
        
        return -1;
    }
};