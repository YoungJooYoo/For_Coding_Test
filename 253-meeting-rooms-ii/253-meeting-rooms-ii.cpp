class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        map<int,int> store;
        
        for(size_t i = 0; i < intervals.size(); i++) {
            store[intervals[i][0]]++; // whenever a meeting starts, a room is occupied
            store[intervals[i][1]]--; // whenever a meeting ends, a room is freed
        }
        
        int min_rooms = 0, curr_rooms = 0;
        
        for(auto itr = store.begin(); itr != store.end(); itr++) { // iterate the map in increasing order of time
            curr_rooms += itr->second; // update the current room count
            min_rooms = max(min_rooms, curr_rooms); // minimum room required is the count when curr_rooms is maximum
        }
        
        return min_rooms;
    }
};