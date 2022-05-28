class Solution {
public:
    int racecar (int target) 
    {
        queue<vector<int>> todo;
        todo.push({0, 1, 0}); // {pos, speed, steps}
        
        while (!todo.empty()) {
            vector<int> cur = todo.front(); todo.pop();
            int pos = cur[0];
            int speed = cur[1];
            int steps = cur[2];
            
            if (pos == target) { // 타겟을 찾은 경우
                return steps;
            }
            if ((pos + speed <= 10000 && pos + speed > 0)) { // 가속
                todo.push({pos + speed, speed * 2, steps + 1});
            }
            if (speed > 0 && (pos + speed > target)) { // 방향 리버스
                todo.push({pos, -1, steps + 1});
            }
            if (speed < 0 && (pos + speed < target)) {
                todo.push({pos, 1, steps + 1});
            }
        }
        
        return 0;
    }
};