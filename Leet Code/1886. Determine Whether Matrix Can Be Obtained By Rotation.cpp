class Solution {
public:
    bool findRotation(const vector<vector<int>>& mat, const vector<vector<int>>& target) 
    {
        int count = 4;
        
        rotated_target = target;
        while (count-- > 0) {
            if (mat == rotated_target) {
                return true;
            }
            else {
                rotated_target = get_rotated_target(rotated_target);
            }
        }

        return false;
    }

private: 
    vector<vector<int>> rotated_target;

    vector<vector<int>> get_rotated_target(const vector<vector<int>>& target)
    {
        assert(target.size() != 0 || target[0].size() != 0);
        
        const size_t ROW = target.size();
        const size_t COL = target[0].size();
        vector<vector<int>> result(ROW, vector<int>(COL));

        for (size_t i = 0; i < ROW; ++i) {
            for (size_t j = 0; j < COL; ++j) {
                result[i][j] = target[COL - j -1][i];
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/
