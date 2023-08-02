class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) 
    {
        const size_t m = grid.size();
        const size_t n = grid[0].size();
        vector<int> result;

        for (size_t j = 0; j < n; ++j) {
            int max_length = INT_MIN;
            for (size_t i = 0; i < m; ++i) {
                int length = 0;
                int temp = grid[i][j];

                if (temp < 0) { // 음수의 경우 길이 +1
                    ++length;
                    temp *= -1; // 양수로 변경
                } 
                else if (temp == 0) {
                    ++length;
                }
                while (temp != 0) { // grid[i][j] 길이체크
                    temp /= 10;
                    ++length;
                }
                max_length = max(max_length, length); // max_length랑 비교
            }
            result.push_back(max_length);
        }

        return result;
    }
};

// https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/description/
