class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) 
    {
        const size_t ROW = mat.size(); // 행의 개수
        const size_t COL = mat[0].size(); // 열의 개수
        int maxOnes = 0; // 최대 1의 개수
        int rowIndex = 0; // 가장 많은 1을 가진 행의 인덱스

        // 각 행을 순회하면서 1의 개수를 세고, 최대 1의 개수를 업데이트합니다.
        for (size_t i = 0; i < ROW; i++) {
            int onesInRow = 0; // 현재 행의 1의 개수
            for (int j = 0; j < COL; j++) {
                if (mat[i][j] == 1) {
                    onesInRow++;
                }
            }
            // 현재 행의 1의 개수가 최대 1의 개수보다 많으면 업데이트합니다.
            if (onesInRow > maxOnes) {
                maxOnes = onesInRow;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};

// https://leetcode.com/problems/row-with-maximum-ones/description/
