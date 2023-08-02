class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int UD = 0;
        int LR = 0;

        for (const auto& move : moves) {
            switch (move) {
                case 'U':
                    ++UD;
                    break;
                case 'D':
                    --UD;
                    break;
                case 'L':
                    ++LR;
                    break;
                case 'R':
                    --LR;
                    break;
                default:
                    assert(false);
            }
        }

        return (UD | LR) == 0; // 둘다 0이 나올때면 최종적으로 원점인 0이 나오는 비트마스킹 or연산
    }
};

// https://leetcode.com/problems/robot-return-to-origin/description/
