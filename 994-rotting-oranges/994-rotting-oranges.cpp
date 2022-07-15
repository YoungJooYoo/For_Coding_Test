class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        const int ROW = grid.size();
        const int COL = grid[0].size();
        int time_stamp = ROTTEN_ORANGE; // 상한오렌지로 바꾸며, 몇번만에 바꾸었는지 카운트 하는 변수
        
        while (runRottingProcess(time_stamp, grid, ROW, COL) == true) {
            time_stamp++;
        }
        
        // 멀쩡한 오렌지 있는지 감별
        for (const auto& elem : grid) {
            for (const auto& orange : elem){
                if (orange == ORANGE) {
                    return -1;    
                }
            }
        }
        
        return time_stamp - 2; // 처음 +2로 시작한 것 뺴고, count 된 값만 반환
    }  
    
    bool runRottingProcess(int time_stamp, vector<vector<int>>& grid, const int ROW, const int COL) 
    {
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 동서남북 방향
        bool is_continued = false;
        
        for (int row = 0; row < ROW; ++row) {
            for (int col = 0; col < COL; ++col) {
                if (grid[row][col] == time_stamp) {
                    for (const auto direction : directions)  {
                        int nRow = row + direction[0]; // 동서 남북을 움직인다.
                        int nCol = col + direction[1];
                        if (nRow >= 0 && nRow < ROW && nCol >= 0 && nCol < COL)  { // 배열의 범위를 벗어나지 않는 범위에서 탐색
                            if (grid[nRow][nCol] == ORANGE)  { // 오랜지라면, 상한 오렌지로 바꾼다.
                                grid[nRow][nCol] = time_stamp + 1; // 시간에 지남에 따라 트리 탐색처럼 단계가 + 1 된다,

                                is_continued = true;
                            }
                        }
                    }
                }
            }
        }

        return is_continued;
    }
    
private:
    const int ORANGE = 1;
    const int ROTTEN_ORANGE = 2;
};




