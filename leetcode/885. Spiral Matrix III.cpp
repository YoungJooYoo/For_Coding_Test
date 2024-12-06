class Solution 
{
public:
    vector<vector<int>> spiralMatrixIII(const int rows, const int cols, const int rStart, const int cStart) 
    {
        vector<vector<int>> outMatrix;
        const int totalCells = rows * cols;
        int currentRow = rStart;
        int currentCol = cStart;
        int step = 0; // 현재 이동하는 스텝의 길이

        outMatrix.push_back({currentRow, currentCol});
        
        while (outMatrix.size() < totalCells) 
        {
           
            ++step;  // Step 수 증가 후, 네 방향으로 이동

            for (int i = 0; i < step; ++i)  // 오른쪽으로 이동
            {
                ++currentCol;
                if (isValidCell(currentRow, currentCol, rows, cols)) 
                {
                    outMatrix.push_back({currentRow, currentCol});
                }
            }

            // 아래로 이동
            for (int i = 0; i < step; ++i) 
            {
                ++currentRow;
                if (isValidCell(currentRow, currentCol, rows, cols)) 
                {
                    outMatrix.push_back({currentRow, currentCol});
                }
            }

            // 다음으로는 step 수를 증가시킨 후, 왼쪽으로 이동
            ++step;

            // 왼쪽으로 이동
            for (int i = 0; i < step; ++i) 
            {
                --currentCol;
                if (isValidCell(currentRow, currentCol, rows, cols)) 
                {
                    outMatrix.push_back({currentRow, currentCol});
                }
            }

            // 위로 이동
            for (int i = 0; i < step; ++i) 
            {
                --currentRow;
                if (isValidCell(currentRow, currentCol, rows, cols)) 
                {
                    outMatrix.push_back({currentRow, currentCol});
                }
            }
        }

        return outMatrix;
    }

private:
    // 유효한 좌표인지 확인하는 함수
    bool isValidCell(const int row, const int col, const int rows, const int cols) const 
    {
        return (row >= 0 && row < rows && col >= 0 && col < cols) ? true : false;
    }
};

// https://leetcode.com/problems/spiral-matrix-iii/description/
