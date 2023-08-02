class Solution 
{   
public:
    int getFood(vector<vector<char>>& grid) 
    {

        const size_t ROW = grid.size();
        const size_t COL = grid[0].size(); 
        queue<pair<int, int>> search_queue; 
        int step_length = 0;
        
        if (ROW == 0 || COL == 0) {
            return -1;
        }
        
        // 모든 푸드셀을 위치를 먼저 찾는다.
        for (size_t i = 0; i < ROW; i++) {
            for (size_t j = 0; j < COL; j++) {
                if (grid[i][j] == FOOD_CELL) {
                    search_queue.push({i, j});
                }
            }
        }
        
        // bfs를 통해 푸르셀로 출발해 시작위치를 찾는다.
        while (!search_queue.empty()) {
            size_t queue_size = search_queue.size(); 
            step_length++;
            
            for (size_t i = 0; i < queue_size; i++) {
                auto [x, y] = search_queue.front(); search_queue.pop();
                
                for (size_t j = 0; j < directions.size(); j++) {
                    int X = x + directions[j][0];
                    int Y = y + directions[j][1];
                    
                    if (0 <= X && X < ROW && 0 <= Y && Y < COL) {
                        if (grid[X][Y] == START_LOCATION) {
                            return step_length;
                        }
                        else if (grid[X][Y] == FREE_SPACE) {
                            grid[X][Y] = VISITED; // 방문표시
                            search_queue.push({X, Y});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
    
private:
    enum
    {
        START_LOCATION = '*',
        FOOD_CELL = '#',
        FREE_SPACE = 'O',
        OBSTACLE = 'X',
        VISITED = 'V',
        MAX = 5
    };
    
    vector<vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; // 동서남북 탐방
};