class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int x) 
    {
        int n = grid.size();
        int m = grid[0].size();     
        
        for (int k = 0; k < x; k++) {
            int temp;
            for (int i = n - 1; i >= 0; i--) { // 배열을 뒤에서 부터 읽는다.
                for (int j = m - 1; j >= 0; j--) {
                    if (i == n - 1 && j == m - 1) { // 배열을 읽는 첫 시작(끝의 값) 경우
                        temp = grid[i][j];
                    }
                    else if (j == m - 1) {
                        grid[i + 1][0] = grid[i][j];
                    }
                    else {
                        grid[i][j + 1] = grid[i][j];
                    }
                }
            }
            grid[0][0] = temp;
        }

        return grid;
    }
};
