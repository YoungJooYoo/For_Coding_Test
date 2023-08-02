class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        map<int,int> store;
        
        for(size_t i = 0; i < intervals.size(); i++) {
            store[intervals[i][0]]++; // whenever a meeting starts, a room is occupied, 방이 찰때 체크
            store[intervals[i][1]]--; // whenever a meeting ends, a room is freed, 방이 빌때 체크
        }
        
        int min_rooms = 0, curr_rooms = 0;
        
        for(auto itr = store.begin(); itr != store.end(); itr++) { // iterate the map in increasing order of time
            curr_rooms += itr->second; // update the current room count , 방이 빌때를 업데이트한다 비었는지 아닌지
            min_rooms = max(min_rooms, curr_rooms); // minimum room required is the count when curr_rooms is maximum, 빈방이 아닌 경우를 체크하는 것
        }
        
        return min_rooms;
    }
};