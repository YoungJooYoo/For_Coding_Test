class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();    // m is column
        int n = m ? grid[0].size() : 0; // n is row,  m의 값이 존재하면 row를 넣고 존재하지 않으면 0 대입;        
        int islands_count = 0;
        
        // grid를 한칸씩 옮겨가면서 island를 탐색시작
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands_count++; // island를 찾으면 카운트
                    erase_islands(grid, i, j); // 찾은 island를 전부 0으로 만들어 지우고, 새로운 island를 찾아간다.
                }
            }
        }
        
        return islands_count;
    }
    
    void erase_islands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') { // grid의 범위를 넘어가거나, 물이 발견되면 pass
            return;
        }
        grid[i][j] = '0';
        erase_islands(grid, i + 1, j); // 탐색 지점으로 부터 동서남북 전부 탐색 DFS로
        erase_islands(grid, i - 1, j);
        erase_islands(grid, i, j + 1);
        erase_islands(grid, i, j - 1);
    }
};


/* 
BFS(반복문+큐)는 코드가 길어서, 짧은 DFS(재귀)로 풀이

풀이법 : 섬의 갯수는 서로 분리된 각각의 섬의 갯수를 의미한다.
따라서, 1을 발견하면 인접한 1을 전부 0으로 만들면서
섬의 갯수를 카운팅한다.  그러다 다른 섬을 찾으면 다시 섬을 카운팅하고
다시 지우는 것을 반복하면서 섬의 갯수를 찾는다.
*/