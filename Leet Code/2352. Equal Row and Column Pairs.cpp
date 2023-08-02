class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        const size_t m = grid.size();
        const size_t n = grid[0].size();
        int count = 0;

        // 세로 행 미리 구해두기
        unordered_map<int, vector<int>> freq;
        for (size_t j = 0; j < n; ++j) {
            vector<int> temp;
            for (size_t i = 0; i < m; ++i) {
                temp.push_back(grid[i][j]);
            }
            freq[j] = temp;
        }

        // 구해둔 세로행과 가로행 비교하기
        for (size_t i = 0; i < m; ++i) { 
            vector<int> temp;
            for (size_t j = 0; j < n; ++j) { //행 구하기
                temp.push_back(grid[i][j]);
            }
            for (const auto& elem : freq) { // 행과 열 비교하기
                if (elem.second == temp) ++count;
            }
         }
        
        return count;
    }   
};

// https://leetcode.com/problems/equal-row-and-column-pairs/description/
