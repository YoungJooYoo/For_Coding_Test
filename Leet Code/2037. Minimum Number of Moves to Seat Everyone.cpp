class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        const size_t ARRAY_LENGTH = seats.size();
        int res = 0;

        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        for (int i = 0; i < ARRAY_LENGTH; ++i) {
            res += abs(seats[i] - students[i]);
        }
        
        return res;
    }
};

// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/

/*

방 안에는 n개의 자리와 n명의 학생이 있습니다. 길이가 n인 배열 seats가 주어지며, seats[i]는 i번째 자리의 위치입니다. 또한 길이가 n인 배열 students가 주어지며, students[j]는 j번째 학생의 위치입니다.

다음과 같은 이동을 여러 번 수행할 수 있습니다:

i번째 학생의 위치를 1 증가시키거나 (즉, i번째 학생을 위치 x에서 x + 1로 이동) 또는
i번째 학생의 위치를 1 감소시킵니다 (즉, i번째 학생을 위치 x에서 x - 1로 이동)
각 학생을 자리에 앉히기 위해 필요한 최소한의 이동 횟수를 반환합니다. 단, 동일한 자리에 두 명 이상의 학생이 앉지 않도록 합니다. 처음에는 동일한 위치에 여러 자리나 학생이 있을 수 있습니다.


*/
