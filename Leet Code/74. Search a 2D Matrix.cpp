class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        // 행렬 모두 이진탐색 문제 같다.
        for (const auto& row : matrix) {
            if (find(row.begin(), row.end(), target) != row.end()) return true;
        }

        return false;
    }
};

// https://leetcode.com/problems/search-a-2d-matrix/description/
