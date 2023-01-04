class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) 
    {
        set<int> nums;
        int ans = 0;

        // 행마다 정렬 후, 열중의 최대 값만 모아서 계산하기
        for (auto& row : grid) {
            sort(row.begin(), row.end());
        }    

        for (size_t j = 0; j < grid[0].size(); ++j) {
            int max = -1;
            for (size_t i = 0; i < grid.size(); ++i) {
                if (max < grid[i][j]) max = grid[i][j];
            }
            ans += max;
        }

        return ans;
    }
};

// https://leetcode.com/problems/delete-greatest-value-in-each-row/description/
