class Solution
{
public:
    bool canVisitAllRooms(const vector<vector<int>>& rooms) const
    {
        const size_t ROOM_COUNT = rooms.size();
        vector<bool> visitedRooms(ROOM_COUNT, false);

        assert(MIN_ROOM_COUNT <= ROOM_COUNT && ROOM_COUNT <= MAX_ROOM_COUNT);
        ExploreRoomsRecursive(rooms, 0, visitedRooms);

        for (size_t roomIndex = 0; roomIndex < ROOM_COUNT; ++roomIndex)
        {
            assert(visitedRooms.size() == ROOM_COUNT);
            if (visitedRooms[roomIndex] == false)
            {
                return false;
            }
        }

        return true;
    }

private:
    void ExploreRoomsRecursive(const vector<vector<int>>& rooms, const int room, vector<bool>& visitedRooms) const
    {
        assert(0 <= room && static_cast<size_t>(room) < rooms.size());
        visitedRooms[room] = true;

        for (const int key : rooms[room])
        {
            assert(MIN_ROOM_INDEX <= key && key < static_cast<int>(rooms.size()));
            if (visitedRooms[key] == false)
            {
                ExploreRoomsRecursive(rooms, key, visitedRooms);
            }
        }
    }

    enum
    {
        MIN_ROOM_COUNT = 2,
        MAX_ROOM_COUNT = 1000,
        MIN_ROOM_INDEX = 0,
        // MAX_ROOM_INDEX는 동적으로 rooms.size() - 1
        MIN_KEYS_TOTAL = 1,
        MAX_KEYS_TOTAL = 3000
    };
};


// https://leetcode.com/problems/keys-and-rooms/description/

/*
841. 열쇠와 방 (Keys and Rooms)
문제 설명
0번부터 n-1번까지 번호가 매겨진 n개의 방이 있습니다.
처음에는 모든 방이 잠겨 있지만 0번 방만 열려 있습니다.
당신의 목표는 모든 방을 방문하는 것입니다.
하지만 해당 방의 열쇠가 없으면 그 방에 들어갈 수 없습니다.

어떤 방을 방문하면, 그 방 안에는 서로 다른 방을 열 수 있는 열쇠 세트가 들어 있을 수 있습니다.
각 열쇠에는 열 수 있는 방의 번호가 적혀 있으며,
그 방의 열쇠를 모두 챙겨서 다른 방을 열 수 있습니다.

정수 배열 rooms가 주어집니다.
rooms[i]는 i번 방을 방문했을 때 얻을 수 있는 열쇠들의 목록입니다.

모든 방을 방문할 수 있으면 true, 아니면 false를 반환하세요.

예시
예시 1
입력: rooms = [[1],[2],[3],[]]

출력: true

설명:

0번 방을 방문해 1번 열쇠를 얻음

1번 방을 방문해 2번 열쇠를 얻음

2번 방을 방문해 3번 열쇠를 얻음

3번 방을 방문

모든 방을 방문할 수 있으므로 true

예시 2
입력: rooms = [[1,3],[3,0,1],[2],[0]]

출력: false

설명:

2번 방에 들어갈 수 있는 열쇠는 2번 방 안에만 있어서

2번 방을 영원히 방문할 수 없다

모든 방을 방문할 수 없으므로 false

제약 사항
n == rooms.length

2 <= n <= 1000

0 <= rooms[i].length <= 1000

1 <= rooms[i] 전체 길이의 합 <= 3000

0 <= rooms[i][j] < n

rooms[i]의 값들은 모두 서로 다름 (중복 없음)

더 궁금한 점, 코드 풀이, 아이디어가 필요하시면 언제든 말씀해 주세요!
*/
