class Solution {
public:
    vector<int> circularGameLosers(int n, int k) 
    {
        vector<int> losers(n, 0);
        int ballHolder = 0;  // 현재 볼을 가지고 있는 친구 (1번 친구부터 시작)

        losers[0] = 1; // 1번 플레이어가 항상 먼저 시작하므로
        for (int i = 1; i <= n; i++) {
            ballHolder = (ballHolder + (i * k)) % n;  // 볼을 넘겨줄 친구를 찾음
            ++losers[ballHolder];  // 볼을 받은 친구의 볼 받은 횟수 증가
            if (losers[ballHolder] == 2) {
                break;  // 두 번째로 볼을 받은 친구를 찾으면 게임 종료
            }
        }

        // 루저 찾는 로직
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (losers[i] == 0) {
                result.push_back(i + 1);  // 인덱스를 1부터 시작하는 번호로 변환
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/
