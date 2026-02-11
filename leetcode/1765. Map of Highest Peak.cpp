class Solution 
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& map) const
    {
        assert(MIN_LENGTH <= map.size() && map.size() <= MAX_LENGTH);
        assert(MIN_LENGTH <= map[0].size() && map[0].size() <= MAX_LENGTH);

        const int ROW_COUNT = map.size();
        const int COL_COUNT = map[0].size();
        vector<vector<int>> heightMap(ROW_COUNT, vector<int>(COL_COUNT, NON_VISITED));
        queue<pair<int, int>> bfsQueue;

        // 모든 물 셀을 BFS 시작점으로 초기화
        for (int row = 0; row < ROW_COUNT; ++row)
        {
            for (int col = 0; col < COL_COUNT; ++col)
            {
                assert(map[row][col] == LAND || map[row][col] == WATER);
                if (map[row][col] == WATER)
                {
                    heightMap[row][col] = BASE_HEIGHT;
                    bfsQueue.push({row, col});
                }
            }
        }

        while (!bfsQueue.empty()) // Multi-source BFS
        {
            const int currentRow = bfsQueue.front().first;
            const int currentCol = bfsQueue.front().second;
            bfsQueue.pop();
            for (const auto& dir : DIRECTIONS)
            {
                const int nextRow = currentRow + dir.first;
                const int nextCol = currentCol + dir.second;
                if ((isInBounds(nextRow, nextCol, ROW_COUNT, COL_COUNT) == true) && (heightMap[nextRow][nextCol] == NON_VISITED))
                {
                    heightMap[nextRow][nextCol] = heightMap[currentRow][currentCol] + 1;
                    bfsQueue.push({nextRow, nextCol});
                }
            }
        }

        return heightMap;
    }

private:
    static bool isInBounds(int row, int col, int maxRow, int maxCol)
    {
        return (row >= 0 && row < maxRow && col >= 0 && col < maxCol) ? true : false;
    }

private:
    constexpr static pair<int, int> DIRECTIONS[4] =
    {
        { 0,  1 }, // EAST
        { 1,  0 }, // SOUTH
        { -1, 0 }, // NORTH
        { 0, -1 }  // WEST
    };

    enum
    {
        NON_VISITED = -1,
        BASE_HEIGHT = 0,
        LAND = 0,
        WATER = 1,
        MIN_LENGTH = 1,
        MAX_LENGTH = 1000
    };
};

// https://leetcode.com/problems/map-of-highest-peak/description/
