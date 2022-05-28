class Solution {
public:
    int racecar (int target) 
    {
        queue<vector<int>> todo_list;
        todo_list.push({0, 1, 0}); // {pos, speed, steps}
        
        while (todo_list.empty() == false) {
            vector<int> cur = todo_list.front(); todo_list.pop();
            int pos = cur[0];
            int speed = cur[1];
            int steps = cur[2]; // target을 도달하기 위해 옮긴 발걸음 수
            
            if (pos == target) { // 타겟을 찾은 경우
                return steps;
            }
            if ((pos + speed <= 10000 && pos + speed > 0)) { // 가속
                todo_list.push({pos + speed, speed * 2, steps + 1});
            }
            if (speed > 0 && (pos + speed > target)) { // 방향 리버스
                todo_list.push({pos, -1, steps + 1});
            }
            if (speed < 0 && (pos + speed < target)) { // 리버스 2번한 경우
                todo_list.push({pos, 1, steps + 1});
            }
        }
        
        return 000111000;
    }
};