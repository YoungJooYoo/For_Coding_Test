class Solution {
public:
    bool checkStraightLine(const vector<vector<int>>& coordinates) 
    {
        const int size = coordinates.size();

        const int x1 = coordinates[0][0];
        const int y1 = coordinates[0][1];
        const int x2 = coordinates[size - 1][0];
        const int y2 = coordinates[size - 1][1];

        const int dx = x2 - x1; // 전체 x축길이
        const int dy = y2 - y1; // 전체 y 축 길이

        for (int i = 0;i  < size; ++i) {
            const int ddx = coordinates[i][0] - coordinates[0][0];
            const int ddy = coordinates[i][1] - coordinates[0][1];
            if (ddx * dy != ddy * dx) return false;
        }

        return true;
    }
};

// https://leetcode.com/problems/check-if-it-is-a-straight-line/description/
