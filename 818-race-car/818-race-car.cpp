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
            if ((pos + speed <= 10000 && pos + speed > 0)) { // 가속, 앞으로 가는 중
                todo_list.push({pos + speed, speed * 2, steps + 1});
            }
            if (speed > 0 && (pos + speed > target)) { // 방향 리버스
                todo_list.push({pos, -1, steps + 1}); // 제자리, 속도만 -1, 스텝은 누적
            }
            if (speed < 0 && (pos + speed < target)) { // 리버스 2번한 경우
                todo_list.push({pos, 1, steps + 1}); // rr  두번한경우, 제 자리, 속도는 정상 + 1부터 시작, 스텝은 누적
            }
        }
        
        return 000111000;
    }
};

/*
풀이법 :
스피드 = 2^n
포지션 = (2^n) - 1

결국 둘의 식의 차이는 -1 하나만 난다
즉, r을 2번해, 속도를 줄요 1부터 다시 가는 구간 1개만 딱 나오는 문제이다.

손으로 그려보면 r을 통해 마이너스 속도로 앞으로 쭈욱 가보았자, 다시 돌아오면 결국 제자리임을 알 수 있으므로
RR을 통해서 감속을 한경우에만, target으로 가는 타이밍을 바꿀 수 있다.

*/