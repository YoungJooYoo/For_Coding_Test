class Solution {
public:
    int maxCount(const int m, const int n, vector<vector<int>>& ops) 
    {
        const size_t LEN = ops.size();
        int min_row = m;
        int min_col = n;

        for (size_t i = 0; i < LEN; i++) {
            min_row = min(min_row, ops[i][0]);
            min_col = min(min_col, ops[i][1]);
        }

        return min_row * min_col;
    }
};
// https://leetcode.com/problems/range-addition-ii/description/
