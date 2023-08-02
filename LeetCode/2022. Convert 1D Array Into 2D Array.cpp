class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        const size_t SIZE = original.size();
        vector<vector<int>> result;

        if (SIZE != m * n) {
            return result;
        }

        size_t idx = 0;
        for (size_t i = 0; i < m; ++i) {
            vector<int> temp;
            for (size_t j = 0; j < n; ++j) {
                temp.push_back(original[idx++]);
            }
            result.push_back(temp);
        }

        return result;
    }
};

// https://leetcode.com/problems/convert-1d-array-into-2d-array/description/
