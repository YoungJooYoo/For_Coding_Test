class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end()); // intervals[i][0]의 크기 순으로 정렬
        
        for(size_t i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] < intervals[i - 1][1]) { // 앞뒤 원소끼리 비교
                return false;
            }
        }
        
        return true;
    }
};