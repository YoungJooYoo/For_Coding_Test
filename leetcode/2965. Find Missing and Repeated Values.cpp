class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        unordered_map<int, int> freq;
        vector<int> result(2, 0);

        // 빈도수 찾기
        for (const auto& row : grid) {
            for (const auto& elem : row) {
                ++freq[elem];
            }
        }

        // 누락된 숫자 찾기, 중복숫자 찾기
        const size_t ROW = grid.size();
        const size_t COL = grid[0].size();
        for (size_t i = 1; i <= ROW * COL; ++i) {
            if (freq.find(i) == freq.end()) result[1] = i;
            else if (freq[i] > 1) result[0] = i;
        }

        return result;
    }
};

// https://leetcode.com/problems/find-missing-and-repeated-values/description/
