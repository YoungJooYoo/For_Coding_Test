class Solution 
{
public:
    bool isPathCrossing(const string& path) 
    {
        // 현재 위치를 추적하기 위한 (x, y) 좌표
        int x = 0;
        int y = 0;

        // 방문한 위치를 저장하기 위한 set
        unordered_set<string> visited;
        
        // 초기 위치를 저장
        visited.insert("0,0");

        for (char direction : path) 
        {
            if (direction == 'N') 
            {
                ++y;
            } 
            else if (direction == 'S') 
            {
                --y;
            } 
            else if (direction == 'E') 
            {
                ++x;
            } 
            else if (direction == 'W') 
            {
                --x;
            }
            
            // 현재 위치를 문자열로 변환하여 저장
            const string currentPosition = to_string(x) + "," + to_string(y);
            
            // 이미 방문한 위치인지 확인
            if (visited.find(currentPosition) != visited.end()) 
            {
                return true; // 경로가 교차함
            }
            
            // 현재 위치를 set에 저장
            visited.insert(currentPosition);
        }
        
        return false; // 경로가 교차하지 않음
    }
};

// https://leetcode.com/problems/path-crossing/description/
