class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        unordered_map<int, int> freq;
        const size_t ROW = matrix.size();
        const size_t COL = matrix[0].size();

        // 행의 최소값
        for (const auto& elem : matrix) {
            freq[*min_element(elem.begin(), elem.end())]++;
        }

        // 열의 최대값
        for (size_t i = 0; i < COL; ++i) {
            int max_val = INT_MIN;
            for (size_t j = 0; j < ROW; ++j) {
                max_val = max(max_val, matrix[j][i]);
            }
            freq[max_val]++;
        }

        for (const auto& elem : freq) {
            if (elem.second == 2) return {elem.first};
        }


        return {};
    }
};

// https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
